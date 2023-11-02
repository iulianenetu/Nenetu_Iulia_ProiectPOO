#include<iostream>
using namespace std;

class Formatie {
private:
	static string genMuzical ;
	const float pretOra;
	string numeFormatie;
	int nrInstrumente;
	int nrSolisti;
	string* numeSolisti;
public:
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

	Formatie(const Formatie& m) :pretOra(1500) {
		this->numeFormatie = m.numeFormatie;
		this->nrSolisti = m.nrSolisti;
		this->nrInstrumente = m.nrInstrumente;
		this->numeSolisti = new string[m.nrSolisti];
		for (int i = 0; i < m.nrSolisti; i++) {
			this->numeSolisti[i] = m.numeSolisti[i];
		}
	}
	Formatie operator=(const Formatie& m) {
		if (this != &m) {
			this->numeFormatie = m.numeFormatie;
			this->nrSolisti = m.nrSolisti;
			this->nrInstrumente = m.nrInstrumente;
			if (this->numeSolisti != NULL) {
				delete[]this->numeSolisti;
			}
			for (int i = 0; i < m.nrSolisti; i++) {
				this->numeSolisti[i] = m.numeSolisti[i];
			}
		}
		return *this;
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
	string getNumeFormatie() {
		return numeFormatie;
	}
	void setNumeFormatie(string numeFormatie) {
		if (numeFormatie.length() > 0) {
			this->numeFormatie = numeFormatie;
		}
	}
	int getNrInstrumente() {
		return nrInstrumente;
	}
	void setNrInstrumente(int nrInstrumente) {
		if (nrInstrumente > 0) {
			this->nrInstrumente = nrInstrumente;
		}
	}
	int getNrSolisti() {
		return nrSolisti;
	}
	void setNrSolisti(int nrSolisti) {
		if (nrSolisti > 0) {
			this->nrSolisti = nrSolisti;
		}
	}
	void setSolisti(int nrSolisti, string* numeSolisti) {
		if (nrSolisti > 0) {
			this->nrSolisti = nrSolisti;
			if (this->numeSolisti != NULL) {
				delete[]this->numeSolisti;
			}
			this->numeSolisti = new string[nrSolisti];
			for (int i = 0; i < nrSolisti; i++) {
				this->numeSolisti[i] = numeSolisti[i];
			}
		}
	}
	string* getNumeSolisti() {
		return numeSolisti;
	}
	friend string getSirSolisti(const Formatie& m);
};

string Formatie::genMuzical = "Pop";


string getSirSolisti(const Formatie& m) {
	string aux = "";
	for (int i = 0; i < m.nrSolisti; i++) {
		aux += m.numeSolisti[i] + ",";
	}
	return aux;
}

class Mireasa {
private:
	const int ziuaNuntii;
	static string culoareRochie;
	string nume;
	float pretRochie;
	int nrDomnisoareO;
	string* numeDomnisoareO;
public:
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
	Mireasa(const Mireasa& o) :ziuaNuntii(20) {
		this->nume = o.nume;
		this->pretRochie = o.pretRochie;
		this->nrDomnisoareO = o.nrDomnisoareO;
		this->numeDomnisoareO = new string[o.nrDomnisoareO];
		for (int i = 0; i < o.nrDomnisoareO; i++) {
			this->numeDomnisoareO[i] = o.numeDomnisoareO[i];
		}
	}
	Mireasa operator=(const Mireasa& o) {
		if (this != &o) {
			this->nume = o.nume;
			this->pretRochie = o.pretRochie;
			this->nrDomnisoareO = o.nrDomnisoareO;
			if (numeDomnisoareO != NULL) {
				delete[]this->numeDomnisoareO;
			}
			for (int i = 0; i < o.nrDomnisoareO; i++) {
				this->numeDomnisoareO[i] = o.numeDomnisoareO[i];
			}
		}
		return *this;
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

	string getNume() {
		return nume;
	}
	void setNume(string nume) {
		if (nume.length() > 0) {
			this->nume = nume;
		}
	}
	float getPretRochie() {
		return pretRochie;
	}
	void setPretRochie(float pretRochie) {
		if (pretRochie > 10) {
			this->pretRochie =pretRochie;
		}
	}
	int getNrDomnisoareO() {
		return nrDomnisoareO;
	}
	void setNrDomnisoareO(int nrDomnisoareO) {
		if (nrDomnisoareO > 0) {
			this->nrDomnisoareO = nrDomnisoareO;
		}
	}
	void setDomnisoare(int nrDomnisoareO, string* numeDomnisoareO) {
		if (nrDomnisoareO > 0) {
			this->nrDomnisoareO = nrDomnisoareO;
			if (this->numeDomnisoareO != NULL) {
				delete[]this->numeDomnisoareO;
			}
			this->numeDomnisoareO = new string[nrDomnisoareO];
			for (int i = 0; i < nrDomnisoareO; i++) {
				this->numeDomnisoareO[i] = numeDomnisoareO[i];
			}
		}
	}
	string* getNumeDomnisoareO() {
		return numeDomnisoareO;
	}
	
};
string Mireasa::culoareRochie = "alb";


class Meniu {
private:
	const int pret;
	static int nrPortii;
	int nrFeluri;
	string* numeFeluri;
	float nrKilocalorii;
	float cantitateGrame;
public:
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
	Meniu(const Meniu& p) :pret(200) {
		this->nrFeluri = p.nrFeluri;
		this->numeFeluri = new string[p.nrFeluri];
		for (int i = 0; i < p.nrFeluri; i++) {
			this->numeFeluri[i] = p.numeFeluri[i];
		}
		this->nrKilocalorii = p.nrKilocalorii;
		this->cantitateGrame = p.cantitateGrame;

	}
	Meniu operator=(const Meniu& p) {
		if (this != &p) {
			this->nrKilocalorii = p.nrKilocalorii;
			this->cantitateGrame = p.cantitateGrame;
			this->nrFeluri = p.nrFeluri;
			if (numeFeluri != NULL) {
				delete[]this->numeFeluri;
			}
			this->numeFeluri = new string[p.nrFeluri];
			for (int i = 0; i < p.nrFeluri; i++) {
				this->numeFeluri[i] = p.numeFeluri[i];
			}
		}
		return *this;
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

	float getCantitateGrame() {
		return cantitateGrame;
	}
	void setCantitateGrame(float cantitateGrame) {
		if (cantitateGrame > 10) {
			this->cantitateGrame = cantitateGrame;
		}
	}
	float getNrKilocalorii() {
		return nrKilocalorii;
	}
	void setNrKilocalorii(float nrKilocalorii) {
		if (nrKilocalorii > 10) {
			this->nrKilocalorii = nrKilocalorii;
		}
	}
	int getNrFeluri() {
		return nrFeluri;
	}
	void setNrFeluri(int nrFeluri) {
		if (nrFeluri > 0) {
			this->nrFeluri = nrFeluri;
		}
	}
	void setFeluri(int nrFeluri, string* numeFeluri) {
		if (nrFeluri > 0) {
			this->nrFeluri = nrFeluri;
			if (this->numeFeluri != NULL) {
				delete[]this->numeFeluri;
			}
			this->numeFeluri = new string[nrFeluri];
			for (int i = 0; i < nrFeluri; i++) {
				this->numeFeluri[i] = numeFeluri[i];
			}
		}
	}
	string* getNumeFeluri() {
		return numeFeluri;
	}
	friend float getNumarKilocaloriiPePortie(const Meniu& p);
};
int Meniu::nrPortii = 300;

float getNumarKilocaloriiPePortie(const Meniu& p) {
	float aux = 0;
	if ( p.nrFeluri > 0) {
		aux =p.nrKilocalorii / p.nrFeluri;
			return aux;
	}
}



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

	Formatie f1 = formatie3;
	f1.afisareFormatie();

	cout << f1.getNumeFormatie() << endl;
	f1.setNumeFormatie("alabala");
	cout << f1.getNumeFormatie() << endl;
	f1.setNrInstrumente(1);
	cout << f1.getNrInstrumente() << endl;
	f1.setNrSolisti(2);
	cout << f1.getNrSolisti() << endl;
	string* vector = new string[2]{ "Alex","Marcela" };
	f1.setSolisti(2, vector);
	cout << *f1.getNumeSolisti() << endl;
	cout << *(f1.getNumeSolisti() + 1) << endl;

	delete[]vector;


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
	Mireasa o1 = mireasa3;
	o1.afisareMireasa();


	cout << o1.getNume() << endl;
	o1.setNume("Laura");
	cout << o1.getNume() << endl;
	o1.setPretRochie(3456);
	cout << o1.getPretRochie() << endl;
	o1.setNrDomnisoareO(2);
	cout << o1.getNrDomnisoareO() << endl;
	string* vector1 = new string[2]{ "Eliza","Vanessa" };
	o1.setDomnisoare(2, vector1);
	cout << *o1.getNumeDomnisoareO() << endl;
	cout << *(o1.getNumeDomnisoareO() + 1) << endl;

	delete[]vector1;



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

	Meniu m1 = meniu3;
	m1.afisareMeniu();

	cout << m1.getCantitateGrame() << endl;
	m1.setCantitateGrame(245);
	cout << m1.getCantitateGrame() << endl;
	m1.setNrKilocalorii(12345);
	cout << m1.getNrKilocalorii() << endl;
	m1.setNrFeluri(3);
	cout << m1.getNrFeluri() << endl;
	string* vector2 = new string[3]{ "Mezeluri","Peste","Tort"};
	m1.setFeluri(3, vector2);
	cout << *m1.getNumeFeluri() << endl;
	cout << *(m1.getNumeFeluri() + 1) << endl;
	cout << *(m1.getNumeFeluri() + 2) << endl;
	delete[]vector2;


	cout << endl << getSirSolisti(f1)<<endl;
	cout << endl << getNumarKilocaloriiPePortie(meniu2);
}