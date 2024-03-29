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
	unsigned int mask = (unsigned int)pow(2,msPos-lsPos+1)-1;
	number >>= lsPos;
	number &= mask;

	return number;
}


void Util::setBit(unsigned int &number,unsigned int position,short unsigned int value) {
	unsigned int numerPos = (unsigned int)pow(2,position);
	if(value == 1)
		number |= numerPos;
	else
		number &= ~numerPos;
}

void Util::setBit(unsigned char * buffer,unsigned int bufferSize, unsigned int position, short unsigned int value) {
	unsigned int posBuffer =  (unsigned int)floor((double)position / 8);
	unsigned int numerPos = (unsigned int)pow(2,position);
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

// parsea (1,3,4,6,6)
list<string> Util::parsear(string registro) {
	int posI = registro.find_first_of("(");
	int posF = registro.find_first_of(")");
	string relleno = registro.substr(posI+1,posF-posI-1);

	list<string> idList;
	char* token;
	char* auxStr;

	//creo un string auxiliar en estilo c
	auxStr = new char[relleno.length() + 1];

	//copio el string compuesto por ids al string auxiliar
	strcpy(auxStr, relleno.c_str());

	//parseo el primer id
	token = strtok(auxStr, ID_SEPARATOR);
	string tokenString(token);
	idList.push_front(tokenString);

	//parseo el resto de los ids
	while( ( token = strtok(NULL, ID_SEPARATOR) ) != NULL){
		string valor(token);
		idList.push_back(valor);
	}

	delete[] auxStr;
	return idList;
}

vector<string> Util::split(char separador, const string& cadena)
{
	vector<string> out;
	string aux;
	for (string::const_iterator i = cadena.begin(); i != cadena.end(); i++)
	{
	const char& k = *i;
	if (k == separador)
	{
	out.push_back(aux);
	aux.clear();
	}
	else
	aux.push_back(k);
	}

	out.push_back(aux);
	return out;
}

string Util::getNombreSubElemento(int idSubElemento)
{
	string nombresCampos[] = {NOMBRE_LINEA, NOMBRE_FORMACION, NOMBRE_FALLA, NOMBRE_ACCIDENTE, NOMBRE_FRANJAHORARIA };

	string nombreCampo_elejido = "";
	for(int i=0 ; i < CANT_SUBELEMENTOS ; i++){
		if (idSubElemento == i)
			nombreCampo_elejido = nombresCampos[i];
	}

	return nombreCampo_elejido;
}

int Util::getPosicionSubElemento(string nombreSubElemento)
{
	int pos = 0;
	if (nombreSubElemento == Util::getNombreSubElemento(0)) 		pos = 1;
	else if (nombreSubElemento == Util::getNombreSubElemento(1))	pos = 2;
	else if (nombreSubElemento == Util::getNombreSubElemento(2))	pos = 3;
	else if (nombreSubElemento == Util::getNombreSubElemento(3))	pos = 4;
	else if (nombreSubElemento == NOMBRE_FECHADESDE || nombreSubElemento == NOMBRE_FECHAHASTA) pos = 5;
	else pos=-1;

	return pos;
}


bool Util::esSubElemento(string nombreSubElemento) {
	bool esSubElemento_ = false;
	for(int i=0 ; i < CANT_SUBELEMENTOS && !esSubElemento_ ; i++){
		if (nombreSubElemento == Util::getNombreSubElemento(i) )
			esSubElemento_ = true;
	}

	return esSubElemento_;
}

string Util::crearEntradaDeReporte(string parametro, int cantSubParametros){
	string entradaDeReporte = "";
	bool errores_formatoDeConsulta = false;

	string elem_vacio = ELEM_VACIO;
	string elem_todo = ELEM_TODO;
	string separador = ELEM_SEPARADOR;

	if (cantSubParametros == 2){
		vector<string> parametro_parseado = Util::split(' ',parametro);
		vector<string>::iterator it = parametro_parseado.begin();
		string parametro_1 = *(it++);
		string parametro_2 = *(it);

		//le quito el '--'
		parametro_1 = parametro_1.substr(2,parametro_1.size()-1);
		parametro_2 = parametro_2.substr(2,parametro_2.size()-1);

		//separo clave y valor
		vector<string> parametro_2_parseado = Util::split('=',parametro_2);
		vector<string>::iterator it_param2 = parametro_2_parseado.begin();
		string clave1_ = *(it_param2++);
		string valor1_ = *(it_param2++);

		//empiezo a definir la entrada del reporte
		entradaDeReporte.append("(");
		for(int i=0 ; i<5 ; i++){
			if ((i+1) ==  5)
				separador = "";
			if ((i+1) ==  Util::getPosicionSubElemento(clave1_))
				entradaDeReporte.append(valor1_);
			else if ((i+1) ==  Util::getPosicionSubElemento(parametro_1))
				entradaDeReporte.append(elem_todo);
			else
				entradaDeReporte.append(elem_vacio);

			entradaDeReporte.append(separador);
		}
		entradaDeReporte.append(") ");

	}	if (cantSubParametros == 1){
		string parametro_1 = parametro;
		//le quito el '--'
		parametro_1 = parametro_1.substr(2,parametro_1.size()-1);

		//empiezo a definir la entrada del reporte
		entradaDeReporte.append("(");
		for(int i=0 ; i<5 ; i++){
			if ((i+1) ==  5)
				separador = "";
			if ((i+1) ==  Util::getPosicionSubElemento(parametro_1))
				entradaDeReporte.append(elem_todo);
			else
				entradaDeReporte.append(elem_vacio);

			entradaDeReporte.append(separador);
		}
		entradaDeReporte.append(") ");

	} else if (cantSubParametros == 4){
		vector<string> parametro_parseado = Util::split(' ',parametro);
		vector<string>::iterator it = parametro_parseado.begin();
		string parametro_1 = *(it++);
		string parametro_2 = *(it++);
		string parametro_3 = *(it++);
		string parametro_4 = *(it);
		//le quito el '--'
		parametro_1 = parametro_1.substr(2,parametro_1.size()-1);
		parametro_2 = parametro_2.substr(2,parametro_2.size()-1);
		parametro_3 = parametro_3.substr(2,parametro_3.size()-1);
		parametro_4 = parametro_4.substr(2,parametro_4.size()-1);

		//separo clave valor
		vector<string> parametro_2_parseado = Util::split('=',parametro_2);
		vector<string> parametro_3_parseado = Util::split('=',parametro_3);
		vector<string> parametro_4_parseado = Util::split('=',parametro_4);
		vector<string>::iterator it_param2 = parametro_2_parseado.begin();
		vector<string>::iterator it_param3 = parametro_3_parseado.begin();
		vector<string>::iterator it_param4 = parametro_4_parseado.begin();
		string clave1 = *(it_param2++);
		string clave2 = *(it_param3++);
		string clave3 = *(it_param4++);
		string valor1 = *(it_param2++);
		string valor2 = *(it_param3++);
		string valor3 = *(it_param4++);

		//empiezo a definir la entrada del reporte
		entradaDeReporte.append("(");
		for(int i=0 ; i<5 ; i++){
			if ((i+1) ==  5)
				separador = "";

			if ((i+1) ==  Util::getPosicionSubElemento(clave1))
				entradaDeReporte.append(valor1);
			else if ((i+1) ==  Util::getPosicionSubElemento(clave2)){
				entradaDeReporte.append(valor2);
				entradaDeReporte.append("-");
				entradaDeReporte.append(valor3);
			}
			else if ((i+1) ==  Util::getPosicionSubElemento(parametro_1))
				entradaDeReporte.append(elem_todo);
			else
				entradaDeReporte.append(elem_vacio);

			entradaDeReporte.append(separador);
		}
		entradaDeReporte.append(") ");

	}

	if (errores_formatoDeConsulta)
		cout<<"ocurrio un error en formato de consulta[utile.cpp]"<<endl;

	return entradaDeReporte;
}

string Util::calcularEntradaReporte(string contenidoConsulta, int cantParametros) {

	//subParametros encontrados en 'contenidoConsulta_parseada'
	string entrada_reporte = "";

	//("--formacion", "--falla=idFalla")
	if (cantParametros == 2){
		entrada_reporte = Util::crearEntradaDeReporte(contenidoConsulta,cantParametros);
	//("--falla")
	}else if (cantParametros == 1){
		entrada_reporte = Util::crearEntradaDeReporte(contenidoConsulta,cantParametros);

	//("--formacion", "--falla=idFalla", "--fechaDesde=fechaDesde", " --fechaHasta=fechaHasta")
	}else if (cantParametros == 4){
		entrada_reporte = Util::crearEntradaDeReporte(contenidoConsulta,cantParametros);
	}

	return entrada_reporte;
}

bool Util::consulta_esConParametro(string contenidoConsulta) {
	string primero = *(Util::split(' ',contenidoConsulta).begin());
	primero = primero.substr(2,primero.size()-1);
	return (Util::esSubElemento(primero));
}

bool Util::tienenParametroConRango(string contenidoConsulta) {
	bool tiene = false;
	if ( Util::consulta_esConParametro(contenidoConsulta) ){
//		cout<<Util::split(' ',contenidoConsulta).size()<<endl;
		tiene = (Util::split(' ',contenidoConsulta).size()) > 2;
	}else{
//		cout<<"consulta: "<<contenidoConsulta<<endl;
		vector<string> array = Util::split(',',contenidoConsulta);
		vector<string>::iterator it = array.begin();
//		string ultimo = *(Util::parsear(contenidoConsulta).end());
		string ultimo = *(it++);
		ultimo = *(it++);
		ultimo = *(it++);
		ultimo = *(it++);
		ultimo = *(it);
		ultimo = ultimo.substr(0,ultimo.size()-2);
		tiene = (Util::split('-',ultimo).size()) > 1;
	}
	return ( tiene );
}

