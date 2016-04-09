#include "Pobocka.h"

using namespace Semestralka;

Semestralka::Pobocka::Pobocka(int zonaPredajne, string adresaPredajne) :
	zonaPredajne_(zonaPredajne), adresaPredajne_(adresaPredajne)
{
}

Semestralka::Pobocka::~Pobocka()
{
}

string Pobocka::dajAdresu()
{
	return adresaPredajne_;
}

int Pobocka::dajZonu()
{
	return zonaPredajne_;
}
