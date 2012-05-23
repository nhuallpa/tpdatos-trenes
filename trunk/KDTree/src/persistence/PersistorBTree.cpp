/*
 * PersistorBTree.cpp
 *
 */

#include "PersistorBTree.h"
#include "../bplustree/LeafNode.h"
#include "../bplustree/Node.h"
#include "../bplustree/NodeFactory.h"
#include "../utils/StringUtils.h"

PersistorBTree PersistorBTree::instance;

BNode *PersistorBTree::getNodeInBlock(int blockNumber) {
	std::string buffer;
	Level level;
	BNode *root;

	buffer = this->load(blockNumber);
	buffer.copy((char*) &level, sizeof(Level));

	if (level == 0)
		root = NodeFactory::createLeafNode();
	else
		root = NodeFactory::createKeyNode();

	root->unserialize(buffer);
	root->setOffset(blockNumber);

	return root;
}

PersistorBTree* PersistorBTree::getInstance(){
	return &instance;
}

void PersistorBTree::init(std::string fileName, BlockSize size) {
	/* Validacion de que este iniciado */
	if (fileName.length() == 0 || size == 0) {
		string mensaje;
		mensaje.append("el nombre del archivo tiene longitud ").append(
				StringUtils::intToString(fileName.length())).append(
				" y el tamanno es de ").append(StringUtils::convertIntToString(
				size)).append(" por lo tanto esta inicializado el persistor : ").append(
				fileName);
		throw  PersistExceptions::PersistorNotInitializedException(mensaje);
	}

	freeSpaceManager = new FreeSpaceManager(fileName + ".fs");

	/* Abre el archivo para lectura - escritura binario */
	this->archivo.open(fileName.c_str(), std::ios::in | std::ios::out
			| std::ios::binary);
	this->blockSize = size;
	this->fileName = fileName;

	if (!this->archivo.is_open()) {
		this->archivo.clear();
		this->newFile(fileName);
	}

	this->archivo.seekg(0, std::ios::beg);
	/* Levanta el bloque header */
	char charBuffer[HEADER_SIZE];
	this->archivo.read(charBuffer, HEADER_SIZE);

	BlockSize test;
	memcpy(&test, &charBuffer, sizeof(BlockSize));

	if (test != size)
		throw new PersistExceptions::WrongBlockSize();
}

PersistorBTree::PersistorBTree() {
}

PersistorBTree::~PersistorBTree() {
}

void PersistorBTree::newFile(std::string fileName) {
	PersistorBase::newFile(fileName);
	LeafNode *root = NodeFactory::createLeafNode();

	this->add(root);

	delete root;
}

BNode* PersistorBTree::getRoot() {
	std::string buffer;
	Level level;
	BNode *root;

	buffer = this->load(0);
	buffer.copy((char*) &level, sizeof(Level));

	if (level == 0)
		root = NodeFactory::createLeafNode();
	else
		root = NodeFactory::createKeyNode();

	root->unserialize(buffer);
	root->setOffset(0);

	return root;
}
