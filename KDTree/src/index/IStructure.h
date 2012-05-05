/*
 * Index.h
 *
 *  Created on: Oct 1, 2011
 *      Author: carlos
 */

#ifndef INDEX_H_
#define INDEX_H_
#include "../entidades/IEntidad.h"
#include "../utils/types.h"
#include "../bplustree/KeyBplus.h"
#include "../bplustree/exceptions/ProgramException.h"
class IStructure {
public:

	/**
	 *Inicializarlo con el nombre de archivo. Tener una asociacion con el nombre de archivo y la entidad que debe crear.
	 *Asi de esta forma se puede saber como se serializa y se deserializa.
	 */
	IStructure(ESTRUCTURAS estructura);
	virtual int insert(IEntidad* entidad)=0;
	virtual int modify(IEntidad* entidad)=0;
	virtual IEntidad* find(ID key)=0;
	virtual int remove(ID key)=0;
	virtual ~IStructure();
	//Esto es para recorrer la estructura en forma secuencial. Solo en los arboles
	virtual IEntidad* siguiente()=0;
    ESTRUCTURAS getEstructura() const
    {
        return estructura;
    }

    /**
     * Elimina la estructura del sistema
     */
    virtual void dropStructure(){
    	//TODO cuando todos los hijos implementen. Sacar la exception y hacerlo virtual
    	throw ProgramException("metodo no implementado");
    }
    void setEstructura(ESTRUCTURAS estructura)
    {
        this->estructura = estructura;
    }

private:
	ESTRUCTURAS estructura;
};

#endif /* INDEX_H_ */
