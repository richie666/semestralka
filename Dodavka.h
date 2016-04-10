#pragma once
#include "TypMineralnaVoda.h"
#include "Datum.h"
#include <string>

namespace Semestralka {
	class Dodavka {

	public:
		Dodavka(string nazovDodavatela, string eanKod, int pocetKS, string datum);
		virtual ~Dodavka();
		string dajTypMineralnejVody();
		int dajMnozstvo();
	private:
		string typMineralnejVody_;
		int mnozstvo_;
		string datumPlnenia_;
		string dodavatel_;
	};
}
