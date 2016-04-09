#pragma once
#include<string>
#include "Pobocka.h"
#include "LinkedList.h"
#include "ArrayList.h"
#include "Poziadavka.h"

using namespace DS;
using namespace std;

namespace Semestralka {
	class Zakaznik {

	public:
		Zakaznik(string obchodnyNazov, string adresaCentraly);
		~Zakaznik();
		void pridajNovuPobocku(Pobocka &pobocka);
		void pridajPoziadavku(Poziadavka poziadavka);
		LinkedList<Poziadavka*> dajListPoziadaviek();

	private:
		string obchodnyNazov_;
		string adresaCentraly_;
		LinkedList<Pobocka*> listPobociek_;
		LinkedList<Poziadavka*> listPoziadaviek_;
	};
}