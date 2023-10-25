#include<iostream>
using namespace std;

class Formatie {
public:
	static string genMuzical ;
	const float pretOra;
	string numeFormatie;
	int nrInstrumente;
	int nrSolisti;
	string* numeSolisti;

	Formatie() : pretOra(1500) {
		this->numeFormatie = "Lala";
		this->nrSolisti = 0;
		this->numeSolisti = NULL;
		this->nrInstrumente = 0;
	}
	Formatie(string* numeSolisti, int nrSolisti) : pretOra(1500) {
		this->numeFormatie = "NuntaDeVis";
		this->nrSolisti = nrSolisti;
		this->numeSolisti = new string[nrSolisti];
		for (int i = 0; i < nrSolisti; i++) {
			this->numeSolisti[i] = numeSolisti[i];
		}
		this->nrInstrumente = 0;
	}
	Formatie(string numeFormatie, int nrSolisti, string* numeSolisti, int nrInstrumente) : pretOra(1500) {
		this->numeFormatie = numeFormatie;
		this->nrSolisti = nrSolisti;
		this->nrInstrumente = nrInstrumente;
		this->numeSolisti = new string[nrSolisti];
		for (int i = 0; i < nrSolisti; i++) {
			this->numeSolisti[i] = numeSolisti[i];
		}


	}
	~Formatie() {
		if (this->numeSolisti != NULL) {
			delete[]this->numeSolisti;
		}
	}

	void afisareFormatie() {
		cout << "Formatia " << numeFormatie << " care are tariful de " << pretOra << " de euro pe ora,cu " << nrInstrumente << " instrumente si cu " << nrSolisti << " solisti ,care sunt: ";
		if(nrSolisti>0)
		{
			for (int i = 0; i < nrSolisti; i++) {
				cout << numeSolisti[i] << " ";
			}
		}
		else {
			cout <<"NE";
		}
		cout << endl;
	}
	static string getgenMuzical() {
		return genMuzical;
	}

};

string Formatie::genMuzical = "Pop";

class Mireasa {
public:
	const int ziuaNuntii;
	static string culoareRochie;
	string nume;
	float pretRochie;
	int nrDomnisoareO;
	string* numeDomnisoareO;

	Mireasa() : ziuaNuntii(12) {
		this->nume = "Ana";
		this->pretRochie = 2340.5;
		this->nrDomnisoareO = 0;
		this->numeDomnisoareO = NULL;
	}

	Mireasa(string nume,float pretRochie) :ziuaNuntii(30) {
		this->nume = nume;
		this->pretRochie = pretRochie;
		this->nrDomnisoareO = 0;
		this->numeDomnisoareO = NULL;
	}

	Mireasa(string nume, float pretRochie, int nrDomnisoareO, string* numeDomnisoareO) :ziuaNuntii(19) {
		this->nume = nume;
		this->pretRochie = pretRochie;
		this->nrDomnisoareO = nrDomnisoareO;
		this->numeDomnisoareO = new string[nrDomnisoareO];
		for (int i = 0; i < nrDomnisoareO; i++) {
			this->numeDomnisoareO[i] = numeDomnisoareO[i];
		}

	}
	~Mireasa() {
		if (this->numeDomnisoareO != NULL) {
			delete[]this->numeDomnisoareO;
		}
	}


	
	void afisareMireasa() {
		cout <<"In ziua de "<<ziuaNuntii << " ,mireasa " << nume << " a carei rochie a costat " << pretRochie << " si care a avut " << nrDomnisoareO << " domnisoare de onoare,anume: ";
		if (nrDomnisoareO > 0) {
			for (int i = 0; i < nrDomnisoareO; i++) {
				cout << numeDomnisoareO[i] << " ";
			}
		}
		else {
			cout << "niciuna";
		}
		cout << endl;
	}

	static string getculoareRochie() {
		return culoareRochie;
	}
	
};
string Mireasa::culoareRochie = "alb";


class Meniu {
public:
	const int pret;
	static int nrPortii;
	int nrFeluri;
	string* numeFeluri;
	float nrKilocalorii;
	float cantitateGrame;

	Meniu() :pret(200) {
		this->nrFeluri = 0;
		this->numeFeluri = NULL;
		this->nrKilocalorii = 1700;
		this->cantitateGrame = 2330;
	}

	Meniu(string* numeFeluri, int nrFeluri) :pret(pret) {
		this->nrFeluri = nrFeluri;
		this->numeFeluri = new string[nrFeluri];
		for (int i = 0; i < nrFeluri; i++) {
			this->numeFeluri[i] = numeFeluri[i];
		}
		this->nrKilocalorii = 1700;
		this->cantitateGrame = 2330;
	}

	Meniu(int nrFeluri,string* numeFeluri,float nrKilocalorii,float cantitateGrame) : pret(200){
		this->nrFeluri = nrFeluri;
		this->numeFeluri = new string[nrFeluri];
		for (int i = 0; i < nrFeluri; i++) {
			this->numeFeluri[i] = numeFeluri[i];
		}
		this->nrKilocalorii = nrKilocalorii;
		this->cantitateGrame = cantitateGrame;
		
	}
	~Meniu() {
		if (this->numeFeluri != NULL) {
			delete[]this->numeFeluri;
		}
	}

	void afisareMeniu() {
		cout << "Meniul de la nunta,a avut cantitatea de " << cantitateGrame << " grame,cu " << nrKilocalorii << " kilocalorii,a costat "<<pret<<" euro si a fost cerut cu "<<nrFeluri<<" feluri,iar la preferintele mirilor au fost alese: ";
		if (nrFeluri > 0) {
			for (int i = 0; i < nrFeluri; i++) {
				cout << numeFeluri[i] << " ";
			}
		}
		else {
			cout << " 0 ";
		}
		cout << endl;
	}
	static int getnrPortii() {
		return nrPortii;
	}
};
int Meniu::nrPortii = 300;








void main() {
	Formatie formatie1;
	formatie1.afisareFormatie();
	string* numeSolisti = new string[3];
	numeSolisti[0] = "Andrei";
	numeSolisti[1] = "George";
	numeSolisti[2] = "Ana";

	Formatie formatie2(numeSolisti, 2);
	formatie2.afisareFormatie();
	
	Formatie formatie3("Lala", 3, numeSolisti, 3);
	formatie3.afisareFormatie();
	cout<< "Genul muzical luat in considerare in alegerea formatiei este: " << Formatie::getgenMuzical() << endl;





	Mireasa mireasa1;
	mireasa1.afisareMireasa();
	string* numeDomnisoareO = new string[2];
	numeDomnisoareO[0] = "Alice";
	numeDomnisoareO[1] = "Bianca";

	

	Mireasa mireasa2("Alice",7500.3);
	mireasa2.afisareMireasa();
	
	Mireasa mireasa3("Beatrice", 9999.9, 2, numeDomnisoareO);
	mireasa3.afisareMireasa();
	cout << "Culoarea rochiei este: " << Mireasa::getculoareRochie() << endl;




	Meniu meniu1;
	meniu1.afisareMeniu();
	
	string* numeFeluri = new string[3];
	numeFeluri[0] = "aperitiv";
	numeFeluri[1] = "sarmale";
	numeFeluri[2] = "friptura";

	Meniu meniu2(numeFeluri,3);
	meniu2.afisareMeniu();
	
	


	Meniu meniu3(3, numeFeluri, 45.5, 32.0);
	meniu3.afisareMeniu();
	cout<< "Numarul portiilor pentru aceasta nunta este de: " << Meniu::getnrPortii() << endl;


	
}