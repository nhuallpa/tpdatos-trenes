/*
 * LeafNode.cpp
 *
 */

#include "LeafNode.h"
#include <iostream>
#include "exceptions/OperationNotFoundException.h"
#include "../utils/StringUtils.h"
#include "../persistence/PersistorBTree.h"
#include "ElementFactory.h"
#include "../entidades/EntityFactory.h"

LeafNode::LeafNode() {
	nextNode = -1;
	prevNode = -1;
	freeSpace = 0;
	setLevel(0);
	itElementInitialized = false;
}

IElement* LeafNode::nextElement() {
	if (this->elements.begin() == this->elements.end()) {
		return NULL;
	}
	if (this->elements.end() == itElementActual) {
		return NULL;
	}
	if (this->itElementInitialized) {
		this->itElementActual = (this->elements.begin());
		this->itElementInitialized = true;
	} else {
		this->itElementActual++;

	}
	return (*itElementActual);
}

LeafNode::~LeafNode() {

	std::vector<IElement*>::iterator it;

	it = this->elements.begin();
	while (it != this->elements.end()) {
		delete (*it);
		this->elements.erase(it);
	}
}

Offset LeafNode::getPrevNode() {
	return prevNode;
}

Offset LeafNode::getNextNode() {
	return nextNode;
}

FreeSpace LeafNode::getFreeSpace() {
	return freeSpace;
}

IElement* LeafNode::getElement(IEntidad* key) {
	std::vector<IElement*>::iterator it;

	for (it = elements.begin(); it != elements.end(); it++) {
		IElement* el = (IElement*) *it;
		if (key->compareTo(el->getData()) == IGUAL)
			return el;
	}

	throw new ElementNotFoundException();
}

/**
 * Balancea con el sibling, devuelve true si cambiaron (ambos this y sibling)
 * false en caso contrario.
 * Pasa los primeros elementos de este nodo al final sibling (hermano)
 */
bool LeafNode::rightBalanceWith(BNode* leftSibling) {
	LeafNode* myLeftSibling = (LeafNode*) leftSibling;
	vector<IElement*>::iterator it = this->elements.begin();
	IElement* elem = (*it);

	int borrowRecordCount = 0;
	if (!this->isUnderflowded()) {
		while (leftSibling->isUnderflowded() && !this->isUnderflowded()) {
			borrowRecordCount++;
			this->elements.erase(it);
			myLeftSibling->insert(elem);
		}
		if (this->isUnderflowded()) {
			//no puedo balancear asi que le devuelvo los registros pedidos
			for (int i = borrowRecordCount; i > 0; i--) {
				it = myLeftSibling->elements.end();
				it--;
				elem = (*it);
				myLeftSibling->elements.erase(it);
				this->elements.push_back(elem);
			}
			return false;
		} else {
			return true;
		}
	}
	return false;
}
/**
 * Balancea con el sibling, devuelve true si cambiaron ambos (this y sibling) false caso contrario.
 * Pasa los ultimos elementos de este nodo al rightSibling
 */
bool LeafNode::leftBalanceWith(BNode* rightSibling) {
	LeafNode* myRightSibling = (LeafNode*) rightSibling;
	vector<IElement*>::iterator it = this->elements.end();
	IElement* elem = (*it);

	int borrowRecordCount = 0;
	if (!this->isUnderflowded()) {
		while (rightSibling->isUnderflowded() && !this->isUnderflowded()) {
			borrowRecordCount++;
			it--;
			elem = (*it);
			myRightSibling->elements.insert(myRightSibling->elements.begin(),
					elem);
			this->elements.erase(it);
			it = this->elements.end();
		}
		if (this->isUnderflowded()) { // si este quedo en underflow entonces no puedo balancear
			for (int i = borrowRecordCount; i > 0; i--) {
				it = myRightSibling->elements.begin();
				this->elements.push_back(*it);
				myRightSibling->elements.erase(it);
			}
			return false;
		} else {
			return true;
		}
	}
	return false;
}

/**
 * Toma los elementos de sibling y se los agrega a este nodo
 */
bool LeafNode::join(BNode* sibling) {
	LeafNode* mySibling = (LeafNode*) sibling;
	vector<IElement*>::iterator it;

	it = mySibling->elements.begin();
	while (it != mySibling->elements.end()) {
		this->elements.push_back((*it));
		mySibling->elements.erase(it);
		it = mySibling->elements.begin();
	}
	return true;
}

//NO USAR PARA BUSCAR EL HERMANO
IEntidad* LeafNode::getFirstKey() {
	//puede que este vacio entonces devuelveo
	if (this->elements.size() == 0) {
		throw ElementNotFoundException();
	}
	return (*(elements.begin()))->getData();
}
/**
 * Devuleve siempre true. Arroja una exception en caso de que ya exista
 */
bool LeafNode::insert(IElement* elemToInsert) {
	std::vector<IElement*>::iterator it;

	it = this->findElement(elemToInsert);
	//it = find (elements.begin(), elements.end(), elemToInsert);

	if (it != this->elements.end()) {
		throw ElementAlreadyExists();
	}

	//Insertamos en orden
	for (it = elements.begin(); it != elements.end(); it++) {
		IElement* el = (IElement*) *it;
		if (elemToInsert->getData()->compareTo(el->getData()) == MENOR) {
			elements.insert(it, elemToInsert);
			return true;
		}
	}
	//si llego aca es porque es mayor a todas la claves asi que la inserto al final

	elements.push_back(elemToInsert);
	return true;
}

LeafNode *LeafNode::find(IEntidad* key) {
	return this;
}

IElement *LeafNode::findExact(IEntidad* key) {
	std::vector<IElement*>::iterator it = getElementsBegin();

	while (it != getElementsEnds()) {
		if (key->compareTo((*it)->getData()) == IGUAL)
			return *it;
		it++;
	}

	throw new ElementNotFoundException();
}

/**
 * Tenemos que encontrar la elemento, sino esta, entonces hay que arrojar un error.
 */
std::vector<IElement*>::iterator LeafNode::findElement(IElement* elemToFind) {
	std::vector<IElement*>::iterator it;
	bool found = false;
	it = this->elements.begin();
	for (it = elements.begin(); it != elements.end() && !found;) {
		found = (*it)->getData()->compareTo(elemToFind->getData()) == IGUAL;
		if (!found) {
			it++;
		}
	}

	return it;
}

bool LeafNode::modify(IElement* elemToModify) {

	IElement* el;
	std::vector<IElement*>::iterator it = findElement(elemToModify);
	if (it == this->elements.end()) {
		throw new ElementNotFoundException();
	} else {
		el = (*it);
		this->elements.erase(it);
		this->elements.insert(it, elemToModify);
		delete el;
	}

	return true;
}

/**
 * Elimina el elemento cuya clave es key
 */
bool LeafNode::remove(IEntidad* key) {
	vector<IElement*>::iterator it = this->elements.begin();
	bool found = false;
	while (it != this->elements.end() && !found) {
		if (key->compareTo((*it)->getData()) == IGUAL) {
			delete *it;
			this->elements.erase(it);
			found = true;
		}
		it++;

	}

	if (!found) {
		throw new ElementNotFoundException();
	}
	return found;
}

/**
 * Metodo para test
 */
bool LeafNode::insertarTest(IElement* elem) {

	std::vector<IElement*>::iterator it;

	for (it = elements.begin(); it != elements.end(); it++) {
		IElement* el = (IElement*) *it;
		if (elem->getData()->compareTo(el->getData()) == MENOR) {
			elements.insert(it, elem);
			return true;
		}
	}

	elements.push_back(elem);
	return true;
}

/**
 * Divide la carga de bytes en dos nuevos Nodos
 */
KeyElement* LeafNode::doSplit() {
	KeyElement* keyElementFromMiddle = new KeyElement();

	LeafNode* newLeafNode = NodeFactory::createLeafNode();
	PersistorBTree* p = PersistorBTree::getInstance();
	newLeafNode->elements = this->splitElements();

	vector<IElement*>::iterator it;

	p->add(newLeafNode);
	keyElementFromMiddle->setRightNode(newLeafNode->getOffset());
	IElement* elemen = (IElement*) (*newLeafNode->elements.begin());
	keyElementFromMiddle->setKey(elemen->getData());
	newLeafNode->nextNode = this->nextNode;
	this->nextNode = newLeafNode->getOffset();

	return keyElementFromMiddle;
}

/**
 * Devuelve la mitad de la carga de este nodo.
 */
std::vector<IElement*> LeafNode::splitElements() {
	std::vector<IElement*> newElements;

	std::vector<IElement*>::iterator it = this->elements.end();
	it--;

	while (this->getDataElementsSize(this->elements)
			> this->getDataElementsSize(newElements)) {
		newElements.insert(newElements.begin(), (*it));
		this->elements.erase(it);
		it--;
	}

	return newElements;
}

bool LeafNode::isOverflowded(int modifyOrInsert) {
	bool isOverflow = false;
	switch (modifyOrInsert) {
	case INSERT:
		//Vemos que no supere el porcentaje de carga
		int dataSize;
		dataSize = this->getDataSize();
		int maxNodeLoad;
		maxNodeLoad = ConfigurationMananger::getInstance()->getMaxNodeLoadForInsert();
		isOverflow = dataSize > maxNodeLoad;
		break;
	case MODIFY:
		//si entra esta bien.
		dataSize = this->getDataSize();
		maxNodeLoad = ConfigurationMananger::getInstance()->getBufferSizeTree();
		isOverflow = dataSize > maxNodeLoad;
		break;
	default:
		throw OperationNotFoundException();
		break;
	}

	return isOverflow;
}

bool LeafNode::isUnderflowded() {
	ConfigurationMananger *cManager = ConfigurationMananger::getInstance();

	int minUnderflow = cManager->getMinUnderflowSizeTree();
	int dataSize = this->getDataSize();
	if (minUnderflow > dataSize)
		return true;
	else
		return false;
}

/******************************************************
 * 					PERSISTENCIA
 *
 ****************************************************/
RegisterCounter LeafNode::getRegisterCounter() {
	return this->elements.size();
}
std::vector<IElement*>::iterator LeafNode::getElementsBegin() {
	return elements.begin();
}

std::vector<IElement*>::iterator LeafNode::getElementsEnds() {
	return elements.end();
}
std::string LeafNode::serialize() {
	std::string buffer = BNode::serialize();

	buffer.append((char*) &prevNode, sizeof(Offset));
	buffer.append((char*) &nextNode, sizeof(Offset));

	std::vector<IElement*>::iterator it;

	for (it = elements.begin(); it != elements.end(); it++) {
		IElement* el = (IElement*) *it;
		buffer.append(el->serialize());
	}

	return buffer;
}

void LeafNode::unserialize(std::string &buffer) {
	BNode::unserialize(buffer);
	RegisterCounter registerCounter;

	buffer.copy((char*) &registerCounter, sizeof(RegisterCounter));
	buffer.erase(0, sizeof(RegisterCounter));

	buffer.copy((char*) &prevNode, sizeof(Offset));
	buffer.erase(0, sizeof(Offset));

	buffer.copy((char*) &nextNode, sizeof(Offset));
	buffer.erase(0, sizeof(Offset));

	for (RegisterCounter i = 0; i < registerCounter; i++) {
		IElement* el = ElementFactory::createElement();
		el->unserialize(buffer);
		buffer.erase(0, el->getDataSize());
		elements.push_back(el);
	}
}

/**
 * Devuelve el tamaño del vector
 */
int LeafNode::getDataElementsSize(std::vector<IElement*> vector) {

	int size = 0;
	std::vector<IElement*>::iterator it;

	for (it = vector.begin(); it != vector.end(); it++) {
		IElement* elem = (*it);
		size += elem->getDataSize();
	}
	return size;
}

DataSize LeafNode::getDataSize() {
	return (2 * sizeof(Offset) + sizeof(FreeSpace) + getDataElementsSize(
			elements) + BNode::getDataSize());
}
//El arbol maneja IElment, pero para mostrar necesito la entidad real
void LeafNode::exportNode() {

	std::vector<IElement*>::iterator it;
	cout << "Leaf Nodo: " << this->getOffset() << " cantidad Elementos "
			<< this->elements.size() << endl;
	for (it = this->elements.begin(); it != elements.end(); it++) {
		Element* elem = (Element*) (*it);
		//vale para todas menos para Element

		IEntidad* ientidad = elem->getData();

		//casteo para usar el operador que corresonde
		//esto quedo deprecado.El arobl solo sabe mostrar element.
		cout << ientidad->toString() << endl;
		delete ientidad;

	}
	cout << " siguiente: " << this->nextNode;
	cout << endl;

}
ostream& LeafNode::printMe(ostream& myOstream) {
	std::vector<IElement*>::iterator it;
	myOstream << "Nodo: " << getOffset() << " ";
	for (it = getElementsBegin(); it != getElementsEnds(); it++) {
		Element* elem = (Element*) (*it);
		IEntidad* ientidad = EntityFactory::createEntity(elem->getData());
		//casteo para usar el operador que corresonde

		myOstream << *elem << " ";
		delete ientidad;
	}
	myOstream << endl;
	return myOstream;

}

//**********************************//
//*****functor para la busqueda*****//
//**********************************//


