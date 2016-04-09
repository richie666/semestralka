#include "TypeOfMineralWater.h"



TypeOfMineralWater::TypeOfMineralWater(const char * EAN, const char * name, Supplier & supplier) :
	EAN_(EAN), name_(name), supplier_(&supplier)
{
}

TypeOfMineralWater::~TypeOfMineralWater()
{
}

const char * TypeOfMineralWater::getEAN()
{
	return EAN_;
}

const char * TypeOfMineralWater::getName()
{
	return name_;
}

Supplier * TypeOfMineralWater::getSupplier()
{
	return supplier_;
}


