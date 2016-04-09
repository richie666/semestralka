#include "Zakaznik.h"

using namespace Semestralka;

Semestralka::Zakaznik::Zakaznik(string obchodnyNazov, string adresaCentraly) :
	obchodnyNazov_(obchodnyNazov), adresaCentraly_(adresaCentraly)
{
}

Semestralka::Zakaznik::~Zakaznik()
{
}

void Zakaznik::pridajNovuPobocku(Pobocka &pobocka)
{
	bool duplicitaNazvu = false;
	for (size_t i = 0; i < listPobociek_.size(); i++)
	{
		if (pobocka.dajAdresu() == listPobociek_[i]->dajAdresu())
		{
			duplicitaNazvu = true;
		}
	}

	if (!duplicitaNazvu)
	{
		listPobociek_.add(&pobocka);
	}
}

void Zakaznik::pridajPoziadavku(Poziadavka poziadavka)
{
	listPoziadaviek_.add(&poziadavka);
}

LinkedList<Poziadavka*> Zakaznik::dajListPoziadaviek()
{
	return listPoziadaviek_;
}
