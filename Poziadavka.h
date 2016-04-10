#pragma once
#include "TypMineralnaVoda.h"
#include "Pobocka.h"
#include "ArrayList.h"
#include <string>

using namespace DS;

namespace Semestralka {
	class Poziadavka {
	public:
		Poziadavka(Pobocka *pobocka, string deadlineDatum);
		virtual ~Poziadavka();
		void pridaTypAMnozstvoMineralky(TypMineralnaVoda * typMineralnejVody, int mnozstvo);
		string dajDatumDodavky();
		//int dajMnozstvoTypuMineralky(TypMineralnaVoda *typMineralnejVody);
		ArrayList<TypMineralnaVoda*> dajListTypyMineralnejVody();
		ArrayList<int> dajListMnozstvo();
		Pobocka* dajPobocku();
	private: 
		ArrayList<TypMineralnaVoda*> typyMineralnejVody_;
		ArrayList<int> mnozstvo_;
		Pobocka* pobocka_;
		string deadlineDatum_;
	};
}

