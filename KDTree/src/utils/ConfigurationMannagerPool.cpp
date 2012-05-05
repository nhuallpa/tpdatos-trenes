/*
 * ConfigurationMannagerPool.cpp
 *
 *  Created on: Oct 1, 2011
 *      Author: carlos
 */

#include "ConfigurationMannagerPool.h"
#include "../utils/const.h"
#include "../utils/StringUtils.h"
#include "../bplustree/exceptions/ProgramException.h"

STRING2CONFIGURATIONMANAGER ConfigurationMannagerPool::instances;
ConfigurationMannagerPool::ConfigurationMannagerPool() {
	// TODO Auto-generated constructor stub

}
ConfigurationMananger* ConfigurationMannagerPool::getInstance(ESTRUCTURAS estuctura){
	string name=ConfigurationMannagerPool::getStructureName(estuctura);

	return ConfigurationMannagerPool::getInstance(name);
}
string ConfigurationMannagerPool::getStructureName(ESTRUCTURAS estuctura){
	string name="";
	switch (estuctura) {
		default:
			name="";
			string mensaje;
			mensaje.append("no se configuro el configuration mannager para ");
			mensaje.append(StringUtils::convertIntToString(estuctura));
			throw ProgramException(mensaje);
			break;
	}

	return name;
}

ConfigurationMananger* ConfigurationMannagerPool::getInstance(string name) {
	STRING2CONFIGURATIONMANAGER::iterator mapIterator;
	mapIterator = ConfigurationMannagerPool::instances.find(name);
	if (mapIterator != ConfigurationMannagerPool::instances.end()) {
		return (*mapIterator).second;
	} else {
		ConfigurationMananger* configMananger = new ConfigurationMananger(name);
		ConfigurationMannagerPool::instances.insert(
				STRING2CONFIGURATIONMANAGER::value_type(name, configMananger));
		return configMananger;
	}
}
ConfigurationMannagerPool::~ConfigurationMannagerPool() {
	//TODO eliminar de la memoria todas las instancias
}
