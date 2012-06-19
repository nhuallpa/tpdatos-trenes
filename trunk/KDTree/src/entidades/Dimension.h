/*
 * Dimension.h
 *
 *  Created on: 14/06/2012
 *      Author: sergio
 */

#ifndef DIMENSION_H_
#define DIMENSION_H_

#include "../entidades/IEntidad.h"

class Dimension : public IEntidad{
private:
	int dimension;
	int value;
public:
	Dimension(int dimension, int value);
	virtual ~Dimension();

	void setValue(int value);

	int compareTo(IEntidad* entidad);
	string toString () const;

	string serialize();
	void unserialize(string& buffer);

	DataSize getDataSize();
};

#endif /* DIMENSION_H_ */
