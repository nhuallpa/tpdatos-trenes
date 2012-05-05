/*
 * SimpleSecondaryIndex.h
 *
 *  Created on: Oct 21, 2011
 *      Author: carlos
 */

#ifndef SIMPLESECONDARYINDEX_H_
#define SIMPLESECONDARYINDEX_H_

/**
 * Esto se puede hacer mas generico todavia, pero hay que pensarlo y las dos neuronas que tengo
 * se estan peleando entre ellas por irse a dormir.
 *
 * Relaciona 1 id principal con muchos id's
 */
#include <vector>
#include "../utils/types.h"
#include "../entidades/IEntidad.h"
class SimpleSecondaryIndex: public IEntidad {
friend class EntityFactory;
private:
	vector<ID> id_relacionales;
	SimpleSecondaryIndex();

public:
	ID findID(ID);//Arroja ObjectNotFound
	void agregarIdOrdenado(ID idEleccion);
	void removerIdRelacional(ID idRelacional);
	vector<ID> getId_relacionales() const {
		return id_relacionales;
	}

	void setId_relacionales(vector<ID> id_relacionales) {
		this->id_relacionales = id_relacionales;
	}

	virtual ~SimpleSecondaryIndex();

	bool operator==(const SimpleSecondaryIndex& k) { // sobrecarga operador ==
		return this->id == k.id;
	}
	bool operator>(const SimpleSecondaryIndex& k) { // sobrecarga operador >
		return this->id > k.id;
	}
	bool operator<(const SimpleSecondaryIndex& k) { // sobrecarga operador <
		return this->id < k.id;
	}
	virtual std::string serialize();
	virtual void unserialize(std::string &buffer);
	virtual int getDataSize();
};

#endif /* SIMPLESECONDARYINDEX_H_ */
