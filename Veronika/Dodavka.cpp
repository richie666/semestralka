#include "Dodavka.h"
#include "Datum.h"

using namespace Semestralka;

Semestralka::Dodavka::Dodavka(TypMineralnejVody& typMineralnejVody, int mnozstvo, Datum& datumPlnenia, Dodavatel& dodavatel) :
	typMineralnejVody_(&typMineralnejVody), mnozstvo_(mnozstvo), datumPlnenia_(&datumPlnenia), dodavatel_(&dodavatel)
{
}

Semestralka::Dodavka::~Dodavka()
{
}

TypMineralnejVody * Semestralka::Dodavka::getTypMineralnejVody()
{
	return typMineralnejVody_;
}


int Semestralka::Dodavka::getMnozstvo()
{
	return mnozstvo_;
}

Dodavatel * Semestralka::Dodavka::getDodavatel()
{
	return dodavatel_;
}
