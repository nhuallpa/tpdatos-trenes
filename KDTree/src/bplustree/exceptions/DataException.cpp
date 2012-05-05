/*
 * ProgramException.cpp
 *
 */

#include "DataException.h"

DataException::DataException() throw() {

}
DataException::DataException(string description) throw() {
	this->description=description;

}

DataException::~DataException() throw() {

}

const char* DataException::what() const throw(){
	return this->description.c_str();
}

