#pragma once
#include<string>

using namespace std;

namespace Semestralka {
	class Dodavatel {

	public:	
		Dodavatel(string obchodnyNazov, string adresaSidla);
		virtual ~Dodavatel();
		string dajObchodnyNazov();
		string dajAdresuSidla();
	private:
		string obchodnyNazov_;
		string adresaSidla_;
	};
}