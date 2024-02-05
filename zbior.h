#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <new>
#include <random>
#include "zbior.h"
#include <iomanip>

using namespace std;

class Zbior
{
	size_t m_liczbaElementow = 0;
	double* m_elementy = nullptr;
	double m_dolnaGranica = 0;
	double m_gornaGranica = 0;
	void alokuj(int);
	void zwolnij();
public:
	Zbior(size_t liczElem, double dGran, double gGran);
	~Zbior() { zwolnij(); }

	Zbior(const Zbior& org);										// konstruktor kopiuj¹cy
	Zbior& operator=(Zbior&& org);									// przenosz¹cy operator przypisania

	Zbior(const Zbior&& org) = delete;								// wykluczenie konstruktora przenosz¹cego
	Zbior& operator=(const Zbior& org) = delete;					// wykluczenie kopiuj¹cego operatora = 

	double sredniaArytmetyczna() const;
};

class funktor
{
	const double tolerancja = 1e-6;									// tolerancja dla porównania zmiennoprzecinkowego
	const std::list<double>& refLista;

public:

	funktor(const std::list<double>& lista) : refLista(lista) {}
	bool operator()(double wartosc) const;
};