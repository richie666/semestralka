#pragma once
#include "TypMineralnaVoda.h"
#include "Datum.h"
#include <string>

namespace Semestralka {
	class Dodavka {

	public:
		Dodavka(TypMineralnaVoda &typMineralnejVody, int mnozstvo, Datum &datumPlnenia, Dodavatel &dodavatel);
		virtual ~Dodavka();
		TypMineralnaVoda* dajTypMineralnejVody();
		int dajMnozstvo();
	private:
		TypMineralnaVoda* typMineralnejVody_;
		int mnozstvo_;
		Datum* datumPlnenia_;
		Dodavatel* dodavatel_;
	};
}
