#pragma once
#include <string>
#include "Dodavatel.h"

using namespace std;

namespace Semestralka {
	class TypMineralnejVody
	{
	public:
		TypMineralnejVody(string EANkod, string nazov, Dodavatel& dodavatel);
		virtual ~TypMineralnejVody();
		string getEANkod();
		string getNazov();
		Dodavatel* getDodavatel();

	private:
		string EANkod_;
		string nazov_;
		Dodavatel* dodavatel_;
	};
}

