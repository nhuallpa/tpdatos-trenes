#ifndef HORAEXCEP_H
#define HORAEXCEP_H
#include <stdexcept>
#include <exception>

class HourNonexistent : public std::runtime_error{
  public:
    HourNonexistent(): std::runtime_error( "No existe la hora" ) {}
};

class MinNonexistent : public std::runtime_error{
  public:
    MinNonexistent(): std::runtime_error( "No existe la hora" ) {}
};

#endif

