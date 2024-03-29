/*
 * types.h
 *
 */

#ifndef TYPES_H_
#define TYPES_H_

#include <string>

/* secuencias */

#define NOMBRE_SECUENCIA "secuencia"

/* archivo de secuencias */
#define ID_SEQUENCES_FILE "datos/sequences.txt"

#define PLAIN "plain"

using namespace std;

typedef unsigned long AUTONUMERIC_ID;
typedef char ENTITY_TYPE;
typedef int Offset;
typedef unsigned long ID;
typedef unsigned int Level;
typedef unsigned int RegisterCounter;
typedef unsigned int BlockSize;
typedef unsigned int DataSize;
typedef unsigned int FreeSpace;
typedef double ChargeFactor;
typedef char* Data;
typedef unsigned short PrecisionInt;
typedef unsigned long EnteroLargo;

typedef unsigned int uint;

#endif /* TYPES_H_ */
