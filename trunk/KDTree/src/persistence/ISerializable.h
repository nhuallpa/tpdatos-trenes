/*
 * ISerializable.h
 *
 */

#ifndef ISERIALIZABLE_H_
#define ISERIALIZABLE_H_

#include <string.h>
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
};

#endif /* ISERIALIZABLE_H_ */
