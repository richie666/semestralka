#include "Dodavka.h"

using namespace Semestralka;

Dodavka::Dodavka(TypMineralnaVoda* mineralka, int pocetKS, string datum) :
typMineralnejVody_(mineralka), mnozstvo_(pocetKS), datumPlnenia_(datum)
{
}


Dodavka::~Dodavka()
{
}

TypMineralnaVoda* Semestralka::Dodavka::dajTypMineralnejVody()
{
	return typMineralnejVody_;
}

int Semestralka::Dodavka::dajMnozstvo()
{
	return mnozstvo_;
}
