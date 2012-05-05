/*
 * ISerializable.h
 *
 */

#ifndef ISERIALIZABLE_H_
#define ISERIALIZABLE_H_

#include <string>
#include "Serializacion.h"
#include "../utils/types.h"

class ISerializable {
public:
		virtual std::string serialize() = 0;
		virtual void unserialize(std::string& buffer) = 0;

		/*
		* Cantidad de bytes que ocupará cuando sea serializado.
		* Es el TOTAL del elemento
		**/
		virtual int getDataSize() = 0;

public:
		/* Funciones para serializar enteros y float */

		static Serializacion serializarEntero( int entero ){
			Serializacion serial( (char*)&entero, sizeof(int) );
			return serial;
		}

		static int desSerializarEntero( Serializacion &serial ){
			char enteroBinario [sizeof(int)];
			for ( size_t i = 0; i<sizeof(int); i++ ) enteroBinario[i] = serial[i];
			int* punteroAEntero;
			punteroAEntero = (int*)enteroBinario;
			return (*punteroAEntero);
		}

		static Serializacion serializarID( ID id ){
			Serializacion serial( (char*)&id, sizeof(ID) );
			return serial;
		}

		static int desSerializarID( Serializacion &serial ){
			char enteroBinario [sizeof(ID)];
			for ( size_t i = 0; i<sizeof(ID); i++ ) enteroBinario[i] = serial[i];
			ID* punteroAID;
			punteroAID = (ID*)enteroBinario;
			return (*punteroAID);
		}

		static Serializacion serializarLong( long lEntero ){
			Serializacion serial( (char*)&lEntero, sizeof(long) );
			return serial;
		}

		static Serializacion serializarULong( unsigned long ulEntero ){
			Serializacion serial( (char*)&ulEntero, sizeof(unsigned long) );
			return serial;
		}

		static int desSerializarLong( Serializacion &serial ){
			char lEnteroBinario [sizeof(long)];
			for ( size_t i = 0; i<sizeof(long); i++ ) lEnteroBinario[i] = serial[i];
			long* punteroALEntero;
			punteroALEntero = (long*)lEnteroBinario;
			return (*punteroALEntero);
		}

		static int desSerializarULong( Serializacion &serial ){
			char lEnteroBinario [sizeof(unsigned long)];
			for ( size_t i = 0; i<sizeof(unsigned long); i++ ) lEnteroBinario[i] = serial[i];
			unsigned long* punteroALEntero;
			punteroALEntero = (unsigned long*)lEnteroBinario;
			return (*punteroALEntero);
		}

		static float desSerializarFloat( Serializacion &serial ){
			char floatBinario[sizeof(float)];
			for ( size_t i = 0; i<sizeof(float); i++ ) floatBinario[i] = serial[i];
			float* punteroAFloat;
			punteroAFloat = (float*)floatBinario;
			return (*punteroAFloat);
		}

		static Serializacion serializarFloat( float valor ){
			Serializacion serial( (char*)&valor, sizeof(float) );
			return serial;
		}
};

#endif /* ISERIALIZABLE_H_ */
