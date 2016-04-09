#include "Poziadavka.h"
#include "Datum.h"
#include "Zakaznik.h"
#include <string>


using namespace Semestralka;

Semestralka::Poziadavka::Poziadavka(Predajna& predajna, Datum& deadlineDorucenia, Zakaznik& zakaznik):
	predajna_(&predajna), deadlineDorucenia_(&deadlineDorucenia), zakaznik_(&zakaznik), zoznamTypovMineralnychVod_(new ArrayList<TypMineralnejVody*>()),
	zoznamMnozstiev_(new ArrayList<int>()), zrealizovana_(false)
{
}

Semestralka::Poziadavka::~Poziadavka()
{
}

Datum * Semestralka::Poziadavka::getDeadlineDorucenia()
{
	return deadlineDorucenia_;
}

int Semestralka::Poziadavka::getMnozstvo(TypMineralnejVody& typMineralnejVody)
{
	int i = 0;
	while (typMineralnejVody.getEANkod().compare(zoznamTypovMineralnychVod_->operator[](i)->getEANkod()) != 0)
	{
		i++;
	}
	return zoznamMnozstiev_->operator[](i);
}

Predajna * Semestralka::Poziadavka::getPredajna()
{
	return predajna_;
}

void Semestralka::Poziadavka::pridajTypAMnozstvo(TypMineralnejVody & typMineralnejVody, int mnozstvo)
{
	zoznamTypovMineralnychVod_->add(&typMineralnejVody);
	zoznamMnozstiev_->add(mnozstvo);
}

ArrayList<TypMineralnejVody*>* Semestralka::Poziadavka::getZoznamTypovMineralnychVod()
{
	return zoznamTypovMineralnychVod_;
}

ArrayList<int>* Semestralka::Poziadavka::getZoznamMnozstiev()
{
	return zoznamMnozstiev_;
}

Zakaznik * Semestralka::Poziadavka::getZakaznik()
{
	return zakaznik_;
}

void Semestralka::Poziadavka::nastavZeJeZrealizovana()
{
	zrealizovana_ = true;
}
