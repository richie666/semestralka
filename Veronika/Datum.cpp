#include "Datum.h"

using namespace Semestralka;

Semestralka::Datum::Datum(int den, int mesiac, int rok) :
	den_(den), mesiac_(mesiac), rok_(rok)
{
}

Semestralka::Datum::~Datum()
{
}

int Semestralka::Datum::getDen()
{
	return den_;
}

int Semestralka::Datum::getMesiac()
{
	return mesiac_;
}

int Semestralka::Datum::getRok()
{
	return rok_;
}

bool Semestralka::Datum::jeMensiAko(int den, int mesiac, int rok)
{
	bool jeMensi = false;

	if (rok_ <= rok)	
	{
		if (mesiac_ <= mesiac)
		{
			if (den_ < den)
			{
				jeMensi = true;
			}
		}
	}

	return jeMensi;
}
