#pragma once
#include "TypMineralnejVody.h"
#include "Datum.h"
#include <string>

namespace Semestralka {

	class Dodavka
	{
	public:
		Dodavka(TypMineralnejVody& typMineralnejVody, int mnozstvo, Datum& datumPlnenia, Dodavatel& dodavatel);
		virtual ~Dodavka();
		TypMineralnejVody* getTypMineralnejVody();
		int getMnozstvo();
		Dodavatel* getDodavatel();

	private:
		TypMineralnejVody* typMineralnejVody_;
		int mnozstvo_;
		Datum* datumPlnenia_;
		Dodavatel* dodavatel_;
	};
}

