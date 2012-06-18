/*
 * ConfigurationMananger.cpp
 * Clase singleton donde se setean los parámetros de configuración
 *
 */

#include "ConfigurationMananger.h"
#include <math.h>
#include "../logger/Logger.h"
#include "../utils/StringUtils.h"

ConfigurationMananger ConfigurationMananger::instance;

ConfigurationMananger* ConfigurationMananger::getInstance(){
	return &instance;
}

ConfigurationMananger::ConfigurationMananger() {
	configFile = new ConfigFile("config.txt", "=", "#", "EndConfigFile");

	double maxRecordPercent;

	configFile->readInto(bufferSize, "blockSize");
	configFile->readInto(bufferSizeTree, "treeBlockSize");
	configFile->readInto<double> (chargeFactor, "chargePercent");
	configFile->readInto(minRecordSizeTree, "minRecordSizeTree");
	configFile->readInto<string> (this->filename, "filename");
	configFile->readInto<string> (this->sequenceName, "sequenceName");
	configFile->readInto<string> (this->sequenceFilename, "sequenceFilename");
	//configFile->readInto(maxRecordPercent,"maxRecordPercent");

	/* El factor maximo de registro tiene que ser tal que si dos nodos NO estan en underflow,
	 * juntos tienen que dar overflow
	 * 2*minUnderFlowSizeTree = porcentajeCarga * tamannoBloque
	 * minUnderFlowSizeTree = tamannoBloque/2 - maxRecordPercent * tamannoBloque
	 *
	 * (tamannBloque/2 - maxRecordPercent * tamaoBloque) * 2 = porcentajeCarga * tamannoBloque
	 * 1 - 2*maxRecordPercent = factorCarga
	 * maxRecordPercent = (1 - factorCarga)/2
	 */

	//chargeFactor = (int)(chargeFactor *maxRecordSizeTree 1000);
	//chargeFactor = (double)chargeFactor/1000;

	maxRecordPercent = (1 - chargeFactor) / 2;

	//Tamanno maximo que puede tener un registro.
	this->maxRecordSizeTree = (int)(this->bufferSizeTree * maxRecordPercent);

	this->maxNodeLoadForInsert = (int)floor(getChargeFactor() * getBufferSizeTree());

	// 50% del tamanioo maximo del bloque - el tamanio maximo del registro
	this->minUnderflowSizeTree = ((this->bufferSizeTree / 2)
			- this->getMaxRecordSizeTree());
	//delete configFile;
	string mensaje;
	mensaje.append("ConfigurationMannager name: ").append(
			"filename: ").append(this->filename).append("treeBlockSize ").append(
			StringUtils::convertIntToString(this->bufferSizeTree)).append(
			" maxRecordPercent: ").append(StringUtils::converFloatToString(
			maxRecordPercent)).append(" maxRecordSizeTree: ").append(
			StringUtils::convertIntToString(this->maxRecordSizeTree)).append(
			" maxLoadForInsert: ").append(StringUtils::converFloatToString(
			this->maxNodeLoadForInsert)).append(" minUnderflowSizeTree ").append(
			StringUtils::convertIntToString(this->minUnderflowSizeTree)).append(
			" nombre de la secuencia :").append(sequenceName);
	Logger::getInstance()->debug(mensaje);
}

int ConfigurationMananger::getMaxNodeLoadForInsert() {
	return this->maxNodeLoadForInsert;
}
unsigned int ConfigurationMananger::getBufferSizeTree() {
	return this->bufferSizeTree;
}

int ConfigurationMananger::getMinUnderflowSizeTree() {
	return this->minUnderflowSizeTree;

}

int ConfigurationMananger::getMinRecordSizeTree() {
	return this->minRecordSizeTree;
}
int ConfigurationMananger::getMaxRecordSizeTree() {
	return this->maxRecordSizeTree;
}
ConfigurationMananger::~ConfigurationMananger() {
	delete configFile;
}

ChargeFactor ConfigurationMananger::getChargeFactor() {
	return this->chargeFactor;
}

int ConfigurationMananger::getBufferSize() {
	return this->bufferSize;
}

string ConfigurationMananger::getSequenceName() {
	return this->sequenceName;
}

void ConfigurationMananger::setSequenceName(string sequenceName) {
	this->sequenceName = sequenceName;
}

