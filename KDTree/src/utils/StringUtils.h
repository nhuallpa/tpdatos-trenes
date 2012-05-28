/*
 * StringUtils.h
 *
 *  Created on: Oct 2, 2011
 *      Author: carlos
 */

#ifndef STRINGUTILS_H_
#define STRINGUTILS_H_

#define ID_SEPARATOR ","
#define SPACE_CHAR ' '

#include <sstream>
#include <list>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../utils/types.h"
#include <iostream>

using namespace std;

class StringUtils {
public:
	static string converFloatToString(float numero);
	static string intToString(int value);
	StringUtils();
/*
	 * Funcion que convierte un numero entero al mismo
	 * numero en una cadena de caracteres.
	 */
	static string convertIntToString(int numero);

	static int convertStringToInt(string nro);

	static uint convertStringToUint(string nro);

	static  std::string convertirAString( int numero);

	/**
	 * Elimina los espacios del string (todos los espacios, no solo los que estén al principio y al final)
	 */
	static string trim(const string& str);

	/**
	 * Convierte un string compuesto de ids separados por coma en una lista de ids
	 */
	static list<ID>* extractIDs(const string& strIdSet);

	/**
	 * Convierte un vector de ids en un sting con los ids separados por comas
	 */
	static string glueIds(const vector<ID>& ids);

	/**
	 * Convierte un string en un ids
	 */
	static ID stringToId(const string& str);

	/**
	 * Convierte un ID en un string
	 */
	static string idToString(const ID& id);

	virtual ~StringUtils();
};

#endif /* STRINGUTILS_H_ */
