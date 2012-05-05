/*
 * Exceptions.h
 *
 */

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <exception>
#include <string>
using namespace std;
namespace PersistExceptions {
class ElementNotFoundException: public std::exception {
};
class FailFileWriteException: public std::exception {
};
class FileNotFoundexception: public std::exception {
};
class FileReadException: public std::exception {
};
class OverFlowException: public std::exception {
};
class NotFindFreeNodeException: public std::exception {
};

class PersistorInitializedException: public std::exception {
private:
	string nombre;
public:

	PersistorInitializedException(string nombre) throw () {
		this->nombre = nombre;
	}
	const char* what() const throw () {
		return nombre.c_str();
	}
	virtual ~PersistorInitializedException() throw () {

	}

};

class PersistorNotInitializedException: public std::exception {
private:
	string nombre;
public:
	PersistorNotInitializedException(string nombre) throw () {
		this->nombre = nombre;
	}
	const char* what() const throw () {
		return nombre.c_str();
	}
	virtual ~PersistorNotInitializedException() throw () {

	}

};

class WrongBlockSize: public std::exception {
};
}

#endif /* EXCEPTIONS_H_*/
