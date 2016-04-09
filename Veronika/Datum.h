#pragma once

using namespace std;

namespace Semestralka {

	class Datum
	{
	public:
		Datum(int den, int mesiac, int rok);
		virtual ~Datum();
		int getDen();
		int getMesiac();
		int getRok();
		bool jeMensiAko(int den, int mesiac, int rok);

	private:
		int den_;
		int mesiac_;
		int rok_;
	};
}

