#pragma once
#include "Supplier.h"


class TypeOfMineralWater
{
public:
	TypeOfMineralWater(const char * EAN, const char * name, Supplier & supplier);
	virtual ~TypeOfMineralWater();
	const char * getEAN();
	const char * getName();
	Supplier * getSupplier();
	//void increaseAmount(int amount);
	//void decreaseAmount(int amount);

private:
	const char * EAN_;
	const char * name_;
	Supplier* supplier_;
	//int amount_;

};

