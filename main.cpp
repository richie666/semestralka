#include<iostream>
#include<time.h>
#include<string>
#include"Array.h"
#include"Velkosklad.h"

using namespace std;
using namespace DS;
using namespace Semestralka;
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

const size_t pocetMoznosti = 18;

Array<string> vypis(pocetMoznosti);
void initVypis()
{
	vypis[0] = (to_string(novyDodavatel) + ". Pridaj noveho Dodavatela\n");
	vypis[1] = (to_string(novyZakaznik) + ". Pridaj noveho Zakaznika\n");
	vypis[2] = (to_string(novaPredajna) + ". Pridanie novej Predajne konkretneho Zakaznika\n");
	vypis[3] = (to_string(novyTypMineralnychVod) + ". Pridanie noveho Typu Mineralnych Vod\n");
	vypis[4] = (to_string(novaDodavkaMineralnychVod) + ". Zaevidovanie novej Dodavky Mineralnych Vod\n");
	vypis[5] = (to_string(zaevidovaniePoziadavkyOdZakaznika) + ". Zaevidovanie Poziadavky od Zakaznika\n");
	vypis[6] = (to_string(kontrolaPoziadaviekOdZakaznikovAMnozstvaVodNaSklade) + ". Kontrola Poziadaviek od Zakaznikov a Mnozstva Vod na Sklade\n");
	vypis[7] = (to_string(vyskladnenie) + ". Vyskladnenie\n");
	vypis[8] = (to_string(odovzdanieTovaruZakaznikovi) + ". Odovzdanie Tovaru Zakaznikovi\n");
	vypis[9] = (to_string(vypisanieAktualnehoMnozstvaJednotlivychTypobMVnaSklade) + ". Vypisanie aktualneho Mnozstva jednotlivych Typov Mineralnych Vod na Sklade\n");
	vypis[10] = (to_string(vyhladanieOdberatelaCOnajMnozstvoKonkrTMV) + ". Vyhladanie Odberatela, ktory za dane Casove Obdobie odobral najvacsie Mnozstvo konkretneho Typu Mineralnej Vody\n");
	vypis[11] = (to_string(vyhladanieOdberatelaCOnajMnozstvoMVodKonkrDod) + ". Vyhladanie Odberatela, ktory za dane Casove Obdobie odobral najvacsie Mnozstvo Mineralnych Vod od konkretneho Dodavatela\n");
	vypis[12] = (to_string(vypisanieVestkychPoziadOdVsetOdberKtSaNepodariloZreal) + ". Vypisanie vsetkych poziadaviek od vsetkych Odberatelov, ktore sa nepodarilo zrealizovat\n");
	vypis[13] = (to_string(vyhladanieDodavPoKtMVbolZaDaneCOnajDopyt) + ". Vyhladanie Dodavatela, po ktoreho Mineralnych Vodach bol za dane casove obdobie najvacsi dopyt\n");
	vypis[14] = (to_string(ulozenieDoSuboruAktStavEv) + ". Ulozenie do suboru aktualny stav evidencie\n");
	vypis[15] = (to_string(nacitanieZoSuboruAktStavEv) + ". Nacitanie zo suboru aktualny stav evidencie\n");
	vypis[16] = (to_string(vypisHlM) + ". Vypis Hlavneho Menu\n");
	vypis[17] = (to_string(koniec) + ". Koniec\n");
	"*** Zadajte cislo moznosti! ***\n";
}

void Vypis() {
	for (int i = 0; i < vypis.size(); i++){
		cout << vypis[i];
	}
}

int main() {
	initVypis();
	bool bezi = true;
	Vypis();
	Velkosklad *velkosklad = new Velkosklad();
	while (bezi)
	{
		cout << "Zadaj cislo";
		string vstup;
		getline(cin, vstup);
		switch (atoi(vstup.c_str()))
		{
		case novyDodavatel:
		{
			cout << vypis[novyDodavatel];
			cout << "1. Pridaj noveho Dodavatela\n";
			cout << "Zadaj Obchodny Nazov Dodavatela: \n";
			string obchodnyNazov;
			getline(cin, obchodnyNazov);
			cout << "Zadali ste Obchodny Nazov Dodavatela: " << obchodnyNazov << " " << endl;

			cout << "Zadaj Adresu Sidla Dodavatela: \n";
			string adresaDodavatela;
			getline(cin, adresaDodavatela);
			cout << "Zadali ste Adresu Sidla Dodavatela: " << adresaDodavatela << "\n";
			velkosklad->pridajNovehoDodavatela(obchodnyNazov, adresaDodavatela);
			break;
		}
		case novyZakaznik: {
				cout << vypis[novyZakaznik];
				cout << "Zadaj Obchodny Nazov Dodavatela: \n";
				string obchodnyNazov;
				getline(cin, obchodnyNazov);
				cout << "Zadali ste Obchodny Nazov Zakaznika: " << obchodnyNazov << "\n";

				cout << "Zadaj Adresu Centraly Zakaznika: \n";
				string adresaCentraly;
				getline(cin, adresaCentraly);
				cout << "Zadali ste Adresu Centraly Zakaznika: " << adresaCentraly << "\n";
				velkosklad->pridajNovehoZakaznika(obchodnyNazov, adresaCentraly);
				break;
			}
			case novaPredajna: {
				cout << vypis[novaPredajna];
				cout << "Zadaj Zakaznika: \n";
				string zakaznik;
				getline(cin, zakaznik);
				cout << "Zadali ste Zakaznika: " << zakaznik << "\n";

				cout << "Zadaj Zonu Predajne Zakaznika: \n";
				string zonaPredajne;
				getline(cin, zonaPredajne);
				int zonaPredajneInt = atoi(zonaPredajne.c_str());
				if (zonaPredajneInt == 0)
				{
					cout << "neplatny vstup";
				}
				cout << "Zadali ste Zonu Predajne Zakaznika: " << zonaPredajne << "\n";				

				cout << "Zadaj Adresu Predajne Zakaznika: \n";
				string adresaPredajne;
				getline(cin, adresaPredajne);
				cout << "Zadali ste Adresu Predajne Zakaznika: " << adresaPredajne << "\n";
				velkosklad->pridajNovuPredajnu(zakaznik, zonaPredajneInt, adresaPredajne);
				break;
			}
			case novyTypMineralnychVod: {
				cout << vypis[novyTypMineralnychVod];
				cout << "Zadaj EANkod Mineralnej Vody: \n";
				string eanKod;
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
				velkosklad->pridajNovyTypMineralky(eanKod, nazovMineralky, dodavatelMineralky);
				break;
			}
			case novaDodavkaMineralnychVod: {
				cout << vypis[novaDodavkaMineralnychVod];
				cout << "Zadaj Dodavatela Mineralnej Vody: \n";
				string dodavatel;
				getline(cin, dodavatel);
				cout << "Zadali ste Dodavatela Mineralnej Vody: " << dodavatel << "\n";

				cout << "Zadaj Typ Mineralnej Vody(eanKod): \n";
				string eanKod;
				getline(cin, eanKod);
				cout << "Zadali ste Typ Mineralnej Vody(eanKod): " << eanKod << "\n";

				cout << "Zadaj Mnozstvo: \n";
				string pocetKS;
				getline(cin, pocetKS);
				int pocetKsInt = atoi(pocetKS.c_str());
				if (pocetKsInt == 0)
				{
					cout << "neplatny vstup";
				}
				cout << "Zadali ste Mnozstvo: " << pocetKS << "\n";

				cout << "Zadaj Datum Plnenia: \n";
				string datumPlnenia;
				getline(cin, datumPlnenia);
				cout << "Zadali ste Datum Plnenia: " << datumPlnenia << "\n";
				velkosklad->zaevidovanieNovejDodavky(dodavatel, eanKod, pocetKsInt, datumPlnenia);
				break;
			}
			case zaevidovaniePoziadavkyOdZakaznika: {
				cout << vypis[zaevidovaniePoziadavkyOdZakaznika];
				cout << "Zadaj Pobocku Zakaznika: \n";
				string pobocka;
				getline(cin, pobocka);
				getline(cin, pobocka);
				cout << "Zadali ste Pobocku Zakaznika: " << pobocka << "\n";

				cout << "Zadaj Datum Spotreby: \n";
				string deadlineDatum;
				getline(cin, deadlineDatum);
				cout << "Zadali ste Datum Spotreby: " << deadlineDatum << "\n";
				bezi = false;
				break;
			}
			case kontrolaPoziadaviekOdZakaznikovAMnozstvaVodNaSklade: {
				cout << vypis[kontrolaPoziadaviekOdZakaznikovAMnozstvaVodNaSklade];
				//TODO Po vykonaní tejto operácie sa vypíše zoznam tých minerálnych vôd, ktorých množstvo na sklade je menšie
				//ako je množstvo požadované zákazníkmi.Údaje musia by vypísané v abecednom poradí pod¾a názvu dodávate¾a
				//a názvu minerálnej vody.Vo výpise musí by aj chýbajúce množstvo jednotlivých minerálnych vôd.
				bezi = false;
				break;
			}
			case vyskladnenie: {
				cout << vypis[vyskladnenie];
				//TODO V tomto prípade je nutné pripravi kontajner minerálnych vôd, ktoré	musia by doruèené nasledujúci deò.
				//Doruèovanie prebieha pomocou auta, ktoré rozváža vody k jednotlivým zákazníkom v poradí pod¾a ich zonácie,
				//t.j.na dne kontajnera musia by vody ktoré, je potrebné doruèi do predajní v zóne k, nad nimi sa nachádzajú vody,
				//ktoré sa doruèia do predajní v zóne k - 1, ..., na vrchu sú vody, ktoré sa doruèia do predajní v zóne 1.
				//Pri vyskladnení je ïalej nutné zoh¾adni dátum plnenia, t.j.vyskladòujú sa minerálne vody s najskorším dátumom plnenia.
				//V prípade požiadavky, ktorá sa nedá zrealizova(t.j.požaduje sa viac minerálnej vody, ako je jej množstvo na sklade),
				//sa táto oznaèí za nezrealizovanú.Vyskladnené minerálne vody je nutné odpísa zo skladu.
				bezi = false;
				break;
			}
			case odovzdanieTovaruZakaznikovi: {
				cout << vypis[odovzdanieTovaruZakaznikovi];
				//TODO Z kontajnera, ktorý sa nachádza v aute, sa odoberie	najvrchnejšia položka.Týmto dôjde k zrealizovaniu konkrétnej požiadavky,
				//t.j.v tomto	okamžiku sa požiadavka oznaèí za zrealizovanú.
				bezi = false;
				break;
			}
			case vypisanieAktualnehoMnozstvaJednotlivychTypobMVnaSklade: {
				cout << vypis[vypisanieAktualnehoMnozstvaJednotlivychTypobMVnaSklade];
				//TODO Údaje musia by vypísané v abecednom poradí pod¾a názvu dodávate¾a a názvu minerálnej vody.
				bezi = false;
				break;
			}
			case vyhladanieOdberatelaCOnajMnozstvoKonkrTMV: {
				cout << vypis[vyhladanieOdberatelaCOnajMnozstvoKonkrTMV];
				//TODO
				bezi = false;
				break;
			}
			case vyhladanieOdberatelaCOnajMnozstvoMVodKonkrDod: {
				cout << vypis[vyhladanieOdberatelaCOnajMnozstvoMVodKonkrDod];
				//TODO
				bezi = false;
				break;
			}
			case vypisanieVestkychPoziadOdVsetOdberKtSaNepodariloZreal: {
				cout << vypis[vypisanieVestkychPoziadOdVsetOdberKtSaNepodariloZreal];
				//TODO
				bezi = false;
				break;
			}
			case vyhladanieDodavPoKtMVbolZaDaneCOnajDopyt: {
				cout << vypis[vyhladanieDodavPoKtMVbolZaDaneCOnajDopyt];
				//TODO
				bezi = false;
				break;
			}
			case ulozenieDoSuboruAktStavEv: {
				cout << vypis[ulozenieDoSuboruAktStavEv];
				velkosklad->ulozitDoSuboru();
				//TODO
				break;
			}
			case nacitanieZoSuboruAktStavEv: {
				cout << vypis[nacitanieZoSuboruAktStavEv];
				delete velkosklad;
				velkosklad = new Velkosklad();
				velkosklad->nacitatZoSuboru();
				//TODO
				break;
			}
			case vypisHlM: {
				cout << vypis[vypisHlM];
				Vypis();
				bezi = false;
				break;
			}
			case koniec: {
				cout << vypis[koniec];
				bezi = false;
				break;
			}
			default: {
				cout << "Zadali ste neplatny vstup!";
				continue;
				break;
			}
		}
	}
	delete velkosklad;
	return 0;
}
