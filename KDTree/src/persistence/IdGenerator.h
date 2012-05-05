/*
 * IdGenerator.h
 *
 *  Created on: 02/10/2011
 *      Author: Barrera Oro, Rafael
 */

#ifndef __IDGENERATOR_H__
#define __IDGENERATOR_H__

#define MAX_LINE_LENGTH 256
#define SEQ_FILE_SEPARATOR ":"

#include <cstddef> /* include más simple que pude encontrar es para disponer del define NULL */
#include <string>
#include <map>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include "../utils/StringUtils.h"

using namespace std;

/**
 * Clase encargada de administrar las secuencias de ids autoincrementales (implementado mediante patrón GoF Singleton)
 *
 * ejemplo de uso:
 *
 * cout << IdGenerator::getInstance()->getNextId("votos") << endl;
 * cout << IdGenerator::getInstance()->getNextId("candidatos") << endl;
 *
 * IdGenerator::getInstance()->load();
 *
 * cout << IdGenerator::getInstance()->getNextId("votos") << endl;
 * cout << IdGenerator::getInstance()->getNextId("candidatos") << endl;
 *
 * IdGenerator::getInstance()->save("secuencias2.txt");
 *
 * IdGenerator::getInstance()->reset();
 *
 * cout << IdGenerator::getInstance()->getNextId("votos") << endl;
 * cout << IdGenerator::getInstance()->getNextId("candidatos") << endl;
 *
 * IdGenerator::getInstance()->load("secuencias2.txt");
 *
 * cout << IdGenerator::getInstance()->getNextId("votos") << endl;
 * cout << IdGenerator::getInstance()->getNextId("candidatos") << endl;
 *
 * //destruyo
 * IdGenerator::destroyInstance();
 */
class IdGenerator {

public:

	/**
	 * Destructor. Destruye el mapa de secuencias
	 */
	virtual ~IdGenerator();

	/**
	 * Devuelve la única instancia del IdGenerator (si es la primera vez que se pide, se crea antes)
	 */
	static IdGenerator* getInstance();

	/**
	 * Destruye la única instancia del IdGenerator. Este método es necesario por tratarse de un singleton (solamente se puede destruir la instancia manualmente)
	 */
	static void destroyInstance();

	/**
	 * Devuelve el próximo id de la secuencia cuyo nombre se recibió
	 */
	int getNextId(const string& sequenceName);

	/**
	 * Devuelve el próximo id de la secuencia sin incrementar la misma
	 */
	int peekNextId(const string& sequenceName);

	/**
	 * Resetea la secuencia
	 */
	void reset(const string& seqName);

	/**
	 * Resetea todas las secuencias
	 */
	void reset();

	/**
	 * Persiste el estado de las secuencias en el archivo cuyo nombre es recibido, devuelve true o false de acuerdo a si se pudo llevar a cabo la operación.
	 */
	bool save(const string& seqFileName);
	/**
	 * Persiste las secuencias en el archivo por defecto
	 */
	bool save();
	/**
	 * Carga las secuencias del archivo cuyo nombre es recibido, devuelve true o false de acuerdo a si se pudo llevar a cabo la operación.
	 */
	bool load(const string& seqFileName);

	/**
	 * Carga las secuencias del archivo por defecto
	 */
	bool load();

private:

	//mapa donde el nombre de la secuencia es la clave y el valor guardado es el último id
	map<string, int>* secuencias;

	/**
	 * Constructor (privado por tratarse de una implementación de Singleton). Inicializa el mapa de últimos ids obtenidos (secuencias) y captura el archivo para cargar y persistir las secuencias
	 */
	IdGenerator();

	/**
	 * Puntero a la única instancia
	 */
	static IdGenerator* instance;

	/**
	 * Parsea el archivo de secuencias y carga los últios ids devueltos por cada una en el mapa de secuencias
	 */
	void parseSeqFile(ifstream* seqFile);

	/**
	 * Persiste los últimos ids entregados por cada secuencia
	 */
	void saveSequences(ofstream* seqFile);
};

#endif /* IDGENERATOR_H_ */
