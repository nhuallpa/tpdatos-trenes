/*
 * Block.h
 *
 */

#ifndef BLOCK_H_
#define BLOCK_H_

#include "ISerializable.h"
#include "../utils/types.h"

class Block: public ISerializable {
private:
	Offset offset;
	ESTRUCTURAS estructura;
public:
	ESTRUCTURAS getEstructura() {
		return estructura;
	}
	void setEstructura(ESTRUCTURAS estructura) {
		this->estructura = estructura;
	}
	Block();
	virtual ~Block();
	/**
	 * OffSet donde el bloque se esta persistiendo
	 */
	Offset getOffset();
	void setOffset(Offset offset);
};

#endif /* BLOCK_H_ */
