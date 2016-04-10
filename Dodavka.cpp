#include "Dodavka.h"

using namespace Semestralka;

Dodavka::Dodavka(string nazovDodavatela, string eanKod, int pocetKS, string datum) :
	typMineralnejVody_(eanKod), mnozstvo_(pocetKS), datumPlnenia_(datum), dodavatel_(nazovDodavatela)
{
}


Dodavka::~Dodavka()
{
}

string Semestralka::Dodavka::dajTypMineralnejVody()
{
	return typMineralnejVody_;
}

int Semestralka::Dodavka::dajMnozstvo()
{
	return mnozstvo_;
}
