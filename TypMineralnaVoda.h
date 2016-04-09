#pragma once
#include "Dodavatel.h"
#include<string>

using namespace std;

namespace Semestralka {
	class TypMineralnaVoda {

	public:
		TypMineralnaVoda(string eanKod, string nazovMineralky, Dodavatel &dodavatelMineralky);
		virtual ~TypMineralnaVoda();
		string dajEAN();
		string dajNazov();
		Dodavatel* dajDodavatela();
	private:
		string eanKod_;
		string nazovMineralky_;
		Dodavatel* dodavatelMineralky_;
	};
}