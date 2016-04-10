#include <iostream>
#include <string>
#include "Dodavatel.h"
#include "Velkosklad.h"

using namespace std;
using namespace Semestralka;

void vypisMoznosti() {
	cout << " [1] Pridanie noveho DODAVATELA." << endl;
	cout << " [2] Pridanie noveho ZAKAZNIKA." << endl;
	cout << " [3] Pridanie novej PREDAJNE zakaznika." << endl;
	cout << " [4] Pridanie noveho TYPU mineralnej vody." << endl;
	cout << " [5] Zaevidovanie novej DODAVKY mineralnych vod od dodavatela." << endl;
	cout << " [6] Zaevidovanie POZIADAVKY od zakaznika." << endl;
	cout << " [7] KONTROLA  poziadaviek  od  zakaznikov  a mnozstva  vod  na  sklade." << endl;
	cout << " [8] VYSKLADNENIE." << endl;
	cout << " [9] ODOVZDANIE tovaru zakaznikovi." << endl;
	cout << "[10] Vypisanie aktualneho MNOZSTVA jednotlivych typov vod na sklade." << endl;
	cout << "[11] Vyhladanie odberatela, ktory odobral najvacsie mnozstvo typu vody." << endl;
	cout << "[12] Vyhladanie odberatela, ktory odobral najvacsie mnozstvo vod od dodavatela." << endl;
	cout << "[13] Vypisanie vsetkych poziadaviek, ktore sa nepodarilo zrealizovat." << endl;
	cout << "[14] Vyhladanie dodavatela, po ktoreho vodach bol NAJVACSI DOPYT." << endl;
	cout << "[15] ULOZIT do suboru aktualny stav evidencie." << endl;
	cout << "[16] NACITAT zo suboru aktualny stav evidencie." << endl;
	cout << endl;
	cout << "[17] Zoznam moznosti." << endl;
	cout << "[18] KONIEC" << endl;
	cout << "--------------------------------------------------------------------" << endl;
	cout << "Zvolte si moznost: " << endl;
}

int main() {
	 cout << endl; 
	 cout << "------------------- VELKOSKLAD MINERALNYCH VOD -------------------" << endl;
	 cout << endl;
	 vypisMoznosti();

	 string volba;
	 bool koniec = false;
	 Velkosklad velkosklad; //naoc new? nech zanikne sam ked skonci program. Nemusis volat delete.


	 while (!koniec)
	 {
		 getline(cin, volba);

		 if (volba == "1")
		 {
			cout << endl;
			cout << "-------------------- Pridanie noveho DODAVATELA --------------------" << endl;
			cout << "Obchodny nazov dodavatela:" << endl;
			string nazov;
			getline(cin, nazov);
			cout << "Adresa sidla dodavatela:" << endl;
			string adresa;
			getline(cin, adresa);
			//tieto dva riadky nemaju moc zmysel. Vytvoris object cez new a potom vytvoris klasicky objekt.
			//Dodavatel* dodavatel = new Dodavatel(nazov, adresa);
			//velkosklad->pridajDodavatela(*dodavatel); a navyse ta hodnota dodavatela sa spravi to ze sa vytvori kopia ktoru skopirujes do funkcie pridajDOdavatela a zanikne ti po skonceni tej funkcie. Takze v liste zoznamDodavatelov budes mat adresu na neplatny objekt.
			// uz ti tu len chybalo delete. Kedze som dal delete do destruktora tak:
			
			//Riesenie mozes zmenit funkcny prototyp z pridajDOdavatela(Dodavatel & dodavatel) na pridajDOdavatela(Dodavatel *dodavatel)
			// a potom 
			//velkosklad.pridajDodavatela(new Dodavatel(nazov, adresa));

			//A ja by som to spravil takto. Nech sa mi new vola tam kde ho chcem vymazat.
			velkosklad.pridajDodavatela(nazov, adresa);
		 }

		 else if (volba == "2")
		 {
			 cout << endl;
			 cout << "-------------------- Pridanie noveho ZAKAZNIKA --------------------" << endl;
			 cout << "Obchodny nazov zakaznika:" << endl;
			 string nazov;
			 getline(cin, nazov);
			 cout << "Adresa centraly dodavatela:" << endl;
			 string adresa;
			 getline(cin, adresa);
			 Zakaznik* zakaznik = new Zakaznik(nazov, adresa);
			 velkosklad.pridajZakaznika(*zakaznik);
		 }

		 else if (volba == "3")
		 {
			 cout << endl; 
			 cout << "------------------ Pridanie novej PREDAJNE zakaznika ------------------" << endl;
			 cout << "Zona predajne:" << endl; 
			 string zona;
			 getline(cin, zona);
			 cout << "Adresa predajne:" << endl;
			 string adresa;
			 getline(cin, adresa);
			 Predajna* predajna = new Predajna(stoi(zona), adresa);

			 cout << "Obchodny nazov zakaznika:" << endl;
			 string nazov;
			 getline(cin, nazov);
			 cout << "Adresa centraly dodavatela:" << endl;
			 string adresaZ;
			 getline(cin, adresaZ);
			 Zakaznik* zakaznik = new Zakaznik(nazov, adresaZ);
			 velkosklad.pridajPredajnu(*predajna, *zakaznik);
		 }

		 else if (volba == "4")
		 {
			 cout << endl;
			 cout << "--------------- Pridanie noveho TYPU mineralnej vody ---------------" << endl;
			 cout << "EAN kod: " << endl;
			 string eanKod;
			 getline(cin, eanKod);
			 cout << "Nazov Typu: " << endl;
			 string nazov;
			 getline(cin, nazov);

			 cout << "Nazov dodavatela:" << endl;
			 string nazovD;
			 getline(cin, nazovD);
			 cout << "Adresa dodavatela:" << endl;
			 string adresaD;
			 getline(cin, adresaD);
			 Dodavatel* dodavatel = new Dodavatel(nazovD, adresaD);
			 TypMineralnejVody* typ = new TypMineralnejVody(eanKod, nazov, *dodavatel);
			 velkosklad.pridajTypMineralnejVody(*typ);
		 }

		 else if (volba == "5")
		 {
			 cout << endl;
			 cout << "-------------------- Zaevidovanie novej DODAVKY --------------------" << endl;
			 cout << "Nazov dodavatela:" << endl;
			 string nazovD;
			 getline(cin, nazovD);
			 cout << "Adresa dodavatela:" << endl;
			 string adresaD;
			 getline(cin, adresaD);
			 Dodavatel* dodavatel = new Dodavatel(nazovD, adresaD);

			 cout << "EAN kod: " << endl;
			 string eanKod;
			 getline(cin, eanKod);
			 cout << "Nazov typu: " << endl;
			 string nazovT;
			 getline(cin, nazovT);
			 TypMineralnejVody* typ = new TypMineralnejVody(eanKod, nazovT, *dodavatel);

			 cout << "Mnozstvo: " << endl;
			 string mnozstvo;
			 getline(cin, mnozstvo);
			 

			 cout << "Rok plnenia: " << endl;
			 string rok;
			 getline(cin, rok);
			 cout << "Mesiac plnenia: " << endl;
			 string mesiac;
			 getline(cin, mesiac);
			 cout << "Den plnenia: " << endl;
			 string den;
			 getline(cin, den);
			 Datum* datum = new Datum(stoi(den), stoi(mesiac), stoi(rok));
			 
			 Dodavka* d = new Dodavka(*typ, stoi(mnozstvo), *datum, *dodavatel);
			 velkosklad.zaevidujDodavkuMineralnychVod(*d);
		 }


		 else if (volba == "6")
		 {
			 cout << endl;
			 cout << "------------------- Zaevidovanie novej POZIADAVKY -------------------" << endl;
		 }


		 else if (volba == "7")
		 {
			 cout << endl;
			 cout << "----------------- KONTROLA poziadaviek  od  zakaznikov -----------------" << endl;
		 }


		 else if (volba == "8")
		 {
			 cout << endl;
			 cout << "---------------------------- VYSKLADNENIE ----------------------------" << endl;
		 }


		 else if (volba == "9")
		 {
			 cout << endl;
			 cout << "-------------------- ODOVZDANIE tovaru zakaznikovi --------------------" << endl;
		 }


		 else if (volba == "10")
		 {
			 cout << endl;
			 cout << "---------------- Vypisanie aktualneho MNOZSTVA na sklade ----------------" << endl;
		 }


		 else if (volba == "11")
		 {
			 cout << endl;
			 cout << "--------------- Odberatel s NAJVACSIM MNOZSTVOM typu vody ---------------" << endl;
		 }


		 else if (volba == "12")
		 {
			 cout << endl;
			 cout << "----------- Odberatel s NAJVACSIM MNOZSTVOM vody od dodavatela -----------" << endl;
		 }


		 else if (volba == "13")
		 {
			 cout << endl; 
			 cout << "----------------------- NEZREALIZOVANE POZIADAVKY -----------------------" << endl;
		 }


		 else if (volba == "14")
		 {
			 cout << endl;
			 cout << "---------------- Dodavatel s NAJVACSIM DOPYTOM po vodach ----------------" << endl;
		 }


		 else if (volba == "15")
		 {
			 cout << endl;
			 cout << "-------------------------- ULOZENIE DO SUBORU --------------------------" << endl;
		 }

		 else if (volba == "16")
		 {
			 cout << endl;
			 cout << "------------------------- NACITANIE ZO SUBORU -------------------------" << endl;
		 }

		 else if (volba == "17")
		 {
			 vypisMoznosti();
		 }

		 else if (volba == "18")
		 {
			 koniec = true;
		 }

		 else
		 {
			 cout << "Zadali ste nespravne cislo. Skuste znova." << endl;
		 }
	 }	 
}

