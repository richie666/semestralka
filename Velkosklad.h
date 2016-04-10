#pragma once

#include "LinkedList.h"
#include "ArrayList.h"
#include "Dodavatel.h"
#include "Zakaznik.h"
#include "Pobocka.h"
#include "TypMineralnaVoda.h"
#include "Dodavka.h"
#include <string>
#include <cstring>
#include <iostream>
#include <set>
#include <algorithm>
#include "Datum.h"
#include "PriorityQueue_Heap.h";
#include "Poziadavka.h"

using namespace DS;
using namespace std;

namespace Semestralka {
	class Velkosklad {
		
	public:
		Velkosklad();
		virtual ~Velkosklad();
		void pridajNovehoDodavatela(string obchodnyNazov, string adresaSidla);
		void pridajNovehoZakaznika(string obchodnyNazov, string adresaCentraly);
		void pridajNovuPredajnu(string zakaznik, int zonaPredajne, string adresaPredajne);
		void pridajNovyTypMineralky(string eanKod, string nazovMineralky, string dodavatelMineralky);
		void zaevidovanieNovejDodavky(Dodavka &dodavka);
		int getIndexOf(TypMineralnaVoda &typMineralnejVody);
		void zaevidovanieNovejPoziadavky(Poziadavka &poziadavka);
		void kontrolaPoziadaviekOdZakaznika();
		void vypis(const string &vec);
		void vyskladnenie();
		void odovzdanieTovaruZakaznikovi();
		void vypisAktualneMnozstvoJednotlivychTypovMineralok();
		//Zakaznik* vyhladanieOdberatelaSnajvacsimMnozstvom(time_t zaciatokObdobia, time_t koniecObdobia, TypMineralnaVoda& typMineralnejVody);
		//Zakaznik* vyhladanieOdberatelaSnajvacsimMnozstvom(time_t zaciatokObdobia, time_t koniecObdobia, Dodavatel& dodavatel);
		void vypisNezrealizovatelnychPoziadaviek();
		//Dodavatel* vyhladanieDodavatelaZaNajvacsiDopyt(time_t zaciatokObdobia, time_t koniecObobia);
		void ulozitDoSuboru();
		void nacitatZoSuboru();

	private:
		LinkedList<Dodavatel*> listDodavatelov_;
		LinkedList<Zakaznik*> listZakaznikov_;
		ArrayList<TypMineralnaVoda*> listTypovMineralnychVod_;
		ArrayList<int> listMnozstvaTypovMineralok_;
		ArrayList<int> listPozadovanychMnozstievTypovMineralok_;
		LinkedList<Dodavka*> listDodaviek_;
		LinkedList<TypMineralnaVoda*> listNedostatocnychTypovMineralnychVod_;
		Datum* datum_;
		PriorityQueue_Heap<Poziadavka*> kontajner_;
		LinkedList<Poziadavka*> listNezrealizovanychPoziadaviek_;
	};
}