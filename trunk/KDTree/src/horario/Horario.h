/*
 * Horario.h
 *
 *  Created on: 16/05/2012
 *      Author: ariel
 */

#ifndef HORARIO_H_
#define HORARIO_H_

#include "../persistence/ISerializable.h"
#include "hour.h"
#include "date.h"

#include <iomanip>
#include <sstream>
using namespace std;

class Horario : public ISerializable {
private:
        Hour* hora;
        Date* fecha;
public:
        Horario();
        Horario(Hour* hora, Date* fecha){
                this->hora = hora;
                this->fecha = fecha;
        }

        Date* getFecha(){
                return this->fecha;
        }

        Hour* getHora(){
                return this->hora;
        }
        virtual ~Horario();

    	void copiar(Horario *unHorario);
    	string serialize();
    	void unserialize(std::string& buffer);
    	//Cantidad de bytes que ocupará cuando sea serializado.Es el TOTAL del elemento
    	DataSize getDataSize();

    	friend std::ostream & operator<<(std::ostream & os, const Horario & unHorario);
    	//metodos para relacionarse con Horario
    	//todo: ...
};

#endif /* HORARIO_H_ */
