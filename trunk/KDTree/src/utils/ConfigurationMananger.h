/*
 * ConfigurationMananger.h
 * Clase singleton donde se setean los parámetros de configuración
 *
 */

#ifndef CONFIGURATIONMANANGER_H_
#define CONFIGURATIONMANANGER_H_

#include "types.h"
#include <string>
#include "ConfigFile.h"
#include <map>
using namespace std;

class ConfigurationMananger {
private:
	int minUnderflowSizeTree;
	int maxNodeLoadForInsert;
	//prefijo que parametriza el tipo
	string prefixName;
	/** instancia del Singleton. */


	/** Almacena el porcentaje util de un nodo */
	ChargeFactor chargeFactor;

	/** Define el los bloques cabecera. */
	int bufferSize;

	/**
	 * Tamaño del buffer del arbol
	 */
	int bufferSizeTree;

	/**
	 * Tamaño minimo del registro que puede tener.
	 */
	int minRecordSizeTree;

	/**
	 * Tamaño maximo del registro que puede tener.
	 */
	int maxRecordSizeTree;

	string filename;
	string sequenceName;
	string sequenceFilename;
	/**
	 * Archivo de configuracion
	 */
	ConfigFile *configFile;

public:

	ConfigurationMananger(string name);
	//Destructor
	virtual ~ConfigurationMananger();

	/**
	 * Devuelve la unica instancia del singleton.
	 */
	static ConfigurationMananger* getInstance();
	/**
	 * ConfigurationManager para una estructura en particular
	 */
	static ConfigurationMananger* getInstance(string name);
	ChargeFactor getChargeFactor();
	int getMaxNodeLoadForInsert();
	/**
	 * Tamano que tiene el buffer, Nodo, o bloque
	 */
	int getBufferSize();

	int getBufferSizeTree();

	/**
	 * Devuelve el tama�o minimo de underflow permitido
	 *  50% tama�o del bloque -  el tama�o maximo del registro
	 */
	int getMinUnderflowSizeTree();

	int getMinRecordSizeTree();

	int getMaxRecordSizeTree();
    string getFilename() const
    {
        return filename;
    }

    void setFilename(string filename)
    {
        this->filename = filename;
    }

    string getSequenceName();
    void setSequenceName(string sequenceName);
};

#endif /* CONFIGURATIONMANANGER_H_ */
