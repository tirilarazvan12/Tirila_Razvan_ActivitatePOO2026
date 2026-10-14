#include <iostream>
using namespace std;

class Telefon
{
public:
	float rezolutie;
	float memorie;
	string model;
	char* producator;
	float pret;
	int nrAplicatii;
	float* memorieAplicatii;

	Telefon()
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

	Telefon(float rezolutie, float memorie)
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

float calcularePretTotal(Telefon* v, int nrTelefoane)
{
	float suma = 0;
	for (int i = 0; i < nrTelefoane; i++)
		suma += v[i].pret;
	return suma;
}

float calculeazaMemorieDisponibila(Telefon* g, int nrTelefoane)
{
	float suma = 0;
	for (int i = 0; i < nrTelefoane; i++)
		suma += g[i].calculeazaMemorieLibera();
	return suma;
}

void main()
{
	Telefon t;
	t.afisare();
	cout << '\n' << "Spatiu liber: " << t.calculeazaMemorieLibera() << endl;

	Telefon t1(5.6, 256);
	t1.afisare();
	cout << '\n' << "Spatiu liber: " << t1.calculeazaMemorieLibera() << endl;

	Telefon* telefoane = new Telefon[4];
	telefoane[1].modificaProducator("Samsung");
	telefoane[0].modificaProducator("Xiaomi");
	telefoane[2].modificaProducator("Honour");

	for (int i = 0; i < 4; i++)
		telefoane[i].afisare();

	cout << '\n' << "Pret total telefoane: " << calcularePretTotal(telefoane, 4) << endl;
	cout << '\n' << "Memorie disponibila totala: " << calculeazaMemorieDisponibila(telefoane, 4) << endl;
}