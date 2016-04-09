#pragma once
#include<string>

using namespace std;

namespace Semestralka {
	class Pobocka {

	public:
		Pobocka(int zonaPredajne, string adresaPredajne);
		virtual ~Pobocka();
		string dajAdresu();
		int dajZonu();
	private:
		int zonaPredajne_;
		string adresaPredajne_;
	};
}