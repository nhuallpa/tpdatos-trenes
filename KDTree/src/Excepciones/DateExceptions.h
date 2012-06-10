#ifndef DATE_EXCEPTION_H
#define DATE_EXCEPTION_H
#include <stdexcept>
#include <exception>
using std::runtime_error;

class DayNonexistent : public runtime_error{
  public:
    DayNonexistent(): runtime_error( "No existe el dia" ) {}
};

class MonthNonexistent : public runtime_error{
  public:
    MonthNonexistent(): runtime_error( "No existe el mes segun el dia" ) {}
};

class YearNonexistent : public runtime_error{
  public:
    YearNonexistent(): runtime_error( "NNo existe el año segun el mes!" ) {}
};

class DateNonexistent : public runtime_error{
  public:
    DateNonexistent(): runtime_error( "No existe el Date" ) {}
};

#endif
