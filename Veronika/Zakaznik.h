#pragma once
#include "Predajna.h"
//#include "Poziadavka.h"
#include "Structures\LinkedList.h"
#include "Structures\Structure.h"
#include "Structures\ArrayList.h"
#include <string>

using namespace std;
using namespace DS;

namespace Semestralka {
	class Zakaznik
	{
	public:
		Zakaznik(string obchodnyNazov, string adresaCentraly);
		virtual ~Zakaznik();
		void pridajPredajnu(Predajna& predajna);
		string getObchodnyNazov();
		string getAdresaCentraly();
		LinkedList<Predajna*>* getZoznamPredajni();
		//void zaevidujPoziadavku(Poziadavka& poziadavka);
		//LinkedList<Poziadavka*>* getZoznamPoziadaviek();

	private:
		string obchodnyNazov_;
		string adresaCentraly_;
		LinkedList<Predajna*>* zoznamPredajni_;
		//LinkedList<Poziadavka*>* zoznamPoziadaviek_;
	};
}

