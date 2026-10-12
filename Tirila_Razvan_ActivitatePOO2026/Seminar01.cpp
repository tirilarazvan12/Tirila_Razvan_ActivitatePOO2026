#include <iostream>

using namespace std;

struct Colectie
{
	char* denumire;
	char categorie;
	int nrElemente;
	float pret;
	bool finit;
};

void afisareColectie(Colectie c)
{
	cout << c.categorie << "\n" << c.denumire << "\n" << c.nrElemente << "\n" << c.pret << "\n" << c.finit << "\n";
}

void main() {
	std::cout << "Hello world!" << std::endl;
	Colectie c;
	c.categorie = 'A';
	c.finit = true;
	c.nrElemente = 245;
	c.pret = 4000;
	c.denumire = new char[strlen("Ceai") + 1];
	strcpy_s(c.denumire, strlen("Ceai") + 1, "Ceai");
	afisareColectie(c);
	delete[]c.denumire;
}