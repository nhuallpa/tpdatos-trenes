/*
 * OverflowException.h
 *
 */

#ifndef OVERFLOWEXCEPTION_H_
#define OVERFLOWEXCEPTION_H_
#include <string>
#include <exception>
using namespace std;

class OverflowException : public std::exception{
private:
	string description;
public:
	OverflowException()throw();
	OverflowException(string desc) throw();
	virtual ~OverflowException() throw();
	const char* what() const throw();
};

#endif /* OVERFLOWEXCEPTION_H_ */
