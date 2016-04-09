#include "TypMineralnaVoda.h"

using namespace Semestralka;

Semestralka::TypMineralnaVoda::TypMineralnaVoda(string eanKod, string nazovMineralky, Dodavatel &dodavatelMineralky) :
	eanKod_(eanKod), nazovMineralky_(nazovMineralky), dodavatelMineralky_(&dodavatelMineralky)
{
}

Semestralka::TypMineralnaVoda::~TypMineralnaVoda()
{
}

string Semestralka::TypMineralnaVoda::dajEAN()
{
	return eanKod_;
}

string Semestralka::TypMineralnaVoda::dajNazov()
{
	return nazovMineralky_;
}

Dodavatel * Semestralka::TypMineralnaVoda::dajDodavatela()
{
	return dodavatelMineralky_;
}
