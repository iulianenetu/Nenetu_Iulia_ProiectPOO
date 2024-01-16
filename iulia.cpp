#include<iostream>
#include<fstream>
using namespace std;

class Local {
private:
	string nume;
public:
	virtual void DescrieLocal() = 0;

	Local() {
		this->nume = "Nuba";
	}
	string getNume() {
		return this->nume;
	}
	void setNume(string nume) {
		if (nume.length() > 0) {
			this->nume = nume;
		}
	}
};

class Nasi {
private:
	string nume;
public:
	virtual void DescrieNasi() = 0;
	Nasi() {
		this->nume = "Popescu";
	}
	string getNumeNasi() {
		return this->nume;
	}
	void setNumeNasi(string nume) {
		if (nume.length() > 0) {
			this->nume = nume;
		}
	}
};


class Formatie : public Local {
private:
	static string genMuzical;
	const float pretOra;
	string numeFormatie;
	int nrInstrumente;
	int nrSolisti;
	string* numeSolisti;
public:
	Formatie() : Local(), pretOra(1500) {
		this->numeFormatie = "Lala";
		this->nrSolisti = 0;
		this->numeSolisti = NULL;
		this->nrInstrumente = 0;
	}
	Formatie(string* numeSolisti, int nrSolisti) : Local(), pretOra(1500) {
		this->numeFormatie = "NuntaDeVis";
		this->nrSolisti = nrSolisti;
		this->numeSolisti = new string[nrSolisti];
		for (int i = 0; i < nrSolisti; i++) {
			this->numeSolisti[i] = numeSolisti[i];
		}
		this->nrInstrumente = 0;
	}
	Formatie(string numeFormatie, int nrSolisti, string* numeSolisti, int nrInstrumente) : Local(), pretOra(1500) {
		this->numeFormatie = numeFormatie;
		this->nrSolisti = nrSolisti;
		this->nrInstrumente = nrInstrumente;
		this->numeSolisti = new string[nrSolisti];
		for (int i = 0; i < nrSolisti; i++) {
			this->numeSolisti[i] = numeSolisti[i];
		}


	}

	Formatie(const Formatie& m) :Local(m), pretOra(1500) {
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
			Local::operator=(m);
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
	void DescrieLocal() {
		cout << "Formatia cu numele: " << this->numeFormatie << endl;
	}

	~Formatie() {
		if (this->numeSolisti != NULL) {
			delete[]this->numeSolisti;
		}
	}

	void afisareFormatie() {
		cout << "Formatia " << numeFormatie << " care are tariful de " << pretOra << " de euro pe ora,cu " << nrInstrumente << " instrumente si cu " << nrSolisti << " solisti ,care sunt: ";
		if (nrSolisti > 0)
		{
			for (int i = 0; i < nrSolisti; i++) {
				cout << numeSolisti[i] << " ";
			}
		}
		else {
			cout << "NE";
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

	Formatie operator+(int nrInstrumente)const {
		Formatie aux = *this;
		aux.nrInstrumente = this->nrInstrumente + nrInstrumente;
		return aux;
	}
	/*string numeFormatie;
	int nrInstrumente;
	int nrSolisti;
	string* numeSolisti;*/
	friend ostream& operator<<(ostream& form, const Formatie& f) {
		form << "Numar instrumente: " << f.nrInstrumente << " ";
		form << "Numar solisti: " << f.nrSolisti << " ";
		form << "Numele formatiei: " << f.numeFormatie << " ";
		form << "Numele solistilor: ";
		for (int i = 0; i < f.nrSolisti; i++) {
			form << f.numeSolisti[i] << " , ";

		}
		form << endl;
		return form;
	}

	friend istream& operator>>(istream& t, Formatie& f) {
		cout << "Numele formtiei: ";
		t >> f.numeFormatie;
		cout << "Numarul instrumentelor: ";
		t >> f.nrInstrumente;
		cout << "Numarul solistilor: ";
		t >> f.nrSolisti;
		if (f.numeSolisti != NULL) {
			delete[]f.numeSolisti;
		}
		f.numeSolisti = new string[f.nrSolisti];
		for (int i = 0; i < f.nrSolisti; i++) {
			cout << "Numele solistilor sunt: ";
			t >> f.numeSolisti[i];

		}
		return t;
	}
	string operator()() {
		string s = " ";
		for (int i = 0; i < this->nrSolisti; i++) {
			s += this->numeSolisti[i];
		}

		return s;
	}
	friend ifstream& operator>>(ifstream& cit, Formatie& fr) {
		cit >> fr.numeFormatie;
		cit >> fr.nrInstrumente;
		cit >> fr.nrSolisti;
		if (fr.numeSolisti != NULL) {
			delete[]fr.numeSolisti;
		}
		fr.numeSolisti = new string[fr.nrSolisti];
		for (int i = 0; i < fr.nrSolisti; i++) {
			cit >> fr.numeSolisti[i];

		}
		return cit;
	}
	friend ofstream& operator<<(ofstream& afi, const Formatie& fr) {
		afi << fr.nrInstrumente << " ";
		afi << fr.nrSolisti << " ";
		afi << fr.numeFormatie << " ";
		string form = " ";
		for (int i = 0; i < fr.nrSolisti; i++) {
			form += fr.numeSolisti[i];
			afi << fr.numeSolisti[i] << " ";
		}
		return afi;
	}

};

string Formatie::genMuzical = "Pop";


string getSirSolisti(const Formatie& m) {
	string aux = "";
	for (int i = 0; i < m.nrSolisti; i++) {
		aux += m.numeSolisti[i] + ",";
	}
	return aux;
}

class Mireasa : public Nasi {
private:
	const int ziuaNuntii;
	static string culoareRochie;
	string nume;
	float pretRochie;
	int nrDomnisoareO;
	string* numeDomnisoareO;
public:
	Mireasa() : Nasi(), ziuaNuntii(12) {
		this->nume = "Ana";
		this->pretRochie = 2340.5;
		this->nrDomnisoareO = 0;
		this->numeDomnisoareO = NULL;
	}

	Mireasa(string nume, float pretRochie) :Nasi(), ziuaNuntii(30) {
		this->nume = nume;
		this->pretRochie = pretRochie;
		this->nrDomnisoareO = 0;
		this->numeDomnisoareO = NULL;
	}

	Mireasa(string nume, float pretRochie, int nrDomnisoareO, string* numeDomnisoareO) :Nasi(), ziuaNuntii(19) {
		this->nume = nume;
		this->pretRochie = pretRochie;
		this->nrDomnisoareO = nrDomnisoareO;
		this->numeDomnisoareO = new string[nrDomnisoareO];
		for (int i = 0; i < nrDomnisoareO; i++) {
			this->numeDomnisoareO[i] = numeDomnisoareO[i];
		}

	}
	Mireasa(const Mireasa& o) :Nasi(o), ziuaNuntii(20) {
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
			Nasi::operator=(o);
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
	void DescrieNasi() {
		cout << "Nasii ii vor fii parinti spirituli miresei " << this->nume << endl;
	}
	~Mireasa() {
		if (this->numeDomnisoareO != NULL) {
			delete[]this->numeDomnisoareO;
		}
	}



	void afisareMireasa() {
		cout << "In ziua de " << ziuaNuntii << " ,mireasa " << nume << " a carei rochie a costat " << pretRochie << " si care a avut " << nrDomnisoareO << " domnisoare de onoare,anume: ";
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
			this->pretRochie = pretRochie;
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

	/*const int ziuaNuntii;
	static string culoareRochie;
	string nume;
	float pretRochie;
	int nrDomnisoareO;
	string* numeDomnisoareO;*/

	friend ostream& operator<<(ostream& mire, const Mireasa& m) {
		mire << "Numele miresei : " << m.nume << " , ";
		mire << "A dat pe rochie : " << m.pretRochie << ", ";
		mire << "Numarul domnisoarelor de onoare: " << m.nrDomnisoareO << " , ";
		mire << "Numele domnisoarelor: ";
		for (int i = 0; i < m.nrDomnisoareO; i++) {
			mire << m.numeDomnisoareO[i] << " , ";

		}
		mire << endl;
		return mire;
	}

	friend istream& operator>>(istream& mire, Mireasa& m) {
		cout << "Numele miresei: ";
		mire >> m.nume;
		cout << "A dat pe rochie: ";
		mire >> m.pretRochie;
		cout << "Numarul domnisoarelor: ";
		mire >> m.nrDomnisoareO;
		if (m.numeDomnisoareO != NULL) {
			delete[]m.numeDomnisoareO;
		}
		m.numeDomnisoareO = new string[m.nrDomnisoareO];
		for (int i = 0; i < m.nrDomnisoareO; i++) {
			cout << "Numele domnisoarelor sunt: ";
			mire >> m.numeDomnisoareO[i];

		}
		return mire;
	}

	bool operator>(Mireasa m) {
		return this->pretRochie > m.pretRochie;
	}
	Mireasa operator+(float pretRochie) const {
		Mireasa aux = *this;
		aux.pretRochie = this->pretRochie + pretRochie;
		return aux;
	}


	friend Mireasa operator+(float pretRochie, const Mireasa& m) {
		Mireasa aux = m;
		aux.pretRochie = m.pretRochie + pretRochie;
		return aux;
	}

	friend ifstream& operator>>(ifstream& ci, Mireasa& mi) {
		ci >> mi.nume;
		ci >> mi.pretRochie;
		ci >> mi.nrDomnisoareO;
		if (mi.numeDomnisoareO != NULL) {
			delete[]mi.numeDomnisoareO;
		}
		mi.numeDomnisoareO = new string[mi.nrDomnisoareO];
		for (int i = 0; i < mi.nrDomnisoareO; i++) {
			ci >> mi.numeDomnisoareO[i];

		}
		return ci;
	}
	friend ofstream& operator<<(ofstream& mir, const Mireasa& mi) {
		mir << mi.nrDomnisoareO<< " ";
		mir << mi.nume << " ";
		mir << mi.pretRochie << " ";
		string mire = " ";
		for (int i = 0; i< mi.nrDomnisoareO  ; i++) {
			mire += mi.numeDomnisoareO[i];
			mir << mi.numeDomnisoareO[i] << " ";
		}
		return mir;
	}

};
string Mireasa::culoareRochie = "alb";

class Mire {
private:
	string nume;
	int nrCavaleri;
	Mireasa mireasa;
public:
	Mire() {
		this->nume = "Adrian";
		this->nrCavaleri = 2;
	}
	Mire(string nume, int nrCavaleri, Mireasa& mir) {
		this->nume = nume;
		this->nrCavaleri = nrCavaleri;
		this->mireasa = mir;
	}

	void afisareMire() {
		cout << "Numele mirelui este: " << nume << " ,si el are: " << nrCavaleri << "  cavaleri de onoare. ";
		mireasa.afisareMireasa();
	}
	void setNume(string nume) {
		this->nume = nume;
	}
	void setNrCavaleri(int nrCavaleri) {
		this->nrCavaleri = nrCavaleri;
	}
	string getNume() {
		return nume;
	}
	int getNrCavaleri() {
		return nrCavaleri;
	}
	int getMireasa() {
		cout << "Mireasa: " << mireasa.getNume() << "este a mirelui: " << nume << " care are ";
		return nrCavaleri;
		cout << "  cavaleri de onoare.";
	}
	void setMireasa(Mireasa& mir) {
		this->mireasa = mir;
	}
	Mire operator=(const Mire& m) {
		this->nume = m.nume;
		this->nrCavaleri = m.nrCavaleri;
		this->mireasa = m.mireasa;
		return *this;
	}
	friend ostream& operator<<(ostream& a, const Mire& m) {
		a << "Numele mirelui: " << m.nume << endl;
		a << "Numarul cavalerilor: " << m.nrCavaleri << endl;
		a << "Detaliile despre mireasa lui: " << m.mireasa;
		return a;
	}
	friend istream& operator>>(istream& c, Mire& mi) {
		cout << "Numele mirelui: ";
		c >> mi.nume;
		cout << "Numarul cavalerilor de onoare: ";
		c >> mi.nrCavaleri;
		cout << "Mireasa: ";
		c >> mi.mireasa;
		return c;
	}

	friend ifstream& operator>>(ifstream& in, Mire& m) {
		in >> m.nume;
		in >> m.nrCavaleri;
		in >> m.mireasa;
		
		return in;
	}
	friend ofstream& operator<<(ofstream& ex, const Mire& m) {
		ex << m.nume << " ";
		ex << m.nrCavaleri << " ";
		ex << m.mireasa << " ";
		
		return ex;
	}


};


class Meniu : public Local {
private:
	const int pret;
	static int nrPortii;
	int nrFeluri;
	string* numeFeluri;
	float nrKilocalorii;
	float cantitateGrame;
public:
	Meniu() : Local(), pret(200) {
		this->nrFeluri = 0;
		this->numeFeluri = NULL;
		this->nrKilocalorii = 1700;
		this->cantitateGrame = 2330;
	}

	Meniu(string* numeFeluri, int nrFeluri) :Local(), pret(pret) {
		this->nrFeluri = nrFeluri;
		this->numeFeluri = new string[nrFeluri];
		for (int i = 0; i < nrFeluri; i++) {
			this->numeFeluri[i] = numeFeluri[i];
		}
		this->nrKilocalorii = 1700;
		this->cantitateGrame = 2330;
	}

	Meniu(int nrFeluri, string* numeFeluri, float nrKilocalorii, float cantitateGrame) : Local(), pret(200) {
		this->nrFeluri = nrFeluri;
		this->numeFeluri = new string[nrFeluri];
		for (int i = 0; i < nrFeluri; i++) {
			this->numeFeluri[i] = numeFeluri[i];
		}
		this->nrKilocalorii = nrKilocalorii;
		this->cantitateGrame = cantitateGrame;

	}
	Meniu(const Meniu& p) :Local(p), pret(200) {
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
			Local:: operator=(p);
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
	void DescrieLocal() {
		cout << "Meniul are: " << this->nrFeluri << " feluri." << endl;
	}

	~Meniu() {
		if (this->numeFeluri != NULL) {
			delete[]this->numeFeluri;
		}
	}

	void afisareMeniu() {
		cout << "Meniul de la nunta,a avut cantitatea de " << cantitateGrame << " grame,cu " << nrKilocalorii << " kilocalorii,a costat " << pret << " euro si a fost cerut cu " << nrFeluri << " feluri,iar la preferintele mirilor au fost alese: ";
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


	friend ostream& operator<<(ostream& menu, const Meniu& p) {
		menu << "Pretul : " << p.pret << " , ";
		menu << "Numarul de portii : " << p.nrPortii << ", ";
		menu << "Numarul felurilor: " << p.nrFeluri << " , ";
		menu << "Denumirile felurilor: ";
		for (int i = 0; i < p.nrFeluri; i++) {
			menu << p.numeFeluri[i] << " , ";

		}
		menu << "Cu o cantitate de: " << p.cantitateGrame << " , ";
		menu << "Si kilocalorii: " << p.nrKilocalorii << "  ";
		menu << endl;
		return menu;
	}

	friend istream& operator>>(istream& menu, Meniu& p) {

		cout << "Numarul de portii: ";
		menu >> p.nrFeluri;
		cout << "Numarul felurilor: ";
		menu >> p.nrFeluri;
		if (p.numeFeluri != NULL) {
			delete[]p.numeFeluri;
		}
		p.numeFeluri = new string[p.nrFeluri];
		for (int i = 0; i < p.nrFeluri; i++) {
			cout << "Felurile sunt: ";
			menu >> p.numeFeluri[i];

		}
		cout << "Cantitatea:";
		menu >> p.cantitateGrame;
		cout << "Kilocalorii:";
		menu >> p.nrKilocalorii;


		return menu;
	}




	bool operator<=(Meniu p) {
		return this->cantitateGrame <= p.cantitateGrame;
	}
	float operator()() {
		if (cantitateGrame > 0) {
			return (float)(nrKilocalorii / cantitateGrame) * 100;
		}
	}

	friend ifstream& operator>>(ifstream& in, Meniu& men) {
		in >> men.nrPortii;
		in >> men.nrFeluri;
		in >> men.nrKilocalorii;
		if (men.numeFeluri != NULL) {
			delete[]men.numeFeluri;
		}
		men.numeFeluri = new string[men.nrFeluri];
		for (int i = 0; i < men.nrFeluri; i++) {
			in >> men.numeFeluri[i];

		}
		return in;
	}
	friend ofstream& operator<<(ofstream& out, const Meniu& men) {
		out << men.nrPortii << " ";
		out << men.nrFeluri << " ";
		out << men.nrKilocalorii << " ";
		string menu = " ";
		for (int i = 0; i<men.nrFeluri  ; i++) {
			menu += men.numeFeluri[i];
			out << men.numeFeluri[i] << " ";
		}
		return out;
	}

};
int Meniu::nrPortii = 300;

float getNumarKilocaloriiPePortie(const Meniu& p) {
	float aux = 0;
	if (p.nrFeluri > 0) {
		aux = p.nrKilocalorii / p.nrFeluri;
		return aux;
	}
}
class Aperitiv :public Meniu {
private:
	int nrElemente;
	float gramaj;
public:

	Aperitiv() : Meniu() {
		this->nrElemente = 12;
		this->gramaj = 210.5;
	}
	Aperitiv(int nrElemente, float gramaj) : Meniu() {
		this->nrElemente = nrElemente;
		this->gramaj = gramaj;
	}
	Aperitiv(const Aperitiv& ap) : Meniu(ap) {
		this->nrElemente = ap.nrElemente;
		this->gramaj = ap.gramaj;
	}
	Aperitiv operator=(const Aperitiv& ap) {
		if (this != &ap) {
			(Meniu)*this = (Meniu)ap;
			this->nrElemente = ap.nrElemente;
			this->gramaj = ap.gramaj;
		}
		return *this;
	}


	friend ostream& operator << (ostream& out, const Aperitiv& ap) {
		out << (Meniu)ap << endl;
		out << "primul fel de mancare din meniu are: " << ap.nrElemente << " si gramajul: " << ap.gramaj << endl;
		return out;
	}
	int getNrElemente() {
		return this->nrElemente;
	}
	float getGramaj() {
		return this->gramaj;
	}
	void setNrElemente(int nrElemente) {
		this->nrElemente = nrElemente;
	}
	void setGramaj(float gramaj) {
		this->gramaj = gramaj;
	}

};
class Tort :public Meniu {
private:
	int nrPortii;
	string umplutura;
public:

	Tort() : Meniu() {
		this->nrPortii = 230;
		this->umplutura = "ciocolata si visine";
	}
	Tort(int nrPortii, string umplutura) : Meniu() {
		this->nrPortii = nrPortii;
		this->umplutura = umplutura;
	}
	Tort(const Tort& to) : Meniu(to) {
		this->nrPortii = to.nrPortii;
		this->umplutura = to.umplutura;
	}
	Tort operator=(const Tort& to) {
		if (this != &to) {
			(Meniu)*this = (Meniu)to;
			this->nrPortii = to.nrPortii;
			this->umplutura = to.umplutura;
		}
		return *this;
	}


	friend ostream& operator << (ostream& out, const Tort& to) {
		out << (Meniu)to << endl;
		out << "Tortul miresei are umplutura de " << to.umplutura << " si este pentru  " << to.nrPortii <<" invitati"<< endl;
		return out;
	}
	int getNrPortii() {
		return this->nrPortii;
	}
	string getUmplutura() {
		return this->umplutura;
	}
	void setNrPortii(int nrPortii) {
		this->nrPortii = nrPortii;
	}
	void setUmplutura(string umplutura) {
		this->umplutura = umplutura;
	}

};





class Eveniment {
	int nrEvenimente;
	Local** localuri;
public:
	Eveniment() {
		this->nrEvenimente = 10;
		this->localuri = new  Local * [10];
		for (int i = 0; i < 10; i++) {
			this->localuri[i] = new Meniu;
		}
	}
	Local*& operator[](int i) {
		if (i >= 0 && i < this->nrEvenimente)
			return this->localuri[i];
	}
};




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
	cout << "Genul muzical luat in considerare in alegerea formatiei este: " << Formatie::getgenMuzical() << endl;

	/*Formatie* formatii = new Formatie[3];

	for (int i = 0; i < 3; i++) {
		cin >> formatii[i];
	}
	for (int i = 0; i < 3; i++) {
		cout << formatii[i];
	}


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

	cout << formatie3;
	cin >> formatie3;
	cout << endl << formatie3();
	cout << endl << getSirSolisti(f1) << endl;

	const int nr_linii = 2;
	const int nr_coloane = 2;

	Formatie matriceFormatie[nr_linii][nr_coloane];
	for (int i = 0; i < nr_linii; i++) {
		for (int j = 0; j < nr_coloane; j++) {
			cout << "Introduceti datele penru obietul Formatie la pozitia [" << i << "][" << j << "]";
			cin >> matriceFormatie[i][j];
			cout << endl;
		}
	}
	for (int i = 0; i < nr_linii; i++) {
		for (int j = 0; j < nr_coloane; j++) {
			cout << "Afisre obiecte Formatie la pozitia[" << i << "][" << j << "]";
			cout << matriceFormatie[i][j];
		}
	}*/

	ofstream afisare("textFormatie.txt", ios::out);
	afisare << formatie2;
	afisare.close();
	ifstream citire("textFormatie.txt", ios::in);
	Formatie f5;
	citire >> f5;
	cout << "---------------------" << f5;
	citire.close();




	Mireasa mireasa1;
	mireasa1.afisareMireasa();
	string* numeDomnisoareO = new string[2];
	numeDomnisoareO[0] = "Alice";
	numeDomnisoareO[1] = "Bianca";



	Mireasa mireasa2("Alice", 7500.3);
	mireasa2.afisareMireasa();

	Mireasa mireasa3("Beatrice", 9999.9, 2, numeDomnisoareO);
	mireasa3.afisareMireasa();
	cout << "Culoarea rochiei este: " << Mireasa::getculoareRochie() << endl;

	/*Mireasa* mirese = new Mireasa[3];

	for (int i = 0; i < 3; i++) {
		cin >> mirese[i];
	}
	for (int i = 0; i < 3; i++) {
		cout << mirese[i];
	}*/



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


	Mireasa m4 = mireasa2;
	cout << mireasa3 << endl << m4 << endl;

	if (mireasa3 > m4) {
		cout << "da" << endl;

	}
	else {
		cout << "nu" << endl;
	}

	Mireasa m5 = m4 + 400.7;
	cout << m5;

	ofstream afis("textMireasa.txt", ios::out);
	afis << mireasa2;
	afis.close();
	ifstream cit("textMireasa.txt", ios::in);
	Mireasa m6;
	cit >> m6;
	cout << "---------------------" << m6;
	cit.close();



	Mire mire1("Albert", 2, mireasa2);
	mire1.afisareMire();
	Mire mire2("Eusebiu", 3,mireasa2);
	mire2.afisareMire();
	Mire mire3 = mire2;
	cout << mire3;
	mire2.getNume();
	cout << mire2.getMireasa();
	mire2.afisareMire();
	//Mire mire4;
	//cin >> mire4;
	/*cout << "------------------------------------------";
	fstream mireAfisare("MireOut.bin", ios::out || ios::binary);
	mireAfisare.write((char*)&mire2, sizeof(Mire));
	mireAfisare.close();*/





	Meniu meniu1;
	meniu1.afisareMeniu();

	string* numeFeluri = new string[3];
	numeFeluri[0] = "aperitiv";
	numeFeluri[1] = "sarmale";
	numeFeluri[2] = "friptura";


	Meniu meniu2(numeFeluri, 3);
	meniu2.afisareMeniu();


	Meniu meniu3(3, numeFeluri, 45.5, 32.0);
	meniu3.afisareMeniu();
	cout << "Numarul portiilor pentru aceasta nunta este de: " << Meniu::getnrPortii() << endl;

	/*Meniu* meniuri = new Meniu[3];

	for (int i = 0; i < 3; i++) {
		cin >> meniuri[i];
	}
	for (int i = 0; i < 3; i++) {
		cout << meniuri[i];
	}*/



	Meniu m1 = meniu3;
	m1.afisareMeniu();

	cout << m1.getCantitateGrame() << endl;
	m1.setCantitateGrame(245);
	cout << m1.getCantitateGrame() << endl;
	m1.setNrKilocalorii(12345);
	cout << m1.getNrKilocalorii() << endl;
	m1.setNrFeluri(3);
	cout << m1.getNrFeluri() << endl;
	string* vector2 = new string[3]{ "Mezeluri","Peste","Tort" };
	m1.setFeluri(3, vector2);
	cout << *m1.getNumeFeluri() << endl;
	cout << *(m1.getNumeFeluri() + 1) << endl;
	cout << *(m1.getNumeFeluri() + 2) << endl;
	delete[]vector2;



	cout << endl << getNumarKilocaloriiPePortie(meniu2) << endl;

	Meniu m7 = meniu2;
	cout << m7;

	if (meniu1 <= meniu3) {
		cout << "da" << endl;

	}
	else {
		cout << "nu" << endl;
	}

	cout << "Numarul de kilocalorii per suta de grame: " << meniu2() << endl;

	/*fstream meniuAfisare("MeniuOut.bin", ios::out || ios::binary);
	meniuAfisare.write((char*)&meniu3, sizeof(Meniu));
	meniuAfisare.close();
	cout << endl;*/



	Aperitiv aperitiv1;
	Aperitiv aperitiv2(15, (float)322.2);
	Aperitiv aperitiv3 = aperitiv2;
	aperitiv2.setGramaj((float)122.98);
	cout << aperitiv2.getGramaj()<<endl;

	Tort tort1;
	Tort tort2(420, "mascarpone si fructe de padure");
	cout << tort2<<endl;
	Tort tort3;
	cout << tort3<<endl;
	tort3.setUmplutura("mousse de ciocolata si vanilie");
	tort3.setNrFeluri(560);
	cout << tort3.getNrFeluri()<<endl;
	cout << tort3.getUmplutura()<<endl;







	Eveniment ev;
	ev[0] = new Meniu();
	ev[1] = new Formatie("Lala", 3, numeSolisti, 3);
	ev[2] = new Meniu(3, numeFeluri, 45.5, 32.0);
	ev[3] = new Formatie("Ala", 3, numeSolisti, 5);
	ev[4] = new Meniu(3, numeFeluri, 56.89, 67.09);
	ev[5] = new Formatie("Bambi", 3, numeSolisti, 8);
	ev[6] = new Meniu(3, numeFeluri, 23.98, 45.87);
	ev[7] = new Formatie("N&D", 3, numeSolisti, 11);
	ev[8] = new Meniu(3, numeFeluri, 12.9, 68.56);
	ev[9] = new Formatie("Asia", 3, numeSolisti, 19);

	for (int i = 0; i < 10; i++) {
		ev[i]->DescrieLocal();
		cout << endl;
	}


	



}