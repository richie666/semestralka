#pragma once
#include "TypMineralnejVody.h"
#include "Predajna.h"
#include "Zakaznik.h"
#include "Datum.h"
#include "Structures\ArrayList.h"
#include <string>

using namespace std;
using namespace DS;

namespace Semestralka {
	
	class Poziadavka
	{
	public:
		Poziadavka(Predajna& predajna, Datum& deadlineDorucenia, Zakaznik& zakaznik);
		virtual ~Poziadavka();
		Datum* getDeadlineDorucenia();
		int getMnozstvo(TypMineralnejVody& typMineralnejVody);
		Predajna* getPredajna();
		void pridajTypAMnozstvo(TypMineralnejVody& typMineralnejVody, int mnozstvo);
		ArrayList<TypMineralnejVody*>* getZoznamTypovMineralnychVod();
		ArrayList<int>* getZoznamMnozstiev();
		Zakaznik* getZakaznik();
		void nastavZeJeZrealizovana();

	private:
		Predajna* predajna_; 
		Datum* deadlineDorucenia_;
		Zakaznik* zakaznik_;
		ArrayList<TypMineralnejVody*>* zoznamTypovMineralnychVod_;
		ArrayList<int>* zoznamMnozstiev_;
		bool zrealizovana_;
	};
}

