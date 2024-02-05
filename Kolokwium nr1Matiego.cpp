#include "zbior.h"
using namespace std;

int main()
{
	list<Zbior> listaZbiorow;

	random_device generator;
	uniform_int_distribution<> przedzialListy(10, 20);

	double dolnaG = 1.0;
	double gornaG = 5.0;

	size_t liczbaZbiorow = przedzialListy(generator);					// Losowa liczba zbiorów (10-20)

	for (int i = 0; i < liczbaZbiorow; i++)
	{
		size_t liczbaElementow = przedzialListy(generator);
		Zbior nowyZbior(liczbaElementow, dolnaG, gornaG);
		listaZbiorow.push_back(nowyZbior);
	}

	for (auto& zbior : listaZbiorow)
	{
		double srednia = zbior.sredniaArytmetyczna();
		cout << "Srednia arytm.: " << srednia << endl;
	}
	cout << endl;


	list<double> lista = { 1.1, 2.2, 3.31, 4.4, 5.500001 };

	cout << "Elementy listy: ";
	for (const auto& element : lista)
		cout << setprecision(8) << element << " ";

	cout << endl;

	list<double> testWartosc = { 5.5000019 };

	cout << "Wartosc szukana: ";
	for (const auto& element : testWartosc)
		cout << setprecision(8) << element << " ";
	cout << "z tolerancja: 10^-6" << endl;

	funktor fn(lista);

	auto znajdz = find_if(testWartosc.begin(), testWartosc.end(), fn);

	if (znajdz != testWartosc.end())
		cout << "Wartosc znaleziona na liscie!" << endl;
	else
		cout << "Wartosc nie znaleziona na liscie!" << endl;
}