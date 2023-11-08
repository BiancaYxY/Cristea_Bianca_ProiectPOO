#include<iostream>

using namespace std;
//domeniu: BASCHET
//clase: jucator, minge, teren 
class Jucator {
private:
	string nume;
	static int varstaMinima;
	const int nrJucatori; //per echipa
	float salariu; //in lei
	int* nrTricou;
public:

	//constructor default
	Jucator() : nrJucatori(5) {
		this->nume = "Gheorghe Muresan";
		this->salariu = 5000.5;
		this->nrTricou = new int[nrJucatori];
		for (int i = 0; i < nrJucatori; i++)
			this->nrTricou[i] = i + 20;
	}

	//constructor cu toti parametrii
	Jucator(string numej, float salariuj, int* nrTricouj, const int nrJucatorij) : nrJucatori(nrJucatorij) {
		this->nume = numej;
		this->salariu = salariuj;
		this->nrTricou = new int[nrJucatori];
		for (int i = 0; i < nrJucatori; i++)
			this->nrTricou[i] = i + 20;
	}

	//constructor cu 1 parametru
	Jucator(int* nrTricouj) : salariu(1900), nrJucatori(5), nume("Ionescu Mihai") {
		this->nrTricou = new int[nrJucatori];
		for (int i = 0; i < nrJucatori; i++)
			this->nrTricou[i] = i + 60;
	}

	//copy constructor
	Jucator(const Jucator& j1) : nrJucatori(j1.nrJucatori) {
		this->nume = j1.nume;
		this->salariu = j1.salariu;
		this->nrTricou = new int[nrJucatori];
		for (int i = 0;i < this->nrJucatori;i++) {
			this->nrTricou[i] = j1.nrTricou[i];
		}
	}

	static void ModificareVarsta(int varstaNoua) {
		varstaMinima = varstaNoua;
	}

	void afisareJucator() {
		cout << "Nume jucator: " << this->nume << "\nVarsta minima: " << this->varstaMinima <<
			"\nNr jucatori: " << this->nrJucatori << "\nSalariu: " << this->salariu << "\n Numere de pe tricou: ";
		for (int i = 0;i < this->nrJucatori - 1;i++) {
			cout << this->nrTricou[i] << " ";
		}
		cout << endl<<endl;
	}
	~Jucator() {
		if (this->nrTricou != NULL) {
			delete[]this->nrTricou;
		}
	}

	//Getters
	string getnume() {
		return this->nume;
	}

	static int getvarstaMinima() {
		return varstaMinima;
	}

	const int getnrJucatori() {
		return nrJucatori;
	}

	float getsalariu() {
		return this->salariu;
	}

	int* getnrTricou() {
		return this->nrTricou;
	}

	//Setters
	void setnume(string numeS) {
		if(numeS!=" ")
		this->nume = numeS;
	}

	static void setvarstaMinima(static int varstaMinimaS) {
		if (varstaMinimaS > 18)
			varstaMinima = varstaMinimaS;
	}

	void setsalariu(float salariuS) {
		if (salariuS > 0) {
			this->salariu = salariuS;
		}
	}

	void setnrTricou(int* nrTricouS) {
		if (this->nrTricou != NULL) {
			delete[]this->nrTricou;
		}
		this->nrTricou = new int[nrJucatori];
		for (int i = 0;i < nrJucatori;i++) {
			if (nrTricouS[i] >= 0)
				this->nrTricou[i] = nrTricouS[i];
		}
	}
	//apelare functie prieten
	friend void afisareJucatoriFriend(Jucator j1);

	//supraincarcare operator = 
	Jucator& operator=(const Jucator& j1) {
		if (this != &j1) {
			this->nume = j1.nume;
			this->salariu = j1.salariu;
			if (this->nrTricou != NULL) {
				delete[]this->nrTricou;
			}
			this->nrTricou = new int[this->nrJucatori];

			for (int i = 0;i < j1.nrJucatori;i++) {
				this->nrTricou[i] = j1.nrTricou[i];
			}
		}

			return *this;
		}

		//supraincarcare operator >>
		 friend istream& operator>>(istream& citire, Jucator& j) {
			 cout << "Nume jucator: "; citire >> j.nume;
			cout << "Salariu jucator: "; citire >> j.salariu; 
			if (j.nrTricou != NULL) {
				delete[]j.nrTricou;
			}
			j.nrTricou = new int[j.nrJucatori];
			cout << "Nr de pe tricouri jucatori:"; 
			for (int i = 0;i < j.nrJucatori;i++) {
				citire >> j.nrTricou[i];
			}
			return citire;
	     }

		 //supraincarcare operator <<
		 friend ostream& operator<<(ostream& cons, const Jucator& j) {
			 cout << "Nume jucator: " << j.nume << "\nVarsta minima: " << j.varstaMinima <<
				 "\nNr jucatori: " << j.nrJucatori << "\nSalariu: " << j.salariu << "\n Numere de pe tricou: ";
			 for (int i = 0;i < j.nrJucatori;i++) {
				 cout << j.nrTricou[i] << " ";
			 }
			 cout << endl << endl;
			 return cons;
		 }

		 //supraincarcare preincrementare
		  Jucator operator++() {
			 this->salariu += 1000;
			 return *this;
		 }
};

int Jucator::varstaMinima = 18;

void afisareJucatoriFriend(Jucator j1) {
	cout << "Nume jucator: " << j1.nume << "\nVarsta minima: " << j1.varstaMinima <<
		"\nNr jucatori: " << j1.nrJucatori << "\nSalariu: " << j1.salariu << "\n Numere de pe tricou: ";
	for (int i = 0;i < j1.nrJucatori - 1;i++) {
		cout << j1.nrTricou[i] << " ";
	}
	cout << endl << endl;
}
class Teren {
private:
	string locatie;
	float lungime, latime;
	int* tabelaScor;
	const int nrCosuri;
	static int inaltimeInel;

public:
	
	//constructor default
	Teren() : nrCosuri(2) {
		this->locatie = "Bucuresti";
		this->lungime = 28.5;
		this->latime = 15.3;
		this->tabelaScor = new int[2];
		this->tabelaScor[0] = 50;
		this->tabelaScor[1] = 70;
	}

	//constructor cu toti parametrii
	Teren(string locatie, float lungime, float latime, int* tabelaScor, const int nrCosuri) : nrCosuri(nrCosuri) {
		this->locatie=locatie;
		this->lungime = lungime;
		this->latime = latime;
		this->tabelaScor = new int[2];
		this->tabelaScor[0] = tabelaScor[0];
		this->tabelaScor[1] = tabelaScor[1];
	}
	
	//constructor cu un parametru
	Teren(int* tabelaScor) : locatie("Arad"), lungime(40), latime(20.3), nrCosuri(2) {
		this->tabelaScor = new int[2];
		this->tabelaScor[0] = 100;
		this->tabelaScor[1] = 110;
	}

	//destructor
	~Teren() {
		if (this->tabelaScor != NULL) {
			delete[]this->tabelaScor;
		}
	}

	//copy constructor
	Teren(const Teren &t1) :nrCosuri(t1.nrCosuri) {
		this->locatie = t1.locatie;
		this->lungime = t1.lungime;
		this->latime = t1.latime;
		this->tabelaScor = new int[2];
		for (int i = 0;i <= 1;i++) {
			this->tabelaScor[i] = t1.tabelaScor[i];
		}
	}

	//Getters
	string getlocatie() {
		return this->locatie;
	}

	float getlungime() {
		return this->lungime;
	}

	float getlatime() {
		return this->latime;
	}

	int* gettabelaScor() {
		return this->tabelaScor;
	}

	const int getnrCosuri() {
		return nrCosuri;
	}

	static int getinaltimeInel() {
		return inaltimeInel;
	}

	//Setters
	void setlocatie(string locatieS) {
		if (locatieS != " ") {
			this->locatie = locatieS;
		}
	}

	void setlungime(float lungimeS) {
		if (lungimeS > 0) {
			this->lungime = lungimeS;
		}
	}

	void setlatime(float latimeS) {
		if (latimeS > 0) {
			this->latime = latimeS;
		}
	}

	void settabelaScor(int* tabelaScorS) {
		if (this->tabelaScor != NULL) {
			delete[]this->tabelaScor;
		}
		this->tabelaScor = new int[2];
		for (int i = 0;i < 2;i++) {
			if (tabelaScorS[i] > 0)
				this->tabelaScor[i] = tabelaScorS[i];
		}
	}


	void afisareTeren() {
		cout << "Locatie: " << this->locatie << "\nLungime: " << this->lungime <<
			"\nLatime: " << this->latime << "\nNr cosuri: " << this->nrCosuri << "\nInaltime inel: "
			<<this->inaltimeInel<<endl<<"\n Scor:"<<this->tabelaScor[0]<<" - "<< this->tabelaScor[1];

		cout << endl << endl;
	}
	friend void afisareTerenFriend(Teren t1);

	//supraincarcare operator=
	Teren& operator=(const Teren& t) {
		if (this!= &t) {
			this->locatie = t.locatie;
			this->latime = t.latime;
			this->lungime = t.lungime;
			if (this->tabelaScor != NULL) {
				delete[]this->tabelaScor;
			}
			this->tabelaScor = new int[2];
			for (int i = 0;i < 2;i++) {
				this->tabelaScor[i] = t.tabelaScor[i];
			}
		}
		return *this;
	}

	//supraincarcare operator>>
	friend istream& operator>>(istream& citire, Teren& t) {
		cout << "Locatie teren:"; citire >> t.locatie;
		cout << "Lungime teren:"; citire >> t.lungime;
		cout << "Latime teren:"; citire >> t.latime;
		cout << "Scor:";
		if (t.tabelaScor != NULL) {
			delete[]t.tabelaScor;
		}
		t.tabelaScor = new int[2];
		for (int i = 0;i < 2;i++) {
			citire>>t.tabelaScor[i];
		}
		cout << endl;
		return citire;
	}

	//supraincarcare operator<<
	friend ostream& operator<<(ostream& cons, Teren& t) {
		cout << "Locatie: " << t.locatie << "\nLungime: " << t.lungime <<
			"\nLatime: " << t.latime << "\nNr cosuri: " << t.nrCosuri << "\nInaltime inel: "
			<< t.inaltimeInel << endl << "\n Scor:" << t.tabelaScor[0] << " - " << t.tabelaScor[1];
		cout << endl << endl;
		return cons;
	}

	//supraincarcare operator++
	Teren operator++() {
		Teren aux;
		aux = *this;
		this->lungime += 100;
		this->latime += 50;
		return *this;
	}

};

void afisareTerenFriend(Teren t1) {
		cout << "Locatie: " << t1.locatie << "\nLungime: " << t1.lungime <<
			"\nLatime: " << t1.latime << "\nNr cosuri: " << t1.nrCosuri << "\nInaltime inel: "
			<< t1.inaltimeInel << endl << "\n Scor:" << t1.tabelaScor[0] << " - " << t1.tabelaScor[1];
		cout << endl << endl;
}

int Teren::inaltimeInel = 3;

class Minge {
private:
	string producator;
	char* gradUzare;
	static int dimensiune;
	const int nrMingiRezerva;
public:
	//constructor default
	Minge():nrMingiRezerva(3) {
		this->producator = "Wilson";
		this->gradUzare = new char[strlen("Nou") + 1];
		strcpy_s(this->gradUzare, strlen("Nou") + 1, "Nou");
	}

	//constructor cu toti parametrii
	Minge(string producator, const char* gradUzare, const int mingiRezerva) : nrMingiRezerva(mingiRezerva) {
		this->producator = producator;
		this->gradUzare = new char[strlen(gradUzare)+1];
		strcpy_s(this->gradUzare,strlen(gradUzare)+1, gradUzare);
	}

	//constructor cu un parametru
	Minge(const char* gradUzare) : producator("Spalding"), nrMingiRezerva(5) {
		this->gradUzare = new char[strlen(gradUzare)+1];
		strcpy_s(this->gradUzare, strlen(gradUzare)+1, gradUzare);
	}

	//copy constructor
	Minge(const Minge& m1): nrMingiRezerva(m1.nrMingiRezerva) {
		this->producator = m1.producator;
		this->gradUzare = new char[strlen(m1.gradUzare) + 1];
		strcpy_s(this->gradUzare, strlen(m1.gradUzare) + 1, m1.gradUzare);
	}

	static void ModificareDimensiune(int dimensiuneNoua) {
		dimensiune = dimensiuneNoua;
	}

	void afisareMinge() {
		cout << "Producator: " << this->producator << "\nGrad uzare: " << this->gradUzare <<
			"\nNr mingi rezerva: " << this->nrMingiRezerva << "\nDimensiune: " << this->dimensiune <<endl<<endl;
	}


	~Minge() {
		if (this->gradUzare != NULL) {
			delete[]this->gradUzare;
		}
	}

	//Getters
	string getproducator() {
		return this->producator;
	}

	char* getgradUzare() {
		return this->gradUzare;
	}
	
	static int getdimensiune() {
		return dimensiune;
	}

	const int getnrMingiRezerva() {
		return nrMingiRezerva;
	}

	//Setters
	void setproducator(string producatorS) {
		if (producatorS != " ") {
			this->producator = producatorS;
		}
	}

	void setgradUzare(const char* gradUzareS) {
		if (this->gradUzare != NULL) {
			delete[]this->gradUzare;
			
			this->gradUzare = new char[strlen(gradUzareS) + 1];
			strcpy_s(this->gradUzare, strlen(gradUzareS) + 1, gradUzareS);
		}
	}

	//supraincarcare operator=
	Minge& operator=(const Minge& m) {
		if (&m != this) {
			this->producator = m.producator;
			if (this->gradUzare != NULL) {
				delete[]this->gradUzare;
			}
			this->gradUzare = new char[strlen(m.gradUzare) + 1];
			strcpy_s(this->gradUzare, strlen(m.gradUzare) + 1, m.gradUzare);
		}
		return *this;
	}

	//supraincarcare operator>>
	friend istream& operator>>(istream& citire, Minge& m) {
		cout << "Producator:"; citire >> m.producator;
		if (m.gradUzare != NULL) {
			delete[]m.gradUzare;
		}
		m.gradUzare = new char[9];
		citire >> m.gradUzare;
		return citire;
	}

	//supraincarcare operator<<
	friend ostream& operator<<(ostream& cons, Minge& m) {
		cout << "Producator: " << m.producator << "\nGrad uzare: " << m.gradUzare <<
			"\nNr mingi rezerva: " << m.nrMingiRezerva << "\nDimensiune: " << m.dimensiune << endl << endl;
		return cons;
	}

	//supraincarcare operator++
	Minge operator++() {
		Minge aux=*this;
		this->producator="necunoscut";
		return *this;
	}


};

int Minge::dimensiune = 7;



void main() {
	Jucator j1; //default constructor
	int* nrTricou = new int[5];
	for (int i = 0;i < 5;i++)
		nrTricou[i] = i * i;
	Jucator j2("Adrian Popescu", 2000, nrTricou, 5); //constructor cu toti parametrii
	Jucator j3(nrTricou); //constructor cu 1 parametru
	Jucator j4(j3); //copy constructor
	j1.afisareJucator();
	j2.afisareJucator();
	j3.afisareJucator();
	j4.afisareJucator();

	//Setters Jucator
	Jucator j5;
	j5.setnume("Lebron James");
	j5.setsalariu(100000);
	j5.setnrTricou(nrTricou);

	//Getters Jucator
	cout << "Nume jucator: " << j5.getnume() << endl;
	cout << "Nr jucatori: " << j5.getnrJucatori() << endl;
	cout << "Nr de pe tricouri: ";


	for (int i = 0;i < j5.getnrJucatori();i++) {
	cout<< j5.getnrTricou()[i] <<" ";
	}
	cout << endl;
	cout << "Salariu jucator: " << j5.getsalariu() << endl;
	cout << "Varsta minima: " << j5.getvarstaMinima() << endl;

	Teren t1;
	int* tabelaScor = new int[2];
	for (int i = 0;i <= 1;i++)
		tabelaScor[i] = 30 + i;
	Teren t2("Cluj-Napoca", 80.9, 23, tabelaScor, 2);
	Teren t3(tabelaScor);
	Teren t4(t3);
	t1.afisareTeren();
	t2.afisareTeren();
	t3.afisareTeren();
	t4.afisareTeren();

	//Setters Teren
	Teren t5;
	t5.setlatime(20);
	t5.setlungime(70);
	t5.setlocatie("Timisioara");
	t5.settabelaScor(tabelaScor);

	//Getters Teren
	cout << "Locatie: " << t5.getlocatie() << endl;
	cout << "Latime teren: " << t5.getlatime() << endl;
	cout << "Lungime teren: " << t5.getlungime() << endl;
	cout << "Scor: "<<t5.gettabelaScor()[0]<<"  "<< t5.gettabelaScor()[1]<<endl;
	cout << "Nr cosuri:" << t5.getnrCosuri()<<endl;
	cout << "Inaltime inel: " << t5.getinaltimeInel()<<endl;

	
	
	Minge m1;
	Minge m2("Molten", "Uzat", 10);
	Minge m3("Moderat");
	Minge m4(m3);
	m1.afisareMinge();
	m2.afisareMinge();
	m3.afisareMinge();
	m4.afisareMinge();
	
	//Setters
	Minge m5;
	m5.setgradUzare("Degradat");
	m5.setproducator("Decathlon");

	//Getters
	cout << "Producator: " << m5.getproducator() << endl;
	cout << "Grad Uzare: " << m5.getgradUzare() << endl;
	cout << "Dimensiune: " << m5.getdimensiune() << endl;
	cout << "Nr mingi rezerva: " << m5.getnrMingiRezerva() << endl;
	
	//supraincarcare operatori Jucator
	cout << "OPERATORI JUCATOR\n";
	j1 = j3; 
	j1.afisareJucator();
	Jucator j6;
	cin >> j6;
	cout << j6;
	++j6;
	cout << j6;

	//supraincarcare operatori Teren
	cout << "OPERATORI TEREN\n";
	t1 = t2;
	Teren t6;
	cin >> t6;
	cout << t6;
	++t6;
	cout << t6;

	//supraincarcae operatori Minge
	cout << "OPERATORI MINGE\n";
	m1 = m2;
	cout << m1;
	Minge m6;
	cin >> m6;
	cout << m6;
	++m6;
	cout << m6;
}
