#include "Predajna.h"


Semestralka::Predajna::Predajna(int zona, string adresa):
	zona_(zona), adresa_(adresa)
{
}

Semestralka::Predajna::~Predajna()
{
}

string Semestralka::Predajna::getAdresa()
{
	return adresa_;
}

int Semestralka::Predajna::getZona()
{
	return zona_;
}

/*void Semestralka::Predajna::pridajZakaznika(Zakaznik & zakaznik)
{
		zoznamZakaznikov_->add(&zakaznik);
}*/
