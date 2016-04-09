#include "Velkosklad.h"

using namespace Semestralka;
using namespace DS;


Velkosklad::Velkosklad() :
	listDodavatelov_(), listZakaznikov_(), listTypovMineralnychVod_(),
	listMnozstvaTypovMineralok_(), listPozadovanychMnozstievTypovMineralok_(),
	listDodaviek_(), listNedostatocnychTypovMineralnychVod_(), datum_(), kontajner_(),
	listNezrealizovanychPoziadaviek_()
{
}

Velkosklad::~Velkosklad()
{
}

/*Pridanie nového dodávate¾a. Obchodný názov je unikátny.*/
void Semestralka::Velkosklad::pridajNovehoDodavatela(Dodavatel &dodavatel)
{
	bool duplicitaNazvu = false;
	for (size_t i = 0; i < listDodavatelov_.size(); i++)
	{
		if (dodavatel.dajObchodnyNazov() == listDodavatelov_[i]->dajObchodnyNazov())
		{
			duplicitaNazvu = true;
		}
	}

	if (!duplicitaNazvu)
	{
		listDodavatelov_.add(&dodavatel);
	}
}

/*Pridanie nového zákazníka.*/
void Semestralka::Velkosklad::pridajNovehoZakaznika(Zakaznik &zakaznik)
{
	listZakaznikov_.add(&zakaznik);
}

/*Pridanie novej predajne konkrétneho zákazníka.*/
void Semestralka::Velkosklad::pridajNovuPredajnu(Pobocka &pobocka, Zakaznik &zakaznik)
{
	zakaznik.pridajNovuPobocku(pobocka);
}

/*Pridanie nového typu minerálnej vody.*/
void Semestralka::Velkosklad::pridajNovyTypMineralky(TypMineralnaVoda &typMineralnejVody)
{
	listTypovMineralnychVod_.add(&typMineralnejVody);
}

/*Zaevidovanie novej dodávky minerálnych vôd, ktorá príde od dodávate¾a.*/
void Semestralka::Velkosklad::zaevidovanieNovejDodavky(Dodavka &dodavka)
{
	listDodaviek_.add(&dodavka);
	listMnozstvaTypovMineralok_[getIndexOf(*dodavka.dajTypMineralnejVody())] += dodavka.dajMnozstvo();
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
}

void Semestralka::Velkosklad::nacitatZoSuboru()
{
}
