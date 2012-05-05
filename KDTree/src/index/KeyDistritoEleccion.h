/*
 * KeyEleccionDistrito.h
 *
 *      Author: carlos
 */

#ifndef KEYELECCIONDISTRITO_H_
#define KEYELECCIONDISTRITO_H_
#include "../persistence/ISerializable.h"
#include "../utils/types.h"
/**
 * Es estima que el valor maximo para la que es 4200
 * y el valor maximo para eleccion es 967296. Valores mas que suficientes para esto.
 *
 */
class KeyDistritoEleccion: public ISerializable {
private:
	ID keyDistrito;
	ID KeyEleccion;

public:
	KeyDistritoEleccion();
	KeyDistritoEleccion(ID keyDistrito, ID keyEleccion);
	virtual ~KeyDistritoEleccion();
	virtual std::string serialize();
	virtual void unserialize(std::string &buffer);

	/*
	 * Cantidad de bytes que ocupará cuando sea serializado
	 **/
	virtual int getDataSize();
	//TODO sobrecargar los operadores <<
	bool operator==(const KeyDistritoEleccion& k) { // sobrecarga operador ==
		bool isEqual=this->KeyEleccion == k.KeyEleccion && this->keyDistrito
				== k.keyDistrito;
		return isEqual;
	}
	bool operator>(const KeyDistritoEleccion& k) { // sobrecarga operador >
		return this->keyDistrito > k.keyDistrito || (this->keyDistrito
				== k.keyDistrito && this->KeyEleccion > k.KeyEleccion);
	}
	bool operator<(const KeyDistritoEleccion& k) { // sobrecarga operador <
		return this->keyDistrito < k.keyDistrito || (this->keyDistrito
				== k.keyDistrito && this->KeyEleccion < k.KeyEleccion);
	}

    ID getKeyDistrito()
    {
        return keyDistrito;
    }

    ID getKeyEleccion()
    {
        return KeyEleccion;
    }
    void setKeyDistrito(ID keydistrito){
    	this->keyDistrito=keydistrito;
    }
    void setKeyEleccion(ID KeyEleccion)
    {
        this->KeyEleccion = KeyEleccion;
    }

};

#endif /* KEYELECCIONDISTRITO_H_ */
