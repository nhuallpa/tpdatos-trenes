/*
 * FileHandler.h
 *
 *  Created on: Oct 17, 2011
 *      Author: lucas
 */

#ifndef FILEHANDLER_H_
#define FILEHANDLER_H_
#include <vector>

class FileHandler {
public:
	FileHandler();
	virtual ~FileHandler();
    /**
     * Para elminar todos los handlers
     */
    void dropHandlers();
private:

    void init();

};

#endif /* FILEHANDLER_H_ */
