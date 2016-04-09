#include "TypMineralnejVody.h"

using namespace Semestralka;

Semestralka::TypMineralnejVody::TypMineralnejVody(string EANkod, string nazov, Dodavatel& dodavatel):
	EANkod_(EANkod), nazov_(nazov), dodavatel_(&dodavatel)
{
}

Semestralka::TypMineralnejVody::~TypMineralnejVody()
{
}

string Semestralka::TypMineralnejVody::getEANkod()
{
	return EANkod_;
}

string Semestralka::TypMineralnejVody::getNazov()
{
	return nazov_;
}

Dodavatel * Semestralka::TypMineralnejVody::getDodavatel()
{
	return dodavatel_;
}


