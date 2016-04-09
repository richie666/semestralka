#include "Velkosklad.h"
#include "Dodavatel.h"
#include "Zakaznik.h"
#include "Dodavka.h"
#include "Datum.h"
#include "Poziadavka.h"
#include <iostream>
#include <ctime>
#include <string>

using namespace Semestralka;
using namespace std;
using namespace DS;

Semestralka::Velkosklad::Velkosklad() :
	zoznamDodavatelov_(new LinkedList<Dodavatel*>()), zoznamZakaznikov_(new LinkedList<Zakaznik*>()), 
	zoznamTypovMineralnychVod_(new ArrayList<TypMineralnejVody*>()), zoznamMnozstvievTypov_(new ArrayList<int>()), 
	zoznamDodaviek_(new LinkedList<Dodavka*>()), zoznamPoziadaviek_(new LinkedList<Poziadavka*>())
{
}

Semestralka::Velkosklad::~Velkosklad()
{
}



/*Pridanie  nov�ho  dod�vate�a.  Dod�vate�  je  charakterizovan�  obchodn�m  n�zvom
a adresou s�dla. Obchodn� n�zov je unik�tny.
*/
void Semestralka::Velkosklad::pridajDodavatela(Dodavatel& dodavatel)
{	
	bool nachadzaSa = false;
	for (size_t index = 0; index < zoznamDodavatelov_->size(); index++)
	{
		if (dodavatel.getObchodnyNazov().compare(zoznamDodavatelov_->operator[](index)->getObchodnyNazov()) == 0) //su rovnake
		{
			nachadzaSa = true;
			cout << "Dodavatel " << dodavatel.getObchodnyNazov() << " sa uz v zozname nachadza." << endl;
			break;
		}
	}
	
	if (!nachadzaSa) {
		zoznamDodavatelov_->add(&dodavatel);
		cout << "Dodavatel " << dodavatel.getObchodnyNazov() << " pridany." << endl;
	}
}


/*Pridanie  nov�ho  z�kazn�ka, ktor�  je  charakterizovan�  obchodn�m  n�zvom  a adresou centr�ly.*/
void Semestralka::Velkosklad::pridajZakaznika(Zakaznik& zakaznik)
{	
	bool nachadzaSa = false;
	for (size_t i = 0; i < zoznamZakaznikov_->size(); i++)
	{
		if ((zoznamZakaznikov_->operator[](i)->getObchodnyNazov().compare(zakaznik.getObchodnyNazov()) == 0)
			&& (zoznamZakaznikov_->operator[](i)->getAdresaCentraly().compare(zakaznik.getAdresaCentraly()) == 0))
			{
				nachadzaSa = true; 
				cout << "Zakaznik " << zakaznik.getObchodnyNazov() << " sa uz v zozname nachadza." << endl;
				break;
			}
	}

	if (!nachadzaSa) {
		zoznamZakaznikov_->add(&zakaznik);
		cout << "Zakaznik " << zakaznik.getObchodnyNazov() << " pridany." << endl;
	}
}


/*Pridanie  novej  predajne  konkr�tneho  z�kazn�ka.*/
void Semestralka::Velkosklad::pridajPredajnu(Predajna& predajna, Zakaznik& zakaznik)
{
	bool zakaznikExistuje = false;

	for (size_t i = 0; i < zoznamZakaznikov_->size(); i++)
	{
		if (zoznamZakaznikov_->operator[](i)->getObchodnyNazov().compare(zakaznik.getObchodnyNazov()) == 0)
		{
			if (zoznamZakaznikov_->operator[](i)->getAdresaCentraly().compare(zakaznik.getAdresaCentraly()) == 0)
			{
				zakaznikExistuje = true;
				zoznamZakaznikov_->operator[](i)->pridajPredajnu(predajna);
				cout << "Zakaznikovi " << zakaznik.getObchodnyNazov() << " bola pridana predajna." << endl;
				break;
			}
		}
	}

	if (!zakaznikExistuje)
	{
		cout << "Zakaznik " << zakaznik.getObchodnyNazov() << " nie je v zozname." << endl;
	}
}

/*Pridanie  nov�ho  typu  miner�lnej  vody.*/
void Semestralka::Velkosklad::pridajTypMineralnejVody(TypMineralnejVody& typMineralnejVody)
{
	bool nachadzaSa = false;
	for (size_t i = 0; i < zoznamTypovMineralnychVod_->size(); i++)
	{
		if (zoznamTypovMineralnychVod_->operator[](i)->getEANkod().compare(typMineralnejVody.getEANkod()) == 0)
		{
			nachadzaSa = true;
			cout << "Typ mineralnej vody " << typMineralnejVody.getEANkod() << " sa uz v zozname nachadza." << endl;
			break;
		}
	}

	if (!nachadzaSa)
	{
		zoznamTypovMineralnychVod_->add(&typMineralnejVody);
		zoznamMnozstvievTypov_->add(0);
		cout << "Typ mineralnej vody " << typMineralnejVody.getEANkod() << " bol pridany." << endl;
	}
}


/*Zaevidovanie  novej dod�vky miner�lnych v�d, ktor� pr�de od dod�vate�a.*/
void Semestralka::Velkosklad::zaevidujDodavkuMineralnychVod(Dodavka& dodavka)
{
	zoznamDodaviek_->add(&dodavka);
	
	bool typSaNachadza = false;
	for (size_t x = 0; x < zoznamTypovMineralnychVod_->size(); x++)
	{
		if (zoznamTypovMineralnychVod_->operator[](x)->getEANkod().compare(dodavka.getTypMineralnejVody()->getEANkod()) == 0)
		{
			typSaNachadza = true;
			break;
		}
	}
	
	bool dodavatelSaNachadza = false;
	for (int i = 0; i < zoznamDodavatelov_->size(); i++)
	{
		if (zoznamDodavatelov_->operator[](i)->getObchodnyNazov().compare(dodavka.getDodavatel()->getObchodnyNazov()) == 0)
		{
			dodavatelSaNachadza = true;
			cout << "Dodavka od evidovaneho dodavatela bola zaevidovana." << endl;
			break;
		}
	}

	if (!dodavatelSaNachadza)
	{
		Dodavatel& dodavatel = *dodavka.getDodavatel();
		zoznamDodavatelov_->add(&dodavatel);
		cout << "Dodavka bola zaevidovana spolu s novym dodavatelom." << endl;
	}

	if (!typSaNachadza)
	{
		TypMineralnejVody& typ = *dodavka.getTypMineralnejVody();
		zoznamTypovMineralnychVod_->add(&typ);
		zoznamMnozstvievTypov_->add(dodavka.getMnozstvo());
		cout << "Novy typ bol pridany spolu s mnozstvom." << endl;
	}


	for (size_t m = 0; m < zoznamTypovMineralnychVod_->size(); m++)
	{
		if (zoznamTypovMineralnychVod_->operator[](m)->getEANkod().compare(dodavka.getTypMineralnejVody()->getEANkod()) == 0)
		{
			zoznamMnozstvievTypov_->operator[](m) += dodavka.getMnozstvo();
		}
	}
}


/*Zaevidovanie  po�iadavky od z�kazn�ka.V pr�pade, �e d�tum doru�enia je men�� ako 
�aktu�lny d�tum + 2 dni�, po�iadavka sa nezaeviduje.*/
void Semestralka::Velkosklad::zaevidujPoziadavkyZakaznika(Poziadavka& poziadavka)
{
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	int rok = now->tm_year + 1900;
	int mesiac = now->tm_mon;
	int den = now->tm_mday;
	
	if (!poziadavka.getDeadlineDorucenia()->jeMensiAko(den + 2, mesiac, rok))	//nie je mensi
	{
		zoznamPoziadaviek_->add(&poziadavka);

		bool zakaznikSaNachadza = false;
		bool predajnaSaNachadza = false;
		for (size_t i = 0; i < zoznamZakaznikov_->size(); i++)
		{
			if (zoznamZakaznikov_->operator[](i)->getObchodnyNazov().compare(poziadavka.getZakaznik()->getObchodnyNazov()) == 0)
			{
				zakaznikSaNachadza = true;
				for (size_t z = 0; z < zoznamZakaznikov_->operator[](i)->getZoznamPredajni()->size(); z++)
				{
					if (zoznamZakaznikov_->operator[](i)->getZoznamPredajni()->operator[](z)->getZona() == poziadavka.getPredajna()->getZona())
					{
						predajnaSaNachadza = true;
						break;
					}
				}
			}
		}
		if (!zakaznikSaNachadza)
		{
			zoznamZakaznikov_->add(poziadavka.getZakaznik());
		}
	}
}



void Semestralka::Velkosklad::kontrolujPoziadavkyVsMnozstvoNaSklade()
{
	
	/*Po  vykonan�  tejto
		oper�cie sa vyp�e zoznam t�ch miner�lnych v�d, ktor�ch mno�stvo na sklade je men�ie
		ako  je  mno�stvo  po�adovan�  z�kazn�kmi.�daje  musia  by�  vyp�san�  v abecednom
		porad�  pod�a  n�zvu  dod�vate�a  a n�zvu  miner�lnej  vody.Vo  v�pise  mus�  by�  aj
		ch�baj�ce mno�stvo jednotliv�ch miner�lnych v�d*/
}

void Semestralka::Velkosklad::vyskladni()
{
}


/*Odovzdanie  tovaru  z�kazn�kovi. Z kontajnera, ktor�  sa  nach�dza  v aute, sa  odoberie najvrchnej�ia polo�ka.
T�mto d�jde k zrealizovaniu  konkr�tnej po�iadavky, t.j.v tomto okam�iku sa po�iadavka ozna�� za zrealizovan�.*/
void Semestralka::Velkosklad::odovzdajTovarZakaznikovi()
{
}


/*Vyp�sanie aktu�lneho mno�stva jednotliv�ch  typov miner�lnych v�d na sklade.  �daje musia  by�  vyp�san�
v abecednom porad�  pod�a  n�zvu  dod�vate�a  a n�zvu  miner�lnej vody.*/
void Semestralka::Velkosklad::vypisAktualneMnozstvoTypovMVNaSklade()
{
	cout << "Na sklade sa nachadza " << zoznamTypovMineralnychVod_->size() << "typov mineralnych vod.";
	cout << "--------------------------------------------------------";
	ArrayList<TypMineralnejVody*>* pom = zoznamTypovMineralnychVod_;
	ArrayList<int>* mnozstva = zoznamMnozstvievTypov_;

	for (size_t i = 0; i < pom->size(); i++)
	{

	}
	cout << "";
}


Zakaznik* Semestralka::Velkosklad::vyhladajOdberatela(Datum& zaciatokObdobia, Datum& koniecObdobia, TypMineralnejVody& typMineralnejVody)
{
	throw -1;
}

Zakaznik* Semestralka::Velkosklad::vyhladajOdberatela(Datum& zaciatokObdobia, Datum& koniecObdobia, Dodavatel& dodavatel)
{
	throw -1;
}


void Semestralka::Velkosklad::vypisNezrealizovanePoziadavky()
{
}

Dodavatel* Semestralka::Velkosklad::vyhladajDodavatelaSMaxDopytom(Datum& zaciatokObdobia, Datum& koniecObdobia)
{
	throw -1;
}

void Semestralka::Velkosklad::ulozitDoSuboruAktualnyStavEvidencie()
{
}

void Semestralka::Velkosklad::nacitatZoSuboruAktualnyStavEvidencie()
{
}
