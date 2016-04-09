#include "Poziadavka.h"

using namespace Semestralka;

Poziadavka::Poziadavka(Pobocka &pobocka, string deadlineDatum) :
	pobocka_(&pobocka), deadlineDatum_(deadlineDatum)
{
}
Poziadavka::~Poziadavka()
{
}

void Semestralka::Poziadavka::pridaTypAMnozstvoMineralky(TypMineralnaVoda & typMineralnejVody, int mnozstvo)
{
	typyMineralnejVody_.add(&typMineralnejVody);
	mnozstvo_.add(mnozstvo);
}

string Semestralka::Poziadavka::dajDatumDodavky()
{
	return deadlineDatum_;
}

int Semestralka::Poziadavka::dajMnozstvoTypuMineralky(TypMineralnaVoda & typMineralnejVody)
{
	int i = 0;
	while (typMineralnejVody.dajEAN() != typyMineralnejVody_[i]->dajEAN())
	{
		i++;
	}
	return mnozstvo_[i];
}

ArrayList<TypMineralnaVoda*> Semestralka::Poziadavka::dajListTypyMineralnejVody()
{
	return typyMineralnejVody_;
}

ArrayList<int> Semestralka::Poziadavka::dajListMnozstvo()
{
	return mnozstvo_;
}

Pobocka * Semestralka::Poziadavka::dajPobocku()
{
	return pobocka_;
}