/*
 * KeyElement.h
 *
 */

#ifndef KEYELEMENT_H_
#define KEYELEMENT_H_

#include "../utils/types.h"
#include "../persistence/ISerializable.h"
#include "../entidades/IEntidad.h"
#include <string>
#include <iostream>

using namespace std;
class KeyElement: public ISerializable {
private:
	IEntidad* key;
	Offset rightNode;
public:
	KeyElement();
	KeyElement(IEntidad* key,Offset rightNode);
	virtual ~KeyElement();

	Offset getrightNode();
	void setRightNode(Offset rightNode);

	void setKey(IEntidad* key);
	IEntidad* getKey();
    bool operator== (KeyElement k) {   // sobrecarga operador ==
       return this->key==k.key ;
     }
     bool operator> (KeyElement k) {    // sobrecarga operador >
       return this->key>k.key;
     }
     bool operator< (KeyElement k) {    // sobrecarga operador <
       return this->key<k.key;
     }

     friend ostream& operator<<(ostream&, KeyElement&);

     void toString(){
    	 cout<<"Key "<<this->key->toString()<<" RightOffSet: "<<rightNode<<" ";
     }
	/******************************************************
	 * 					PERSISTENCIA
	 *
	 ****************************************************/
	void unserialize(std::string &buffer);
	DataSize getDataSize();
	std::string serialize();





};

#endif /* KEYELEMENT_H_ */
