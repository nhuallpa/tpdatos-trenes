#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <fstream>
#include "../../entidades/horario/exceptions/DateExceptions.h"
#include "../../persistence/ISerializable.h"
#include "../../utils/const.h"

class Date : public ISerializable {
  unsigned int day;
  unsigned int month;
  unsigned int year;
  public:
    Date( const Date & );
    Date( unsigned int = DIA_DEFAULT , unsigned int = MES_DEFAULT , unsigned int = ANIO_DEFAULT );
    Date(string date);
    void setDay( unsigned int );
    void setMonth( unsigned int );
    void setYear( unsigned int );
    void setDate( unsigned int , unsigned int , unsigned int );
    void setDate ( const Date & );
    void printDate ( std::ostream & os);
    void printDate ( std::ofstream & os);    
    void printDate ( std::fstream & os);
    std::string getDate();
    unsigned int getDay() const;
    unsigned int getMonth() const;
    unsigned int getYear() const;
    bool operator==( const Date & );
    bool operator<( const Date & );
    bool operator>( const Date & );
    bool operator<=( const Date & );
    bool operator>=( const Date & );
    Date & operator=( const Date & );
    friend std::ostream & operator<<(std::ostream & os, const Date &);
    
	std::string serialize();
	void unserialize(std::string& buffer);

	DataSize getDataSize();
};

#endif
