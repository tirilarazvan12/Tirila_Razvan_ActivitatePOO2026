#include <iostream>
using namespace std;

class Telefon
{
private:
	float rezolutie;
	float memorie;
	string model;
	char* producator;
	float pret;
	int nrAplicatii;
	float* memorieAplicatii;
	const int id;
	static int contor;
public:
	Telefon():id(contor++)
	{
		this->rezolutie = 5.3;
		this->memorie = 128;
		this->model = "Iphone 18";
		this->producator = new char[strlen("Apple") + 1];
		strcpy_s(producator, strlen("Apple") + 1, "Apple");
		this->pret = 4000;
		this->nrAplicatii = 5;
		this->memorieAplicatii = new float[this->nrAplicatii];
		this->memorieAplicatii[0] = 2;
		this->memorieAplicatii[1] = 3;
		this->memorieAplicatii[2] = 1.4;
		this->memorieAplicatii[3] = 1.6;
		this->memorieAplicatii[4] = 2.4;
	}

	Telefon(float rezolutie, float memorie): id(contor++)
	{
		this->rezolutie = rezolutie;
		this->memorie = memorie;
		this->model = "Iphone 18";
		this->producator = new char[strlen("Apple") + 1];
		strcpy_s(producator, strlen("Apple") + 1, "Apple");
		this->pret = 4000;
		this->nrAplicatii = 5;
		this->memorieAplicatii = new float[this->nrAplicatii];
		this->memorieAplicatii[0] = 2;
		this->memorieAplicatii[1] = 3;
		this->memorieAplicatii[2] = 1.4;
		this->memorieAplicatii[3] = 1.6;
		this->memorieAplicatii[4] = 2.4;
	}

	Telefon(const Telefon& t): id(contor++)
	{
		this->rezolutie = t.rezolutie;
		this->memorie = t.memorie;
		this->model = t.model;
		this->producator = new char[strlen(t.producator) + 1];
		strcpy_s(producator, strlen(t.producator) + 1, t.producator);
		this->pret = t.pret;
		this->nrAplicatii = t.nrAplicatii;
		this->memorieAplicatii = new float[this->nrAplicatii];
		for (int i = 0; i < this->nrAplicatii; i++)
			this->memorieAplicatii[i] = t.memorieAplicatii[i];
	}

	~Telefon()
	{
		delete[] producator;
		delete[] memorieAplicatii;
	}

	float getPret()
	{
		return this->pret;
	}

	void setPret(float pret);


	int getNrAplicatii()
	{
		return this->nrAplicatii;
	}

	char* getProducator()
	{
		return this->producator;
	}

	void setProducator(const char* producator)
	{
		delete[] this->producator;
		this->producator = new char[strlen(producator) + 1];
		strcpy_s(this->producator, strlen(producator)+1, producator);
	}


	void afisare()
	{
		cout << '\n';
		cout << "Rezolutie: " << this->rezolutie << '\n';
		cout << "Memorie: " << this->memorie << '\n';
		cout << "Model: " << this->model << '\n';
		cout << "Producator: " << this->producator << '\n';
		cout << "Pret: " << this->pret << '\n';
		cout << "Nr aplicatii: " << this->nrAplicatii << '\n';
		cout << "Memorie aplicatii: ";
		for (int i = 0; i < this->nrAplicatii; i++)
			cout << this->memorieAplicatii[i] << "; ";
		cout << '\n';
	}

	float calculeazaMemorieOcupata()
	{
		float sumaMemorie = 0;
		for (int i = 0; i < this->nrAplicatii; i++)
			sumaMemorie += this->memorieAplicatii[i];
		return sumaMemorie;
	}

	float calculeazaMemorieLibera()
	{
		return memorie - this->calculeazaMemorieOcupata();
	}

	void modificaProducator(const char* producatorNou)
	{
		delete[] this->producator;
		producator = new char[strlen(producatorNou) + 1];
		strcpy_s(producator, strlen(producatorNou) + 1, producatorNou);
	}
};

int Telefon::contor = 1000;

float calcularePretTotal(Telefon* v, int nrTelefoane)
{
	float suma = 0;
	for (int i = 0; i < nrTelefoane; i++)
		suma += v[i].getPret();
	return suma;
}

float calculeazaMemorieDisponibila(Telefon* g, int nrTelefoane)
{
	float suma = 0;
	for (int i = 0; i < nrTelefoane; i++)
		suma += g[i].calculeazaMemorieLibera();
	return suma;
}

float calculeazaPretPerAplicatie(Telefon &x)
{
	if (x.getNrAplicatii() == 0)
		return 0;
	else 
	    return x.getPret() / x.getNrAplicatii();
}


void Telefon::setPret(float pret)
{
	this->pret = pret;
}

void main()
{
	
	Telefon t;
	Telefon t2(t);
	Telefon t3 = t;
	cout << calculeazaPretPerAplicatie(t);
}