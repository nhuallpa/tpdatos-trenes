#include "Serializacion.h"
#include "ISerializable.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Serializacion::Serializacion()
{
	this->index = 0;
}

Serializacion::Serializacion ( const Serializacion& str ): index(0)
{
  if ( &str != this )
    this->_cadenaS = str._cadenaS;

  index = 0;
}

Serializacion::Serializacion ( const char * s , size_t size ): index(0)
{  
  size_t j;

  for ( j=0; j<size; j++ )
  {
    this->_cadenaS += s[j];
  }

  index = 0;
}

Serializacion::Serializacion ( const char * s ): index(0)
{
  this->_cadenaS = s;
  index = 0;
}

Serializacion::Serializacion( const string& cadena )
{
  this->_cadenaS = cadena;
  index = 0;
}

const char* Serializacion::toChar() const
{
    return this->_cadenaS.c_str();
}

size_t Serializacion::size() const
{
  return this->_cadenaS.size();
}

void Serializacion::resize ( size_t n, char c )
{
  this->_cadenaS.resize( n,c );
}

Serializacion& Serializacion::operator= ( const Serializacion& str )
{
  if ( &str != this )
    this->_cadenaS = str._cadenaS;
  return *this;
}

Serializacion& Serializacion::operator= ( const string& str )
{
  this->_cadenaS = str;
  return *this;
}

Serializacion& Serializacion::operator= ( char c )
{
  this->_cadenaS = c;
  return *this;
}

Serializacion& Serializacion::operator= ( const char* s )
{
  this->_cadenaS = s;
  return (*this);
}

Serializacion& Serializacion::operator+= ( const Serializacion& str )
{
  this->_cadenaS += str._cadenaS;
  return *this;
}

Serializacion& Serializacion::operator+= ( char c )
{
  this->_cadenaS += c;
  return *this;
}

Serializacion& Serializacion::operator+= ( const char* c )
{
  size_t tamC = strlen( c );
  for ( size_t i = 0; i< tamC; i++ )
  {
    this->_cadenaS += c[i];
  }
  return (*this);

}

bool Serializacion::operator== ( const Serializacion& str )
{
  return ( this->_cadenaS == str._cadenaS );
}

int Serializacion::comparar( const Serializacion& str )
{   
//FIXME
  return 0;
}

Serializacion Serializacion::substr ( size_t pos , size_t n  ) const
{
  Serializacion str( this->_cadenaS.substr(pos,n) );
  return str;
}

string Serializacion::toString() const
{
  return this->_cadenaS;
}

const char& Serializacion::operator[] ( size_t pos ) const
{
  return this->_cadenaS[pos];
}

char& Serializacion::operator[] ( size_t pos )
{
  return this->_cadenaS[pos];
}

ostream& operator<< ( ostream& stream, const Serializacion& cadena )
{
  stream << cadena._cadenaS;
  return stream;
}

bool Serializacion::read( istream& stream, size_t size )
{
  this->_cadenaS.resize(0);
  char buff;
  size_t leidos = 0;
  while ( (!stream.eof()) && (leidos < size) )
  {
    stream.get( buff );
    leidos++;
    this->_cadenaS += buff;
  }

  return ( leidos == size );

}

void Serializacion::IndexReset(){
	index = 0;
}


void Serializacion::addEntero(int entero){
	*this += ISerializable::serializarEntero( entero );
}

int Serializacion::getEntero(){
	Serializacion serialEntero = this->substr(index,sizeof(int));
	index += sizeof(int);
	return ISerializable::desSerializarEntero(serialEntero);
}

float Serializacion::getFloat() {
	Serializacion serialFloat = this->substr(index,sizeof(float));
	index+=sizeof(float);
	return ISerializable::desSerializarFloat(serialFloat);
}

void Serializacion::addString(string data) {
	*this += ISerializable::serializarEntero( data.length() );
	*this += data;
}

string Serializacion::getString() {

	int size = this->getEntero();
	if (size==0) return string(""); //para posibilitar guardar registros con clave nula!
	Serializacion tmpSerial = this->substr(index,size);
	index += size;
	return (tmpSerial.toString());
}

void Serializacion::addID(ID id) {
	*this += ISerializable::serializarID( id );
}

ID Serializacion::getID() {
	Serializacion serialID = this->substr(index,sizeof(ID));
	index += sizeof(ID);
	return ISerializable::desSerializarID(serialID);
}

void Serializacion::addULong(unsigned long ul) {
	*this += ISerializable::serializarULong(ul);
}

unsigned long Serializacion::getULong() {
	Serializacion serialLong = this->substr(index,sizeof(unsigned long));
	index += sizeof(unsigned long);
	return ISerializable::desSerializarULong(serialLong);
}

Serializacion::~Serializacion()
{
}
