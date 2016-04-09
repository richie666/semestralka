#pragma once
#include "Dodavatel.h"
#include "Zakaznik.h"
#include "Predajna.h"
#include "Zakaznik.h"
#include "TypMineralnejVody.h"
#include "Dodavka.h"
#include "Poziadavka.h"
#include "Structures\LinkedList.h"
#include "Structures\Structure.h"
#include "Structures\ArrayList.h"

using namespace std;
using namespace DS;				//kvôli LinkedListu

namespace Semestralka {

	class Velkosklad
	{
	public:
		Velkosklad();
		virtual ~Velkosklad();

		void pridajDodavatela(Dodavatel& dodavatel);
		void pridajZakaznika(Zakaznik& zakaznik);
		void pridajPredajnu(Predajna& predajna, Zakaznik& zakaznik);
		void pridajTypMineralnejVody(TypMineralnejVody& typMineralnejVody);
		void zaevidujDodavkuMineralnychVod(Dodavka& dodavka);
		void zaevidujPoziadavkyZakaznika(Poziadavka& poziadavka);
		void kontrolujPoziadavkyVsMnozstvoNaSklade();
		void vyskladni();
		void odovzdajTovarZakaznikovi();
		void vypisAktualneMnozstvoTypovMVNaSklade();
		Zakaznik* vyhladajOdberatela(Datum& zaciatokObdobia, Datum& koniecObdobia, TypMineralnejVody& typMineralnejVody);
		Zakaznik* vyhladajOdberatela(Datum& zaciatokObdobia, Datum& koniecObdobia, Dodavatel& dodavatel);
		void vypisNezrealizovanePoziadavky();
		Dodavatel* vyhladajDodavatelaSMaxDopytom(Datum& zaciatokObdobia, Datum& koniecObdobia);
		void ulozitDoSuboruAktualnyStavEvidencie();
		void nacitatZoSuboruAktualnyStavEvidencie();

		Dodavatel* getDodavatelZoZoznamu(int index);
		Zakaznik* getZakaznikZoZoznamu(int index);
	

	private:
		LinkedList<Dodavatel*>* zoznamDodavatelov_;
		LinkedList<Zakaznik*>* zoznamZakaznikov_;
		ArrayList<TypMineralnejVody*>* zoznamTypovMineralnychVod_;
		ArrayList<int>* zoznamMnozstvievTypov_;
		LinkedList<Dodavka*>* zoznamDodaviek_;
		LinkedList<Poziadavka*>* zoznamPoziadaviek_;
	};
}