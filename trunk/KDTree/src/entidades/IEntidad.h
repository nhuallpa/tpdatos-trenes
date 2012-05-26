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
	virtual ~IEntidad();

	virtual std::string toString();

	virtual std::string serialize();
	virtual void unserialize(std::string& buffer);

	virtual bool equals(IEntidad* entidad){
		return false;
	}

	//no virtual para subclases hasta que sea necesario
	virtual int getDataSize() {
		return this->serialize().length();
	}

};

#endif /* IENTIDAD_H_ */
