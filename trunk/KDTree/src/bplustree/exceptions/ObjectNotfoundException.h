/*
 * ObjectNotfoundException.h
 *
 *  Created on: Oct 21, 2011
 *      Author: carlos
 */

#ifndef OBJECTNOTFOUNDEXCEPTION_H_
#define OBJECTNOTFOUNDEXCEPTION_H_
#include <exception>
#include <string>
using namespace std;
class ObjectNotfoundException: public std::exception {
private:
	std::string description;
public:
	ObjectNotfoundException() throw();
	ObjectNotfoundException(string description) throw();
	virtual ~ObjectNotfoundException() throw();
	const char* what() const throw();
};

#endif /* OBJECTNOTFOUNDEXCEPTION_H_ */
