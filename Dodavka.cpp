#include "Dodavka.h"

using namespace Semestralka;

Dodavka::Dodavka(TypMineralnaVoda &typMineralnejVody, int mnozstvo, Datum &datumPlnenia, Dodavatel &dodavatel) :
	typMineralnejVody_(&typMineralnejVody), mnozstvo_(mnozstvo), datumPlnenia_(&datumPlnenia), dodavatel_(&dodavatel)
{
}


Dodavka::~Dodavka()
{
}

TypMineralnaVoda * Semestralka::Dodavka::dajTypMineralnejVody()
{
	return typMineralnejVody_;
}

int Semestralka::Dodavka::dajMnozstvo()
{
	return mnozstvo_;
}
