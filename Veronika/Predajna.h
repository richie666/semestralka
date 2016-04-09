#pragma once
#include <string>
//#include "Zakaznik.h"

using namespace std;

namespace Semestralka {
	class Predajna
	{
	public:
		Predajna(int zona, string adresa);
		virtual ~Predajna();
		string getAdresa();
		int getZona();
		//void pridajZakaznika(Zakaznik& zakaznik);

	private:
		int zona_;
		string adresa_;
		//LinkedList<Zakaznik*>* zoznamZakaznikov_;
	};
}

