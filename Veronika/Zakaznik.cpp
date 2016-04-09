#include "Zakaznik.h"

using namespace Semestralka;

Semestralka::Zakaznik::Zakaznik(string obchodnyNazov, string adresaCentraly):
	obchodnyNazov_(obchodnyNazov), adresaCentraly_(adresaCentraly), zoznamPredajni_((new LinkedList<Predajna*>()))
{
}

Semestralka::Zakaznik::~Zakaznik()
{
}


/* Kadı zákazník môe ma viacero predajní, ktoré sa odlišujú svojou adresou.*/
void Semestralka::Zakaznik::pridajPredajnu(Predajna& predajna)
{
	bool nachadzaSa = false;
	for (int index = 0; index < zoznamPredajni_->size(); index++)
	{
		if (predajna.getAdresa().compare(zoznamPredajni_->operator[](index)->getAdresa()) == 0) //su rovnake
		{
			nachadzaSa = true;
		}
	}

	if (!nachadzaSa) {
		zoznamPredajni_->add(&predajna);
	}
}

string Semestralka::Zakaznik::getObchodnyNazov()
{
	return obchodnyNazov_;
}

string Semestralka::Zakaznik::getAdresaCentraly()
{
	return adresaCentraly_;
}

LinkedList<Predajna*>* Semestralka::Zakaznik::getZoznamPredajni()
{
	return zoznamPredajni_;
}

/*
void Semestralka::Zakaznik::zaevidujPoziadavku(Poziadavka& poziadavka)
{
	zoznamPoziadaviek_->add(&poziadavka);
}

LinkedList<Poziadavka*>* Semestralka::Zakaznik::getZoznamPoziadaviek()
{
	return zoznamPoziadaviek_;
}*/
