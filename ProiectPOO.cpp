#include<iostream>

using namespace std;
//domeniu: BASCHET
//clase: jucator, minge, teren 
class Jucator {
public:
	string nume;
	static int varstaMinima;
	const int nrJucatori; //per echipa
	float salariu; //in lei
	int* nrTricou;


	Jucator() : nrJucatori(5) {
		this->nume = "Gheorghe Muresan";
		this->salariu = 5000.5;
		this->nrTricou = new int[nrJucatori];
		for (int i = 0; i < nrJucatori; i++)
			this->nrTricou[i] = i + 20;
	}

	Jucator(string numej, float salariuj, int* nrTricouj, const int nrJucatorij) : nrJucatori(nrJucatorij) {
		this->nume = numej;
		this->salariu = salariuj;
		this->nrTricou = new int[nrJucatori];
		for (int i = 0; i < nrJucatori; i++)
			this->nrTricou[i] = i + 20;
	}

	Jucator(int* nrTricouj) : salariu(1900), nrJucatori(5), nume("Ionescu Mihai") {
		this->nrTricou = new int[nrJucatori];
		for (int i = 0; i < nrJucatori; i++)
			this->nrTricou[i] = i + 60;
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


};

int Jucator::varstaMinima = 18;

class Teren {
public:
	string locatie;
	float lungime, latime;
	int* tabelaScor;
	const int nrCosuri;
	static int inaltimeInel;

	Teren() : nrCosuri(2) {
		this->locatie = "Bucuresti";
		this->lungime = 28.5;
		this->latime = 15.3;
		this->tabelaScor = new int[2];
		this->tabelaScor[1] = 50;
		this->tabelaScor[2] = 70;
	}

	Teren(string locatie, float lungime, float latime, int* tabelaScor, const int nrCosuri) : nrCosuri(nrCosuri) {
		this->locatie=locatie;
		this->lungime = lungime;
		this->latime = latime;
		this->tabelaScor = new int[2];
		this->tabelaScor[1] = tabelaScor[1];
		this->tabelaScor[2] = tabelaScor[2];
	}
	
	Teren(int* tabelaScor) : locatie("Arad"), lungime(40), latime(20.3), nrCosuri(2) {
		this->tabelaScor = new int[2];
		this->tabelaScor[1] = 100;
		this->tabelaScor[2] = 110;
	}

	void afisareTeren() {
		cout << "Locatie: " << this->locatie << "\nLungime: " << this->lungime <<
			"\nLatime: " << this->latime << "\nNr cosuri: " << this->nrCosuri << "\nInaltime inel: "
			<<this->inaltimeInel<<endl<<"\n Scor:"<<this->tabelaScor[1]<<" - "<< this->tabelaScor[2];

		cout << endl << endl;
	}
};

int Teren::inaltimeInel = 3;

class Minge {
public:
	string producator;
	char* gradUzare;
	static int dimensiune;
	const int nrMingiRezerva;

	Minge():nrMingiRezerva(3) {
		this->producator = "Wilson";
		this->gradUzare = new char[strlen("Nou") + 1];
		strcpy_s(this->gradUzare, strlen("Nou") + 1, "Nou");
	}

	Minge(string producator, const char* gradUzare, const int mingiRezerva) : nrMingiRezerva(mingiRezerva) {
		this->producator = producator;
		this->gradUzare = new char[strlen(gradUzare)];
		strcpy_s(this->gradUzare,strlen(gradUzare)+1, gradUzare);
	}

	Minge(const char* gradUzare) : producator("Spalding"), nrMingiRezerva(5) {
		this->gradUzare = new char[strlen(gradUzare)];
		strcpy_s(this->gradUzare, strlen(gradUzare)+1, gradUzare);
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
};

int Minge::dimensiune = 7;



void main() {
	Jucator j1;
	int* nrTricou = new int[5];
	for (int i = 0;i < 5;i++)
		nrTricou[i] = i * i;
	Jucator j2("Adrian Popescu", 2000, nrTricou, 5);
	Jucator j3(nrTricou);
	j1.afisareJucator();
	j2.afisareJucator();
	j3.afisareJucator();

	Teren t1;
	int* tabelaScor = new int[2];
	for (int i = 1;i <= 2;i++)
		tabelaScor[i] = 30 + i;
	Teren t2("Cluj-Napoca", 80.9, 23, tabelaScor, 2);
	Teren t3(tabelaScor);
	t1.afisareTeren();
	t2.afisareTeren();
	t3.afisareTeren();
	
	Minge m1;
	Minge m2("Molten", "Uzat", 10);
	Minge m3("Moderat");
	m1.afisareMinge();
	m2.afisareMinge();
	m3.afisareMinge();


}
