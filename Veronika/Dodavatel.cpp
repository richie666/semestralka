#include "Dodavatel.h"

using namespace Semestralka;

Semestralka::Dodavatel::Dodavatel(string obchodnyNazov, string adresaSidla) :
	obchodnyNazov_(obchodnyNazov), adresaSidla_(adresaSidla)
{
	
}

Semestralka::Dodavatel::~Dodavatel()
{
}

string Semestralka::Dodavatel::getObchodnyNazov()
{
	return obchodnyNazov_;
}

string Semestralka::Dodavatel::getAdresaSidla()
{
	return adresaSidla_;
}
