#include "Dodavatel.h"

Semestralka::Dodavatel::Dodavatel(string obchodnyNazov, string adresaSidla) :
	obchodnyNazov_(obchodnyNazov), adresaSidla_(adresaSidla)
{
}

Semestralka::Dodavatel::~Dodavatel()
{
}

string Semestralka::Dodavatel::dajObchodnyNazov()
{
	return obchodnyNazov_;
}

string Semestralka::Dodavatel::dajAdresuSidla()
{
	return adresaSidla_;
}

string Semestralka::Dodavatel::toString()
{
	return obchodnyNazov_ + "\r\n" + adresaSidla_;
}