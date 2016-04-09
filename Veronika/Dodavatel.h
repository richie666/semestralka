#pragma once
#include <string>

using namespace std;

namespace Semestralka {

	class Dodavatel
	{
	public:
		Dodavatel(string obchodnyNazov, string adresaSidla);
		virtual ~Dodavatel();
		string getObchodnyNazov();
		string getAdresaSidla();

	private:
		string obchodnyNazov_;
		string adresaSidla_;
	};
}
