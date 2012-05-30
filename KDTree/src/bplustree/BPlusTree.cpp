#include "BPlusTree.h"
#include "strategies/UnderflorRootStrategy.h"
#include "exceptions/OverflowException.h"
#include "../utils/StringUtils.h"
#include "exceptions/ProgramException.h"

BPlusTree::BPlusTree(int blockSize, string fileName) {

	PersistorBTree* p = PersistorBTree::getInstance();
	p->init(fileName, blockSize);

	this->root = p->getRoot();
	this->current = NULL;//this->getLeftLeafNodo(root);
}

BPlusTree::BPlusTree() {
	PersistorBTree* p = PersistorBTree::getInstance();

	this->root = p->getRoot();
	this->current = NULL;// this->getLeftLeafNodo(root);
}
BPlusTree::~BPlusTree() {

	if (this->current == this->root) {
		if (this->root != NULL) {
			delete this->root;
			this->root = NULL;
		}
	} else {

		if (this->root != NULL) {
			delete this->root;
			this->root = NULL;
		}

		if (this->current != NULL) {
			delete this->current;
			this->current = NULL;
		}
	}
}

void BPlusTree::insert(IElement* element) {
	this->insert(element, INSERT);
}

LeafNode* BPlusTree::getLeftLeafNodo(BNode* actualNode) {

	LeafNode* firstLeftNode = NULL;

	if (actualNode->getLevel() > 0) {
		Node *internalNode = (Node*) actualNode;
		BNode *leftNode = NodeFactory::createNodeForSearch(
				actualNode->getLevel());
		PersistorBTree::getInstance()->load(
				internalNode->getLeftNode(), leftNode);

		firstLeftNode = this->getLeftLeafNodo(leftNode);

		//TODO VER SI ESTA LINA HAY QUE DECOMENTARLA
		//la movi abajo que es donde va.
		if (internalNode->getOffset() != 0) { ///no borramos al root. Hack sucio.
			delete internalNode;
		}
		return firstLeftNode;
	}

	return (LeafNode*) actualNode;
}

/**
 * Modifcar implica, encontrar el elemento en la hoja. Una vez encontrado hay que modificar el LeafElement para luego ver si cabe en la hoja.
 * Cabe en la hoja si la hoja no esta llena, sin considerar el factor de carga. Si no cabe, hay que dividir la hoja y subir la clave de
 * la derecha.
 *
 */
void BPlusTree::modify(IElement* element) {
	this->insert(element, MODIFY);
}

/**
 * Eliminar una clave implica tambien una posible contraccion del arbol.
 */
void BPlusTree::remove(IEntidad* key) {
	bool hasChanged = this->root->remove(key);

	if (hasChanged) {
		UnderflorRootStrategy underflowRootStrategy;

		this->root = underflowRootStrategy.doBalance(this->root);
	}
}

/**
 * La busqueda es aproximada, es decir, devuelve el elemento si lo encuentra y sino, el primero anterior mas cercano
 */
std::vector<BNode*> BPlusTree::find(IEntidad* key) {
	std::vector<BNode*> founds;

	root->findElements(key, founds);

	return founds;
}

IElement* BPlusTree::findExact(IEntidad* key) {
	return root->findExact(key);
}
/*LeafNode* BPlusTree::find(ID key){
 this->find(StringUtils::convertIntToString(key));
 }
 IElement* BPlusTree::findExact(ID key){
 this->findExact(StringUtils::convertIntToString(key));
 }*/

/**
 * Devuelve el siguiente nodo a partir del actual. Esto supone que se tenga un nodo hoja ya cargado. En caso de no tenerlo se comienza
 * a recorrer con el primero
 */
LeafNode* BPlusTree::next() {
	if (this->current == NULL) {
		current = this->getLeftLeafNodo(this->root);
		return current;
	}
	LeafNode* nextNode = NodeFactory::createLeafNode();
	if (current->getNextNode() == -1) {
		return NULL;
	}
	PersistorBTree::getInstance()->load(current->getNextNode(),
			nextNode);
	delete current;
	this->current = nextNode;

	return current;
}

LeafNode* BPlusTree::prev() {
	LeafNode* prevNode = NodeFactory::createLeafNode();
	PersistorBTree::getInstance()->load(current->getPrevNode(),
			prevNode);

	return prevNode;
}

/*void BPlusTree::remove(ID key)
 {
 this->remove(StringUtils::convertIntToString(key));
 }*/

void BPlusTree::deleteTree() {
	PersistorBTree::getInstance()->deleteFile();
}
void BPlusTree::exportTree(int blockNumber) {

	BNode* node = PersistorBTree::getInstance()->getNodeInBlock(blockNumber);

	node->exportNode();
	delete node;
}
void BPlusTree::exportTree() {
	this->root = PersistorBTree::getInstance()->getRoot();
	this->root->exportNode();
	cout << endl;
}
//*****************************************//
//********Impl. Interna********************//
//*****************************************//
void BPlusTree::insert(IElement* element, int modifyOrInsert) {
	this->validateElementSize(element);
	PersistorBTree* p = PersistorBTree::getInstance();
	KeyElement* keyOverflow = NULL;
	bool modified = false;

	switch (modifyOrInsert) {
	case INSERT:
		modified = this->root->insert(element);
		break;
	case MODIFY:
		modified = this->root->modify(element);
		break;
	}

	if (modified) {
		//como se modifico el nodo, puede que tenga que grabarlo
		//TODO pasarlo a una estrategia de balanceo de root;
		if (this->root->isOverflowded(modifyOrInsert)) {
			//como hubo overflow entonces, tengo que crear un nuevo root con esta clave
			Node* newRoot = NodeFactory::createKeyNode();
			newRoot->setLevel(this->root->getLevel() + 1);
			keyOverflow = this->root->doSplit();
			newRoot->setOffset(this->root->getOffset());
			p->add(this->root);
			newRoot->setLeftNode(this->root->getOffset());
			newRoot->appendKeyElementInOrder(keyOverflow);
			p->modify(newRoot);

			BNode* oldRoot = this->root;
			this->root = newRoot;
			delete oldRoot;
		} else {
			UnderflorRootStrategy underflowRootStrategy;
			this->root = underflowRootStrategy.doBalance(this->root);
		}
	}

}

void BPlusTree::validateElementSize(IElement* elm) {

	ConfigurationMananger* c = ConfigurationMananger::getInstance();
	unsigned int maxRecordSize =c->getMaxRecordSizeTree();

	if (elm->getDataSize() > maxRecordSize) {
		string mensaje;
		mensaje.append("BplussTree: tamano configurado invalido de registro ");
		mensaje.append(
				"los nodos son demasiado pequennos para soportar la estructura reconfigure el sistema");
		mensaje.append(" tamanno del elemento ").append(
				StringUtils::convertIntToString(elm->getDataSize())).append(
				"tamanno configurado ").append(StringUtils::convertIntToString(
						maxRecordSize));
		throw OverflowException(mensaje);
	}

}
