/*
 * util.cpp
 *
 */

#include "utiles.h"
#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <math.h>
#include "StringUtils.h"
#include "../utils/StringUtils.h"
#include <fstream>
Util::Util() {

}

Util::~Util() {
}

string Util::SerializeInt(int value) {
	char *memoria = (char*) &value;
	string response(memoria, sizeof(int));
	return response;
}

string Util::SerializeString(string value) {
	string response(SerializeInt(value.length()));
	response.append(value);
	return response;
}

string Util::SerializeBool(bool value) {
	if (value)
		return "1";
	return "0";
}

string Util::SerializeChar(char value) {
	string response = " ";
	response[0] = value;
	return response;
}

int Util::DeSerializeInt(string &data) {
	int *result = new int;
	data.copy((char*) result, sizeof(int));
	data.erase(0, sizeof(int));
	return *result;
}

string Util::DeSerializeString(string& data) {
	string size(data, 0, 4);
	int tam = DeSerializeInt(size);

	string info(data, 4, tam);

	data.erase(0, sizeof(int));
	data.erase(0, tam);
	return info;

}

bool Util::DeSerializeBool(string &data) {
	bool response = true;
	if (data[0] == '0')
		response = false;
	data.erase(0, 1);
	return response;
}

char Util::DeSerializeChar(string &data) {
	char response = data[0];
	data.erase(0, 1);
	return response;
}

string Util::toString(int value) {
	std::stringstream out;
	out << value;
	return out.str();
}

string Util::uIntToString(unsigned int value) {
	std::stringstream out;
	out << value;
	return out.str();
}

string Util::luIntToString(long unsigned int value) {
	std::stringstream out;
	out << value;
	return out.str();
}


int Util::toInt(string str) {
	stringstream ss(str);
	int n;
	ss >> n;
	return n;
}

bool Util::archivoExiste(string filename) {
	if (FILE * file = fopen(filename.c_str(), "r")) {
		fclose(file);
		return true;
	}
	return false;
}

unsigned int Util::getBit(unsigned int number,unsigned int position) {
	unsigned int bit = number >> position;
	bit &= 1;

	return bit;
}
unsigned int Util::getBits(unsigned int number,unsigned int msPos,unsigned int lsPos) {
	unsigned int mask = pow(2,msPos-lsPos+1)-1;
	number >>= lsPos;
	number &= mask;

	return number;
}


void Util::setBit(unsigned int &number,unsigned int position,short unsigned int value) {
	unsigned int numerPos = pow(2,position);
	if(value == 1)
		number |= numerPos;
	else
		number &= ~numerPos;
}

void Util::setBit(unsigned char * buffer,unsigned int bufferSize, unsigned int position, short unsigned int value) {
	unsigned int posBuffer =  floor((double)position / 8);
	unsigned int numerPos = pow(2,position);
	if(posBuffer < bufferSize) {
		unsigned char bufferChar = buffer[posBuffer];
		if(value == 1)
			bufferChar |= numerPos;
		else
			bufferChar &= ~numerPos;
		buffer[posBuffer] = bufferChar;
	}
}

unsigned short int Util::getNegBit(unsigned short int bit) {
	if(bit == 0)
		return 1;
	else
		return 0;
}


string Util::bitsIntToString(unsigned int number , unsigned int presicion) {
	string bits = "";

	unsigned int i, k, mask;

	for (i = presicion-1; i != UINT_MAX; i--) {
		mask = 1 << i;
		k = number & mask;
		if (k == 0)
			bits += "0";
		else
			bits += "1";
	}

	return bits;
}

unsigned int Util::bitsStringToInt(string bits) {
	unsigned int number = 0;

	for(unsigned int i = 0 ; i < bits.size(); i++) {
		char bit = bits[i];

		number = number << 1;
		if(bit == '1') {
			setBit(number,0,1);
		}
	}

	return number;

}

void Util::printBits(unsigned int number) {
	unsigned int i, k, mask;

	for (i = 31; i != UINT_MAX; i--) {
		mask = 1 << i;
		k = number & mask;
		if (k == 0)
			std::cout << "0 ";
		else
			std::cout << "1 ";
	}
	std::cout << std::endl;
}

PrecisionInt Util::maskBit(unsigned int precision, PrecisionInt bit)
{
	return 1 <<  (precision - (1+(bit)));
}

string Util::textFileToString(string & path)
{
	ifstream file;
	int c;
	std::stringstream text;


	file.open(path.c_str());
	if (!file.is_open()){
		cout<<path<<" no existe.";
		throw std::ios_base::failure("Archivo no existe");
	}

	while (!file.eof()){
		c=file.get();
		if (!file.eof())
			text<<char(c);
	}
	file.close();
	return text.str();
}

void Util::stringToTextFile(string & path, string & data)
{
	ofstream salida;

	salida.open(path.c_str());
	salida<<data;
	salida.close();

}

string Util::strdate()
{
	struct tm *ptr;
	time_t sec;
	time(&sec);
	ptr = localtime(&sec);
	string date;

	   date=StringUtils::convertIntToString(ptr->tm_mday);
	   date+="/";
	   date+=StringUtils::convertIntToString(ptr->tm_mon + 1);
	   date+="/";
	   date+=StringUtils::convertIntToString(ptr->tm_year + 1900);
	   return date;
}





