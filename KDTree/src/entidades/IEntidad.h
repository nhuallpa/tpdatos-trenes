/*
 * IEntidad.h
 *
 *  Created on: Oct 1, 2011
 *      Author: hordia
 */

#ifndef IENTIDAD_H_
#define IENTIDAD_H_

#include "../persistence/ISerializable.h"
#include "../utils/types.h"
#include <string>

using namespace std;

class IEntidad: public ISerializable {

public:
	IEntidad();
	virtual ID getID() const;
	virtual void setID(ID id);

	virtual ~IEntidad();

	virtual string toString();

	std::string serialize() {
		throw "Esta clase no deberia ser instanciada nunca";
		return "";
	}

	//no virtual para subclases hasta que sea necesario
	virtual int getDataSize() {
		return this->serialize().length();
	}

protected:
	ID id;

};

#endif /* IENTIDAD_H_ */
