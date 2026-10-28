#include <iostream>
using namespace std;

class Telefon {
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
	friend class Student;
	Telefon() : id(contor++)
	{
		this->rezolutie = 5.3;
		this->memorie = 128;
		this->model = "iPhone 17";
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


	Telefon(float rezolutie, float memorie) : id(contor++)
	{
		this->rezolutie = rezolutie;
		this->memorie = memorie;
		this->model = "iPhone 17";
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

	Telefon(const Telefon& t) : id(contor++)
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
		{
			this->memorieAplicatii[i] = t.memorieAplicatii[i];
		}
	}

	~Telefon()
	{
		delete[] producator;
		delete[] memorieAplicatii;
	}

	Telefon& operator=(const Telefon& t) {
		if (this != &t) {
			this->rezolutie = t.rezolutie;
			this->memorie = t.memorie;
			this->model = t.model;
			if (this->producator != NULL)
				delete[] this->producator;
			this->producator = new char[strlen(t.producator) + 1];
			strcpy_s(producator, strlen(t.producator) + 1, t.producator);
			this->pret = t.pret;
			this->nrAplicatii = t.nrAplicatii;
			if (this->memorieAplicatii != NULL)
				delete[] this->memorieAplicatii;
			this->memorieAplicatii = new float[this->nrAplicatii];
			for (int i = 0; i < this->nrAplicatii; i++)
			{
				this->memorieAplicatii[i] = t.memorieAplicatii[i];
			}
		}
		return *this;
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
		strcpy_s(this->producator, strlen(producator) + 1, producator);
	}

	Telefon operator+(const Telefon& t) {
		Telefon result = *this;
		result.pret = this->pret + t.pret;
		return result;
	}

	Telefon operator+(float crestere) const {
		Telefon result = *this;
		result.pret = this->pret + crestere;
		return result;
	}

	friend Telefon operator+(float crestere, Telefon t) {
		Telefon result = t;
		t.setPret(t.getPret() + crestere);
		return result;
	}


	void afisare() {
		cout << "Rezolutie: " << this->rezolutie << "\n";
		cout << "Memorie: " << this->memorie << "\n";
		cout << "Model: " << this->model << "\n";
		cout << "Producator: " << this->producator << "\n";
		cout << "Pret: " << this->pret << "\n";
		cout << "Numar aplicatii: " << this->nrAplicatii << "\n";
		cout << "Memorie ocupata aplicatii: ";
		for (int i = 0; i < this->nrAplicatii; i++)
			cout << this->memorieAplicatii[i] << "; ";
		cout << endl;
	}

	float calculeazaMemorieOcupata() {
		float sumaMemorie = 0;
		for (int i = 0; i < this->nrAplicatii; i++)
			sumaMemorie += memorieAplicatii[i];
		return sumaMemorie;
	}

	float calculeazaMemorieLibera() {
		return memorie - calculeazaMemorieOcupata();
	}

	void modificaProducator(const char* producatorNou) {
		delete[]this->producator;
		producator = new char[strlen(producatorNou) + 1];
		strcpy_s(producator, strlen(producatorNou) + 1, producatorNou);
	}

};
int Telefon::contor = 1000;



float calcularePretTotal(Telefon* v, int nrTelefoane) {
	float suma = 0;
	for (int i = 0; i < nrTelefoane; i++)
		suma += v[i].getPret();
	return suma;
}

float calculeazaMemorieDisponibila(Telefon* g, int nrTelefoane) {
	float suma = 0;
	for (int i = 0; i < nrTelefoane; i++)
		suma += g[i].calculeazaMemorieLibera();
	return suma;
}

float calculeazaPretPerAplicatie(Telefon x)
{
	if (x.getNrAplicatii() == 0)
	{
		return 0;
	}
	else
	{
		return x.getPret() / x.getNrAplicatii();
	}
}

void Telefon::setPret(float pret)
{
	this->pret = pret;
}

class Student {
	string nume;
	Telefon telefon;
public:
	Student() {
		nume = "Popescu";
	}
	Student(string nume, Telefon telefon) {
		this->nume = nume;
		this->telefon = telefon;
	}

	string getNume() {
		return this->nume;
	}

	void setNume(string nume) {
		this->nume = nume;
	}

	Telefon getTelefon() {
		return this->telefon;
	}

	void setTelefon(const Telefon& t) {
		this->telefon = t;
	}

	bool poateInstalaAplicatia(float memorieNecesara) {
		return (memorieNecesara <= this->telefon.calculeazaMemorieLibera());
	}

	void afisareInformatii() {
		cout << this->nume << " are un telefon cu " << this->telefon.memorie << " GB memorie";
	}
};

void main() {

	Telefon t;
	Telefon t2(6.3, 512);
	Telefon t3 = t;
	t = t2;
	t2 = t2;

	Telefon t4 = t2 + t;
	Telefon t5 = t2 + 10;
	Telefon t6 = 10 + t2;

	cout << t2.getProducator() << endl;
	cout << calculeazaPretPerAplicatie(t) << endl;
	Student student("Andrei", t2);
	cout << student.getNume() << endl;
	cout << student.getTelefon().getProducator() << endl;
	student.afisareInformatii();
}