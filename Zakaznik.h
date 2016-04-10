#pragma once
#include<string>
#include<iostream>
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
		void pridajNovuPobocku(int zonaPredajne, string adresaPredajne);
		string dajObchodnyNazov();
		string adresaCentraly();
		LinkedList<Pobocka*> & dajListPobociek();

	private:
		string obchodnyNazov_;
		string adresaCentraly_;
		LinkedList<Pobocka*> listPobociek_;
	};
}