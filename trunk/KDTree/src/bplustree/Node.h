/*
 * node.h
 *
 */

#ifndef NODE_H_
#define NODE_H_

#include "BNode.h"
#include "../entidades/IEntidad.h"
#include "../utils/types.h"
#include "KeyElement.h"
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

class Node: public BNode {
private:
	Offset leftNode;
	std::vector<KeyElement*> keyElements;

	vector<KeyElement*> splitKeyElements();
    bool doInsertOrModifyInChild(BNode * childNodeToSearch, IElement * elemToInsert,int insertOrModify);

    BNode* findChild(IElement* key);
    void findChilds(IElement* elementToFind, std::vector<BNode*> &returnNodes);
    void removeKey(IEntidad* key);
    void insertFirstKey(KeyElement* keyelement);

public:
    Node();
    virtual ~Node();
    void appendKeyElementInOrder(KeyElement *keyElement);
    /**
     * Devuelve true si al insertar se modifico el estado del este nodo o false en caso contrario
     */
    bool insert(IElement *elem);
    /**
     * Devuelve true si al modificar fue modificado este o false en caso contrario.
     */
    bool modify(IElement* elemToModify);
    bool remove(IEntidad* key);
    Offset getLeftNode();
    void setLeftNode(Offset leftNode);

    /**
   	 * Balancea con el sibling, devuelve true si cambiaron (ambios this y sibling)
   	 * false en caso contrario.
   	 * Pasa los primeros elementos de este nodo al sibling (hermano)
   	 */
   	bool rightBalanceWith(BNode* leftSibling);

   	/**
   	 * Balancea con el sibling, devuelve true si cambiaron (ambios this y sibling)
   	 * false en caso contrario.
   	 * Pasa los ultimos elementos de este nodo al sibling (hermano)
   	 */
   	bool leftBalanceWith(BNode* rightSibling);

   	/**
   	 * Devuelve el nodo hoja que contiene la clave (o el valor)
   	 */
   	LeafNode* find(IEntidad* key);
   	void findElements(IEntidad* key, std::vector<BNode*> &founds);
   	IElement *findExact(IEntidad* key);
   	/**
   	 * Agrega todos los elementos de siblin a este nodo
   	 */
   	bool join(BNode* sibling);
   	IEntidad* getFirstKey();
	KeyElement *doSplit();
    void doSplit(IElement *elem);
    std::vector<KeyElement*>::iterator getKeyElementsBegin();
	std::vector<KeyElement*>::iterator getKeyElementsEnds();
	std::string serialize();
	void unserialize(std::string &buffer);

	/* devuelve el tamannoo de los datos:
	 * LeftOffset + Tamannoo de todos los elementos + tamannoo del Bnode (Level y RegisterCount)*/
	DataSize getDataSize();
	/**
	 * Hay que buscar en la lista, si es el ultimo elemento de la lista
	 * entonces hay que devolver NULL, porque no le pedimos al primo. Solo se balancea con los hermanos
	 * Puede devolver NULL
	 */
	BNode* getRightSibling(BNode* child);
	BNode* getLeftSibling(BNode* child);
	void changeKey(BNode* child);
	/**
	 * Elmina del vector de hijos el KeyElemento que 
	 * corresponde con key
	 */
	void removeKey(BNode* child);

	bool isOverflowded(int modifyOrInsert);
	bool isUnderflowded();

	RegisterCounter getRegisterCounter() {
		return keyElements.size();
	}
	virtual ostream& printMe(ostream&);
	void exportNode();
};

#endif /* NODE_H_ */
