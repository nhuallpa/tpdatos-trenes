/*
 * Lista.h
 *
 *  Created on: Oct 11, 2011
 *      Author: carlos
 */

#ifndef LISTA_H_
#define LISTA_H_
#include "IEntidad.h"
#include "../utils/types.h"
class Lista : public IEntidad
{
public:
    Lista();
    virtual ~Lista();
    virtual std::string serialize();
    virtual void unserialize(std::string & buffer);
    virtual int getDataSize();
    ID getIdEleccion() const;
    std::string getNombre() const;
    void setIdEleccion(ID idEleccion);
    void setNombre(std::string nombre);
	string toString();
private:
    ID id_eleccion;
    std::string nombre;
};

#endif /* LISTA_H_ */
