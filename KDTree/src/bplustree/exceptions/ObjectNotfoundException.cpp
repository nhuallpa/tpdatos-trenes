/*
 * ObjectNotfoundException.cpp
 *
 *  Created on: Oct 21, 2011
 *      Author: carlos
 */

#include "ObjectNotfoundException.h"

ObjectNotfoundException::ObjectNotfoundException(std::string desc) throw() {
	this->description=desc;
}
ObjectNotfoundException::ObjectNotfoundException() throw(){
	// TODO Auto-generated constructor stub

}

ObjectNotfoundException::~ObjectNotfoundException() throw(){
}

const char *ObjectNotfoundException::what() const throw()
{
	return this->description.c_str();

}


