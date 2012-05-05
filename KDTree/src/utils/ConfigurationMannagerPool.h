/*
 * ConfigurationMannagerPool.h
 *
 *  Created on: Oct 1, 2011
 *      Author: carlos
 */

#ifndef CONFIGURATIONMANNAGERPOOL_H_
#define CONFIGURATIONMANNAGERPOOL_H_
#include <string>
#include <map>
#include "ConfigurationMananger.h"
typedef map<string, ConfigurationMananger*> STRING2CONFIGURATIONMANAGER;
class ConfigurationMannagerPool {
private:
	static STRING2CONFIGURATIONMANAGER instances;
	static ConfigurationMananger* getInstance(string nameIndex);
public:
	string static getStructureName(ESTRUCTURAS estuctura);
	static ConfigurationMananger* getInstance(ESTRUCTURAS name);
	ConfigurationMannagerPool();
	virtual ~ConfigurationMannagerPool();
};

#endif /* CONFIGURATIONMANNAGERPOOL_H_ */
