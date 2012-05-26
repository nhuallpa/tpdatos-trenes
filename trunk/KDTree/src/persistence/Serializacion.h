#ifndef _SERIALIZACION_H_
#define _SERIALIZACION_H_

#include <iostream>
#include <string>
using namespace std;

#include "../utils/types.h"

#define CHAR_DE_RELLENO '\0'

/**
 * Clase para trabajar con cadenas de caracteres que contienen
 * dentro al caracter '\0'
 */
class Serializacion
{
private:
    string _cadenaS;
    int index;
  
public:
    Serializacion();
    Serializacion( const Serializacion& str );
    Serializacion( const string& );

    /*
     * Si el caracter '\0' no define el fin de la cadena, es necesario
     * pasar el tamaño de la misma por parámetro.
     **/
    Serializacion( const char * s , size_t size );
    
    /*
     * Se usa cuando se tiene una cadena terminada en '\0'
     **/
    Serializacion( const char * s );

    size_t size() const;
    void resize( size_t n, char c = CHAR_DE_RELLENO );

    Serializacion& operator= ( const Serializacion& str );
    Serializacion& operator= ( char c );
    Serializacion& operator= ( const string& cadena );
    Serializacion& operator= ( const char* cadena );

    Serializacion& operator+= ( const Serializacion& str );
    Serializacion& operator+= ( char c );

    /*
     * El char* debe estar terminado en \0. No se concatena
     * el '\0' en la Serializacion.
     **/
    Serializacion& operator+= ( const char* c );

    bool operator== ( const Serializacion& );

    int comparar(const Serializacion& str);
    Serializacion substr ( size_t pos , size_t n  ) const;

    /*
     * Transforma el Serializacion en un string común. Dentro del string devuelto
     * no debe haber caracteres '\0' intermedios.
     * Se crea un string con los primeros size bytes de la Serializacion.
     **/
    string toString() const;

    const char* toChar() const;

    const char& operator[] ( size_t pos ) const;
    char& operator[] ( size_t pos );


    /*
     * Carga el stream con 'size' bytes consecutivos tomados del istream.
     * Se borra el contenido previo del Serializacion.
     * Retorna true si los pudo leer todos, false si no. 
     **/
    bool read( istream& stream, size_t size );

    friend ostream& operator<< ( ostream&, const Serializacion& );

    void IndexReset();

    void addString(string data); //agrega string (size+contenido)
    void addEntero(int entero); //agrega entero
    void addULong(unsigned long ul);


    //---
    //Estos metodos devuelven el dato a partir de un index y lo incrementan.
    int getEntero();
    float getFloat();
    string getString(); //recupera string (size+contenido)
    unsigned long getULong();
    //---

    ~Serializacion();

};

#endif
