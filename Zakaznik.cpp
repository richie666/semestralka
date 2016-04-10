#include "Zakaznik.h"

using namespace Semestralka;

Semestralka::Zakaznik::Zakaznik(string obchodnyNazov, string adresaCentraly) :
	obchodnyNazov_(obchodnyNazov), adresaCentraly_(adresaCentraly)
{
}

Semestralka::Zakaznik::~Zakaznik()
{
	//vymazat predajne pridanych v pridajPredajnu
	for (Pobocka *pobocka : listPobociek_)
	{
		delete pobocka;
	}
	//uvolnit miesto alokovane v liste.
	listPobociek_.clear();
}

void Zakaznik::pridajNovuPobocku(int zonaPredajne, string adresaPredajne)
{
	bool duplicitaAdresy = false;
	Pobocka *pobocka = new Pobocka(zonaPredajne, adresaPredajne);
	for (size_t i = 0; i < listPobociek_.size(); i++)
	{
		if (pobocka->dajAdresu() == listPobociek_[i]->dajAdresu())
		{
			duplicitaAdresy = true;
			cout << "Pobocka na danej adrese uz existuje!";
		}
	}
	listPobociek_.add(pobocka);
}

LinkedList<Pobocka*> &Zakaznik::dajListPobociek()
{
	return listPobociek_;
}

string Semestralka::Zakaznik::dajObchodnyNazov()
{
	return obchodnyNazov_;
}

string Semestralka::Zakaznik::adresaCentraly()
{
	return adresaCentraly_;
}
