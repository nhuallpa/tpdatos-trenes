/*
 * DataException
 *
 */

#ifndef DataException_H_
#define DataException_H_

#include <exception>
#include <string>

using namespace std;
class  DataException: public std::exception{
private:
	std::string description;
public:
	DataException() throw();
	DataException(string description) throw();
	virtual ~DataException() throw();
	const char* what() const throw();
};

#endif /* PROGRAMEXCEPTION_H_ */
