#include "Velkosklad.h"

using namespace Semestralka;
using namespace DS;
#include<fstream>


Velkosklad::Velkosklad() :
	listDodavatelov_(), listZakaznikov_(), listTypovMineralnychVod_(),
	listMnozstvaTypovMineralok_(), listPozadovanychMnozstievTypovMineralok_(),
	listDodaviek_(), listNedostatocnychTypovMineralnychVod_(), datum_(), kontajner_(),
	listNezrealizovanychPoziadaviek_()
{
}

Velkosklad::~Velkosklad()
{
	//vymazat dodavatelov pridanych v pridajNovehoDodavatela
	for (Dodavatel *dodavatel : listDodavatelov_)
	{
		delete dodavatel;
	}
	//uvolnit miesto alokovane v liste.
	listDodavatelov_.clear();

	//vymazat zakaznikov pridanych v pridajNovehoZakaznika
	for (Zakaznik *zakaznik : listZakaznikov_)
	{
		delete zakaznik;
	}
	//uvolnit miesto alokovane v liste.
	listZakaznikov_.clear();

	//vymazat typMineralnejVody pridanej v pridajNovyTypMV
	for (TypMineralnaVoda *typMineralnaVoda : listTypovMineralnychVod_)
	{
		delete typMineralnaVoda;
	}
	//uvolnit miesto alokovane v liste.
	listTypovMineralnychVod_.clear();
}

/*Pridanie nového dodávate¾a. Obchodný názov je unikátny.*/
void Semestralka::Velkosklad::pridajNovehoDodavatela(string obchodnyNazov, string adresaSidla)
{
	bool duplicitaNazvu = false;
	//aby objekt existoval v liste aj po skonceni funkcie pridajNovehoDodavatela. Takto je to 100%.
	Dodavatel *dodavatel = new Dodavatel(obchodnyNazov, adresaSidla);
	for (size_t i = 0; i < listDodavatelov_.size(); i++)
	{
		if (dodavatel->dajObchodnyNazov() == listDodavatelov_[i]->dajObchodnyNazov())
		{
			duplicitaNazvu = true;
			cout << "Dodavatel uz existuje!";
			return;
		}
	}
	listDodavatelov_.add(dodavatel);
}

/*Pridanie nového zákazníka.*/
void Semestralka::Velkosklad::pridajNovehoZakaznika(string obchodnyNazov, string adresaCentraly)
{	
	bool duplicitaNazvu = false;
	Zakaznik *zakaznik = new Zakaznik(obchodnyNazov, adresaCentraly);

	for (size_t i = 0; i < listZakaznikov_.size(); i++)
	{
		if (zakaznik->dajObchodnyNazov() == listZakaznikov_[i]->dajObchodnyNazov())
		{
			duplicitaNazvu = true;
			cout << "Zakaznik uz existuje!";
			return;
		}
	}
	listZakaznikov_.add(zakaznik);	
}

void Semestralka::Velkosklad::pridajNovuPredajnu(string zakaznik, int zonaPredajne, string adresaPredajne)
{
	for (size_t i = 0; i < listZakaznikov_.size(); i++)
	{
		if (listZakaznikov_[i]->dajObchodnyNazov() == zakaznik) {
			listZakaznikov_[i]->pridajNovuPobocku(zonaPredajne, adresaPredajne);
			return;
		}
	}
	cout << "Nenaslo Zakaznika";
}

/*Pridanie nového typu minerálnej vody.*/
void Semestralka::Velkosklad::pridajNovyTypMineralky(string eanKod, string nazovMineralky, string dodavatelMineralky)
{
	bool duplicitaTypu = false;

	Dodavatel *hladanyDodavatel = nullptr;
	for (Dodavatel *dodavatel : listDodavatelov_)
	{
		if (dodavatel->dajObchodnyNazov() == dodavatelMineralky)
		{
			hladanyDodavatel = dodavatel;
			break;
		}
	}
	
	if (hladanyDodavatel == nullptr)
	{
		cout << "Neexistujuci dodavatel";
		return;
	}


	for (size_t i = 0; i < listTypovMineralnychVod_.size(); i++)
	{
		if (eanKod == listTypovMineralnychVod_[i]->dajEAN())
		{
			cout << "Typ Mineralnej Vody uz existuje!";
			return;
		}
	}

	TypMineralnaVoda *typMineralnaVoda = new TypMineralnaVoda(eanKod, nazovMineralky, hladanyDodavatel);
	listTypovMineralnychVod_.add(typMineralnaVoda);
}

/*Zaevidovanie novej dodávky minerálnych vôd, ktorá príde od dodávate¾a.*/
void Semestralka::Velkosklad::zaevidovanieNovejDodavky(string eanKod, int pocetKS, string datum)
{
	TypMineralnaVoda *hladanyTypVody = nullptr;
	for (TypMineralnaVoda *typVody : listTypovMineralnychVod_)
	{
		if (typVody->dajEAN() == eanKod)
		{
			Dodavka *dodavka = new Dodavka(typVody, pocetKS, datum);
			listDodaviek_.add(dodavka);
			return;
		}
	}
	cout << "neexistujuci typ vody";
}

int Semestralka::Velkosklad::getIndexOf(TypMineralnaVoda & typMineralnejVody)
{
	return listTypovMineralnychVod_.getIndexOf(&typMineralnejVody);
}

void Semestralka::Velkosklad::zaevidovanieNovejPoziadavky(Poziadavka &poziadavka)
{
	/*time_t cas = time(0);  //ziskaj cas
	struct tm* aktualny = localtime(&cas);
	int rok = aktualny->tm_year + 1900;
	int mesiac = aktualny->tm_mon;
	int den = aktualny->tm_mday;
	*/
	// dorobit kontrolu +2 dni
}
	
void Semestralka::Velkosklad::kontrolaPoziadaviekOdZakaznika()
{
	//TODO nanovo...
	for (size_t i = 0; i < listTypovMineralnychVod_.size(); i++)
	{
		if (listMnozstvaTypovMineralok_[i] < listPozadovanychMnozstievTypovMineralok_[i])
		{
			listNedostatocnychTypovMineralnychVod_.add(listTypovMineralnychVod_[i]);
		}
	}
	set<string> usporiadaneVeci;
	for (size_t i = 0; i < listNedostatocnychTypovMineralnychVod_.size(); i++)
	{
		usporiadaneVeci.insert(string(listNedostatocnychTypovMineralnychVod_[i]->dajDodavatela()->dajObchodnyNazov(), (listNedostatocnychTypovMineralnychVod_[i]->dajDodavatela()->dajObchodnyNazov().length())));
	}
}

void Semestralka::Velkosklad::vypis(const string & tovar)
{
	cout << tovar << endl;
}

void Semestralka::Velkosklad::vyskladnenie()
{
	//TODO nanovo...
	/*bool realizovaniePoziadavky = true;
	for (size_t i = 0; i < listZakaznikov_.size(); i++)
	{
		for (size_t j = 0; j < listZakaznikov_[i]->dajListPoziadaviek().size(); j++)
		{
			if (datum_->jeNasledujuciDenDatumDodavky(listZakaznikov_[i]->dajListPoziadaviek()[j]->dajDatumDodavky()))
			{
				realizovaniePoziadavky = true;
				for (size_t k = 0; k < listZakaznikov_[i]->dajListPoziadaviek()[j]->dajTypyMineralnejVody().size(); k++)
				{
					if (listNedostatocnychTypovMineralnychVod_.getIndexOf(listZakaznikov_[i]->dajListPoziadaviek()[j]->dajTypyMineralnejVody()[k]) == -1)
					{
						realizovaniePoziadavky = false;
					}
				}
				if (realizovaniePoziadavky)
				{
					kontajner_.push(listZakaznikov_[i]->dajListPoziadaviek()[j]->dajPobocku()->dajZonu(), listZakaznikov_[i]->dajListPoziadaviek()[j]);
				}
				else
				{
					listNezrealizovanychPoziadaviek_.add(listZakaznikov_[i]->dajListPoziadaviek()[j]);
					for (size_t l = 0; l < listTypovMineralnychVod_.size(); l++)
					{
						for (size_t k = 0; k < listZakaznikov_[i]->dajListPoziadaviek()[j]->dajTypyMineralnejVody().size(); k++)
						{
							if (strcmp(listZakaznikov_[i]->dajListPoziadaviek()[j]->dajTypyMineralnejVody()[k]->dajEAN(), listTypovMineralnychVod_[l]->dajEAN()) == 0)
							{
								listMnozstvaTypovMineralok_[l] -= listZakaznikov_[i]->dajListPoziadaviek()[j]->dajMnozstvo()[k];
							}
						}
					}
				}
			}
		}
	}*/
}

void Semestralka::Velkosklad::odovzdanieTovaruZakaznikovi()
{
	//TODO nanovo...
	Poziadavka* poziadavka = kontajner_.peek();
	kontajner_.pop();
}

void Semestralka::Velkosklad::vypisAktualneMnozstvoJednotlivychTypovMineralok()
{
	for (size_t i = 0; i < listTypovMineralnychVod_.size(); i++)
	{
		cout << listTypovMineralnychVod_[i]->dajDodavatela()->dajObchodnyNazov() << "  " << listTypovMineralnychVod_[i]->dajNazov() << " " << listMnozstvaTypovMineralok_[i] << endl;
	}
}

void Semestralka::Velkosklad::vypisNezrealizovatelnychPoziadaviek()
{
	/*for (size_t i = 0; i < listNezrealizovanychPoziadaviek_.size(); i++)
	{
		for (size_t j = 0; j < listNezrealizovanychPoziadaviek_[i]->dajListTypyMineralnejVody().size(); j++)
		{
			//vytvorit dajZakaznik, ziskat jeho obchodny nazov a zistit aky typ mineralnej vody je nezrealizovatelna poziadavka ziskat meno
			// asi? cout << listNezrealizovanychPoziadaviek_[i]->dajZakaznika()->dajObchodnyNazov() << "  " << listNezrealizovanychPoziadaviek_[i]->dajListTypyMineralnejVody[j]->dajNazovMineralky() << endl;
		}
	}*/
}

void Semestralka::Velkosklad::ulozitDoSuboru()
{
	remove(subor_s_evidenciou.c_str());
	ofstream evidencia(subor_s_evidenciou.c_str());

	//zapis dodavatelov:
	evidencia << novyDodavatel << endl;
	for (Dodavatel *dodavatel : listDodavatelov_)
		evidencia << dodavatel->toString() << endl;
}

void Semestralka::Velkosklad::nacitatZoSuboru()
{
	ifstream evidencia(subor_s_evidenciou.c_str());
	if (evidencia.is_open())
	{
		string typ;
		getline(evidencia,typ);
		while (!evidencia.eof())
		{
			switch (atoi(typ.c_str()))
			{
			case 1:
			{
				string obchodnyNazov;
				string adresaDodavatela;
				pridajNovehoDodavatela(obchodnyNazov, adresaDodavatela);
				break;
			}
			default:
			{
				throw runtime_error("Chyba citanej databazy. Neocakavany vstup");
				break;
			}
			}
		}
	}
}
