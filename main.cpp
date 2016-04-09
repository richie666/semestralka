#include<iostream>
#include<time.h>
#include<string>

using namespace std;
/*
struct tm * DatePlusDays(struct tm* date, int days)
{
	const time_t ONE_DAY = 24 * 60 * 60;

	// Seconds since start of epoch
	time_t date_seconds = mktime(date) + (days * ONE_DAY);

	// Update caller's date
	// Use localtime because mktime converts to UTC so may change date
	//return (*localtime)(&date_seconds);
}*/


enum Vstup{
	novyDodavatel=0,
	novyZakaznik,
	novaPredajna,
	novyTypMineralnychVod,
	novaDodavkaMineralnychVod,
	zaevidovaniePoziadavkyOdZakaznika,
	kontrolaPoziadaviekOdZakaznikovAMnozstvaVodNaSklade,
	vyskladnenie,
	odovzdanieTovaruZakaznikovi,
	vypisanieAktualnehoMnozstvaJednotlivychTypobMVnaSklade,
	vyhladanieOdberatelaCOnajMnozstvoKonkrTMV,
	vyhladanieOdberatelaCOnajMnozstvoMVodKonkrDod,
	vypisanieVestkychPoziadOdVsetOdberKtSaNepodariloZreal,
	vyhladanieDodavPoKtMVbolZaDaneCOnajDopyt,
	ulozenieDoSuboruAktStavEv,
	nacitanieZoSuboruAktStavEv,
	vypisHlM,
	koniec,
	moznosti
};
string vypis[] = {
	std::to_string(novyDodavatel) + ". Pridaj noveho Dodavatela\n",
	std::to_string(novyZakaznik) + ". Pridaj noveho Zakaznika\n",
	std::to_string(novaPredajna) + ". Pridanie novej Predajne konkretneho Zakaznika\n",
	std::to_string(novyTypMineralnychVod) + ". Pridanie noveho Typu Mineralnych Vod\n",
	std::to_string(novaDodavkaMineralnychVod) + ". Zaevidovanie novej Dodavky Mineralnych Vod\n",
	std::to_string(zaevidovaniePoziadavkyOdZakaznika) + ". Zaevidovanie Poziadavky od Zakaznika\n",
	std::to_string(kontrolaPoziadaviekOdZakaznikovAMnozstvaVodNaSklade) + ". Kontrola Poziadaviek od Zakaznikov a Mnozstva Vod na Sklade\n",
	std::to_string(vyskladnenie) + ". Vyskladnenie\n",
	std::to_string(odovzdanieTovaruZakaznikovi) + ". Odovzdanie Tovaru Zakaznikovi\n",
	std::to_string(vypisanieAktualnehoMnozstvaJednotlivychTypobMVnaSklade) + ". Vypisanie aktualneho Mnozstva jednotlivych Typov Mineralnych Vod na Sklade\n",
	std::to_string(vyhladanieOdberatelaCOnajMnozstvoKonkrTMV) + ". Vyhladanie Odberatela, ktory za dane Casove Obdobie odobral najvacsie Mnozstvo konkretneho Typu Mineralnej Vody\n",
	std::to_string(vyhladanieOdberatelaCOnajMnozstvoMVodKonkrDod) + ". Vyhladanie Odberatela, ktory za dane Casove Obdobie odobral najvacsie Mnozstvo Mineralnych Vod od konkretneho Dodavatela\n",
	std::to_string(vypisanieVestkychPoziadOdVsetOdberKtSaNepodariloZreal) + ". Vypisanie vsetkych poziadaviek od vsetkych Odberatelov, ktore sa nepodarilo zrealizovat\n",
	std::to_string(vyhladanieDodavPoKtMVbolZaDaneCOnajDopyt) + ". Vyhladanie Dodavatela, po ktoreho Mineralnych Vodach bol za dane casove obdobie najvacsi dopyt\n",
	std::to_string(ulozenieDoSuboruAktStavEv) + ". Ulozenie do suboru aktualny stav evidencie\n",
	std::to_string(nacitanieZoSuboruAktStavEv) + ". Nacitanie zo suboru aktualny stav evidencie\n",
	std::to_string(vypisHlM) + ". Vypis Hlavneho Menu\n",
	std::to_string(koniec) + ". Koniec\n",
	"*** Zadajte cislo moznosti! ***\n"
};

void Vypis() {
	for (int i = 0; i < 19; i++){
		cout << vypis[i];
	}
}
/*void Vypis() {
	cout << "1. Pridaj noveho Dodavatela\n";
	cout << "2. Pridaj noveho Zakaznika\n";
	cout << "3. Pridanie novej Predajne konkretneho Zakaznika\n";
	cout << "4. Pridanie noveho Typu Mineralnych Vod\n";
	cout << "5. Zaevidovanie novej Dodavky Mineralnych Vod\n";
	cout << "6. Zaevidovanie Poziadavky od Zakaznika\n";
	cout << "7. Kontrola Poziadaviek od Zakaznikov a Mnozstva Vod na Sklade\n";
	cout << "8. Vyskladnenie\n";
	cout << "9. Odovzdanie Tovaru Zakaznikovi\n";
	cout << "10. Vypisanie aktualneho Mnozstva jednotlivych Typov Mineralnych Vod na Sklade\n";
	cout << "11. Vyhladanie Odberatela, ktory za dane Casove Obdobie odobral najvacsie Mnozstvo konkretneho Typu Mineralnej Vody\n";
	cout << "12. Vyhladanie Odberatela, ktory za dane Casove Obdobie odobral najvacsie Mnozstvo Mineralnych Vod od konkretneho Dodavatela\n";
	cout << "13. Vypisanie vsetkych poziadaviek od vsetkych Odberatelov, ktore sa nepodarilo zrealizovat\n";
	cout << "14. Vyhladanie Dodavatela, po ktoreho Mineralnych Vodach bol za dane casove obdobie najvacsi dopyt\n";
	cout << "15. Ulozenie do suboru aktualny stav evidencie\n";
	cout << "16. Nacitanie zo suboru aktualny stav evidencie\n";
	cout << "17. Vypis Hlavneho Menu\n";
	cout << "0. Koniec\n";
	cout << "*** Zadajte cislo moznosti! ***\n";
}*/

int main() {
	int i;
	bool bezi = true;
	Vypis();

	while (bezi)
	{
		cin >> i;
        switch (i)
		{
			case novyDodavatel:
				cout << vypis[novyDodavatel];
				bezi = false;
				break;
			case novyZakaznik:
				cout << vypis[novyZakaznik];
				bezi = false;
				break;
			case novaPredajna:
				cout << vypis[novaPredajna];
				bezi = false;
				break;
			case novyTypMineralnychVod:
				cout << vypis[novyTypMineralnychVod];
				bezi = false;
				break;
			case novaDodavkaMineralnychVod:
				cout << vypis[novaDodavkaMineralnychVod];
				bezi = false;
				break;
			case zaevidovaniePoziadavkyOdZakaznika:
				cout << vypis[zaevidovaniePoziadavkyOdZakaznika];
				bezi = false;
				break;
			case kontrolaPoziadaviekOdZakaznikovAMnozstvaVodNaSklade:
				cout << vypis[kontrolaPoziadaviekOdZakaznikovAMnozstvaVodNaSklade];
				bezi = false;
				break;
			case vyskladnenie:
				cout << vypis[vyskladnenie];
				bezi = false;
				break;
			case odovzdanieTovaruZakaznikovi:
				cout << vypis[odovzdanieTovaruZakaznikovi];
				bezi = false;
				break;
			case vypisanieAktualnehoMnozstvaJednotlivychTypobMVnaSklade:
				cout << vypis[vypisanieAktualnehoMnozstvaJednotlivychTypobMVnaSklade];
				bezi = false;
				break;
			case vyhladanieOdberatelaCOnajMnozstvoKonkrTMV:
				cout << vypis[vyhladanieOdberatelaCOnajMnozstvoKonkrTMV];
				bezi = false;
				break;
			case vyhladanieOdberatelaCOnajMnozstvoMVodKonkrDod:
				cout << vypis[vyhladanieOdberatelaCOnajMnozstvoMVodKonkrDod];
				bezi = false;
				break;
			case vypisanieVestkychPoziadOdVsetOdberKtSaNepodariloZreal:
				cout << vypis[vypisanieVestkychPoziadOdVsetOdberKtSaNepodariloZreal];
				bezi = false;
				break;
			case vyhladanieDodavPoKtMVbolZaDaneCOnajDopyt:
				cout << vypis[vyhladanieDodavPoKtMVbolZaDaneCOnajDopyt];
				bezi = false;
				break;
			case ulozenieDoSuboruAktStavEv:
				cout << vypis[ulozenieDoSuboruAktStavEv];
				bezi = false;
				break;
			case nacitanieZoSuboruAktStavEv:
				cout << vypis[nacitanieZoSuboruAktStavEv];
				bezi = false;
				break;
			case vypisHlM:
				cout << vypis[vypisHlM];
				bezi = false;
				break;
			case koniec:
				cout << vypis[koniec];
				bezi = false;
				break;
			default:
				continue;
				break;
		}/*
		if (i == "0") {
			bezi = false;
		}
		else if (i == "1") {
			cout << "1. Pridaj noveho Dodavatela\n";
			cout << "Zadaj Obchodny Nazov Dodavatela: \n";
			string obchodnyNazov;
			getline(cin, obchodnyNazov);
			getline(cin, obchodnyNazov);
			cout << "Zadali ste Obchodny Nazov Dodavatela: " << obchodnyNazov << " " << endl;

			cout << "Zadaj Adresu Sidla Dodavatela: \n";
			string adresaDodavatela;
			getline(cin, adresaDodavatela);
			cout << "Zadali ste Adresu Sidla Dodavatela: " << adresaDodavatela << "\n";
		}
		else if (i == "2") {
			cout << "2. Pridaj noveho Zakaznika\n";
			cout << "Zadaj Obchodny Nazov Dodavatela: \n";
			string obchodnyNazov;
			getline(cin, obchodnyNazov);
			getline(cin, obchodnyNazov);
			cout << "Zadali ste Obchodny Nazov Zakaznika: " << obchodnyNazov << "\n";

			cout << "Zadaj Adresu Centraly Zakaznika: \n";
			string adresaCentraly;
			getline(cin, adresaCentraly);
			cout << "Zadali ste Adresu Centraly Zakaznika: " << adresaCentraly << "\n";
		}
		else if (i == "3") {
			cout << "3. Pridanie novej Predajne konkretneho Zakaznika\n";
			cout << "Zadaj Zonu Predajne Zakaznika: \n";
			string zonaPredajne;
			getline(cin, zonaPredajne);
			getline(cin, zonaPredajne);
			cout << "Zadali ste Zonu Predajne Zakaznika: " << zonaPredajne << "\n";

			cout << "Zadaj Adresu Predajne Zakaznika: \n";
			string adresaPredajne;
			getline(cin, adresaPredajne);
			cout << "Zadali ste Adresu Predajne Zakaznika: " << adresaPredajne << "\n";
		}
		else if (i == "4") {
			cout << "4. Pridanie noveho Typu Mineralnych Vod\n";
			cout << "Zadaj EANkod Mineralnej Vody: \n";
			string eanKod;
			getline(cin, eanKod);
			getline(cin, eanKod);
			cout << "Zadali ste EANkod Mineralnej Vody: " << eanKod << "\n";

			cout << "Zadaj Nazov Mineralnej Vody: \n";
			string nazovMineralky;
			getline(cin, nazovMineralky);
			cout << "Zadali ste Nazov Mineralnej Vody: " << nazovMineralky << "\n";

			cout << "Zadaj Dodavatela Mineralnej Vody: \n";
			string dodavatelMineralky;
			getline(cin, dodavatelMineralky);
			cout << "Zadali ste Dodavatela Mineralnej Vody: " << dodavatelMineralky << "\n";
		}
		else if (i == "5") {
			cout << "5. Zaevidovanie novej Dodavky Mineralnych Vod\n";
			cout << "Zadaj Typ Mineralnej Vody: \n";
			string typMineralnejVody;
			getline(cin, typMineralnejVody);
			getline(cin, typMineralnejVody);
			cout << "Zadali ste Typ Mineralnej Vody: " << typMineralnejVody << "\n";

			cout << "Zadaj Mnozstvo: \n";
			string mnozstvo;
			getline(cin, mnozstvo);
			cout << "Zadali ste Mnozstvo: " << mnozstvo << "\n";

			cout << "Zadaj Datum Plnenia: \n";
			string datumPlnenia;
			getline(cin, datumPlnenia);
			cout << "Zadali ste Datum Plnenia: " << datumPlnenia << "\n";

			cout << "Zadaj Dodavatela: \n";
			string dodavatel;
			getline(cin, dodavatel);
			cout << "Zadali ste Dodavatela: " << dodavatel << "\n";
		}
		else if (i == "6") {
			cout << "6. Zaevidovanie Poziadavky od Zakaznika\n";
			cout << "Zadaj Pobocku Zakaznika: \n";
			string pobocka;
			getline(cin, pobocka);
			getline(cin, pobocka);
			cout << "Zadali ste Pobocku Zakaznika: " << pobocka << "\n";

			cout << "Zadaj Datum Spotreby: \n";
			string deadlineDatum;
			getline(cin, deadlineDatum);
			cout << "Zadali ste Datum Spotreby: " << deadlineDatum << "\n";
		}
		else if (i == "7") {
			cout << "7. Kontrola Poziadaviek od Zakaznikov a Mnozstva Vod na Sklade\n";
			//TODO Po vykonan� tejto oper�cie sa vyp�e zoznam t�ch miner�lnych v�d, ktor�ch mno�stvo na sklade je men�ie
			//ako je mno�stvo po�adovan� z�kazn�kmi.�daje musia by� vyp�san� v abecednom porad� pod�a n�zvu dod�vate�a
			//a n�zvu miner�lnej vody.Vo v�pise mus� by� aj ch�baj�ce mno�stvo jednotliv�ch miner�lnych v�d.
		}
		else if (i == "8") {
			cout << "8. Vyskladnenie\n";
			//TODO V tomto pr�pade je nutn� pripravi� kontajner miner�lnych v�d, ktor�	musia by� doru�en� nasleduj�ci de�.
			//Doru�ovanie prebieha pomocou auta, ktor� rozv�a vody k jednotliv�m z�kazn�kom v porad� pod�a ich zon�cie,
			//t.j.na dne kontajnera musia by� vody ktor�, je potrebn� doru�i� do predajn� v z�ne k, nad nimi sa nach�dzaj� vody,
			//ktor� sa doru�ia do predajn� v z�ne k - 1, ..., na vrchu s� vody, ktor� sa doru�ia do predajn� v z�ne 1.
			//Pri vyskladnen� je �alej nutn� zoh�adni� d�tum plnenia, t.j.vysklad�uj� sa miner�lne vody s najskor��m d�tumom plnenia.
			//V pr�pade po�iadavky, ktor� sa ned� zrealizova�(t.j.po�aduje sa viac miner�lnej vody, ako je jej mno�stvo na sklade),
			//sa t�to ozna�� za nezrealizovan�.Vyskladnen� miner�lne vody je nutn� odp�sa� zo skladu.
		}
		else if (i == "9") {
			cout << "9. Odovzdanie Tovaru Zakaznikovi\n";
			//TODO Z kontajnera, ktor� sa nach�dza v aute, sa odoberie	najvrchnej�ia polo�ka.T�mto d�jde k zrealizovaniu konkr�tnej po�iadavky,
			//t.j.v tomto	okam�iku sa po�iadavka ozna�� za zrealizovan�.
		}
		else if (i == "10") {
			cout << "10. Vypisasnie aktualneho Mnozstva jednotlivych Typov Mineralnych Vod na Sklade\n";
			//TODO �daje musia by� vyp�san� v abecednom porad� pod�a n�zvu dod�vate�a a n�zvu miner�lnej vody.
		}
		else if (i == "11") {
			cout << "11. Vyhladanie Odberatela, ktory za dane Casove Obdobie odobral najvacsie Mnozstvo konkretneho Typu Mineralnej Vody\n";
			//TODO
		}
		else if (i == "12") {
			cout << "12. Vyhladanie Odberatela, ktory za dane Casove Obdobie odobral najvacsie Mnozstvo Mineralnych Vod od konkretneho Dodavatela\n";
			//TODO
		}
		else if (i == "13") {
			cout << "13. Vypisanie vsetkych poziadaviek od vsetkych Odberatelov, ktore sa nepodarilo zrealizovat\n";
			//TODO
		}
		else if (i == "14") {
			cout << "14. Vyhladanie Dodavatela, po ktoreho Mineralnych Vodach bol za dane casove obdobie najvacsi dopyt\n";
		}
		else if (i == "15") {
			cout << "15. Ulozenie do suboru aktualny stav evidencie\n";
			//TODO
		}
		else if (i == "16") {
			cout << "16. Nacitanie zo suboru aktualny stav evidencie\n";
			//TODO
		}
		else if (i == "17") {
			cout << "17. Vypis Hlavneho Menu\n";
			Vypis();
		}
		else if (i == "99") {
			continue;
		}
		else {
			cout << "Zadali ste neplatny vstup!\n";
		}
		i = "99";*/
	}
	return 0;
}
