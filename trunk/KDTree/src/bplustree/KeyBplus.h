/*
 * KeyBplus.h
 *
 *      Author: carlos
 */

#ifndef KEYBPLUS_H_
#define KEYBPLUS_H_
#include "../persistence/ISerializable.h"
#include "../utils/types.h"
using namespace std;
class KeyBplus: public ISerializable {
private:
	ID keyDistrito;
	ID KeyEleccion;

public:

	KeyBplus();
	virtual ~KeyBplus();
	virtual std::string serialize();
	virtual void unserialize(std::string &buffer);
	virtual int getDataSize();

    ID getKeyEleccion() const
    {
        return KeyEleccion;
    }

    void setKeyEleccion(ID KeyEleccion)
    {
        this->KeyEleccion = KeyEleccion;
    }

};

#endif /* KEYBPLUS_H_ */
