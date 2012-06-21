	#ifndef HOUR_H
#define HOUR_H
#include <iostream>
#include "../../entidades/horario/exceptions/HourExceptions.h"
#include "../../persistence/ISerializable.h"
#include "../../utils/const.h"

class Hour : public ISerializable {
  unsigned int hour;
  unsigned int min;
  public:
    Hour( unsigned int = HORA_DEFAULT , unsigned  int = MINUTO_DEFAULT );
    Hour( const Hour & );
    void setHour( unsigned int );
    void setMin( unsigned int );
    void setHour( unsigned int , unsigned int );
    void setHour( const Hour & );
    unsigned int getHor() const ;
    unsigned int getMin() const;
    std::string getHour() const;
    int operator-( Hour &);// diferença em minutos entre duas datas;
    Hour & operator=( const Hour & );
    bool operator==( const Hour & ) const;
    bool operator!=( const Hour & ) const;
    bool operator<( const Hour & ) const;
    bool operator>( const Hour & ) const;
    bool operator<=( const Hour & ) const;
    bool operator>=( const Hour & ) const;
    friend Hour operator+( const Hour & , int );
    friend Hour operator-( const Hour & , int ); 
    friend std::ostream & operator<<( std::ostream & os, const Hour & );

	std::string serialize();
	void unserialize(std::string& buffer);

	DataSize getDataSize();
};

#endif
