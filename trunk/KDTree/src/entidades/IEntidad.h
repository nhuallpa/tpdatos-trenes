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
#include "../utils/const.h"
#include <string>

using namespace std;

class IEntidad: public ISerializable {

public:
	IEntidad();
	virtual ~IEntidad();

	virtual std::string toString() const;
	friend std::ostream & operator<<(std::ostream & os, const IEntidad & rp);

	virtual std::string serialize();
	virtual void unserialize(std::string& buffer);

	virtual int compareTo(IEntidad* entidad)=0;

	//no virtual para subclases hasta que sea necesario
	virtual DataSize getDataSize() {
		return this->serialize().length();
	}

};

#endif /* IENTIDAD_H_ */
