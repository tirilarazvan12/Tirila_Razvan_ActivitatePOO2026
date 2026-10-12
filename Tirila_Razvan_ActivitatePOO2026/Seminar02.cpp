#include <iostream>

using namespace std;

struct Ghiozdan {
	float lungime;
	int nrBuzunare;
	bool laptop;
	char* producator;
};

Ghiozdan citireGhio() {
	char numeProducator[10];
	Ghiozdan g;
	cout << "Lungime= ";
	cin >> g.lungime;
	cout << "Numar Buzunare= ";
	cin >> g.nrBuzunare;
	cout << "Pt laptop? (0/1) ";
	cin >> g.laptop;
	cout << "Producator= ";
	cin >> numeProducator;
	g.producator = new char[strlen(numeProducator) + 1];
	strcpy_s(g.producator, strlen(numeProducator) + 1, numeProducator);
	return g;
}

void afisareGhiozdan(Ghiozdan g) {
	cout << "Lungime: " << g.lungime << "\n";
	cout << "Numar Buzunare: " << g.nrBuzunare << "\n";
	cout << "Laptop: " << g.laptop << "\n";
	cout << "Nume producator: " << g.producator << "\n";
}

void modificareLungime(Ghiozdan* g, int lungimeNoua) {
	(*g).lungime = lungimeNoua;
}

int sumaBuzunare(Ghiozdan* ghiozdane, int nrGhiozdane) {
	int suma = 0;
	for (int i = 0; i < nrGhiozdane; i++) {
		suma += ghiozdane[i].nrBuzunare;
	}

	return suma;
}

void main() {
	Ghiozdan g = citireGhio();
	afisareGhiozdan(g);
	modificareLungime(&g, 12);
	afisareGhiozdan(g);

	int nrGhiozdane = 3;
	Ghiozdan* ghiozdane;
	ghiozdane = new Ghiozdan[3];
	for (int i = 0; i < nrGhiozdane;i++) {
		ghiozdane[i] = citireGhio();
	}

	for (int i = 0; i < nrGhiozdane; i++) {
		afisareGhiozdan(ghiozdane[i]);
	}

	cout << "Numarul total de buzunare= " << sumaBuzunare(ghiozdane, nrGhiozdane);

}