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
		string toString();
	private:
		string obchodnyNazov_;
		string adresaSidla_;
	};
}