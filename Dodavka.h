#pragma once
#include "TypMineralnaVoda.h"
#include "Datum.h"
#include <string>

namespace Semestralka {
	class Dodavka {

	public:
		Dodavka(TypMineralnaVoda* mineralka, int pocetKS, string datum);
		virtual ~Dodavka();
		TypMineralnaVoda* dajTypMineralnejVody();
		int dajMnozstvo();
	private:
		TypMineralnaVoda* typMineralnejVody_;
		int mnozstvo_;
		string datumPlnenia_;
	};
}
