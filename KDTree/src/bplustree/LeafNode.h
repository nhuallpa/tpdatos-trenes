/*
 * LeafNode.h
 *
 */

#ifndef LEAFNODE_H_
#define LEAFNODE_H_
#include "../utils/const.h"
#include "../utils/types.h"
#include "exceptions/ElementAlreadyExists.h"
#include "exceptions/ElementNotFoundException.h"
#include "BNode.h"
#include "Element.h"
#include <string.h>
#include <vector>
#include <algorithm>
#include "../persistence/PersistorBase.h"
#include "../entidades/IEntidad.h"
#include <functional>
#include "NodeFactory.h"
class LeafNode: public BNode {
private:
	Offset nextNode;
	Offset prevNode;
	FreeSpace freeSpace;
	std::vector<IElement*> elements;
	std::vector<IElement* > splitElements();
	std::vector<IElement*>::iterator itElementActual;
	bool itElementInitialized;

	int getDataElementsSize(std::vector<IElement*> vector);
	std::vector<IElement*>::iterator findElement(IElement* elemToFind);
public:
	IElement* nextElement();
    LeafNode();
    virtual ~LeafNode();
    KeyElement *doSplit();
    IElement *getElement(IEntidad* key);
    std::vector<IElement*>::iterator getElementsBegin();
    std::vector<IElement*>::iterator getElementsEnds();
    bool rightBalanceWith(BNode *leftSibling);
    bool leftBalanceWith(BNode *rightSibling);
    bool join(BNode *sibling);
    IEntidad* getFirstKey();
    Offset getPrevNode();
    Offset getNextNode();
    FreeSpace getFreeSpace();
    bool insert(IElement *elem);
    LeafNode* find(IEntidad* key);
    void findElements(IEntidad* key, std::vector<BNode*> &founds);
    IElement *findExact(IEntidad* key);
    bool modify(IElement *elemToModify);
    bool insertarTest(IElement *elem);
    bool remove(IEntidad* key);
    std::string serialize();
    void unserialize(std::string & buffer);
    DataSize getDataSize();

	bool isOverflowded(int modifyOrInsert);
	bool isUnderflowded();
	virtual ostream& printMe(ostream&);

	void exportNode();
	RegisterCounter getRegisterCounter();

};

#endif /* LEAFNODE_H_ */
