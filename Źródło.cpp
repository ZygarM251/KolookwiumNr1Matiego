#include "zbior.h"
void Zbior::alokuj(int n)
{
	if (n > 0)
	{
		m_elementy = new(std::nothrow) double[n];
		m_liczbaElementow = n;
	}
}

void Zbior::zwolnij()
{
	if (m_elementy != nullptr)
	{
		delete[] m_elementy;
		m_elementy = nullptr;
	}
}

Zbior::Zbior(size_t liczElem, double dGran, double gGran)
{
	alokuj(liczElem);
	std::uniform_real_distribution<double> zakres(dGran, gGran);
	std::random_device generator;
	for (int elem = 0; elem < liczElem; elem++)
		m_elementy[elem] = zakres(generator);
}

// konstruktor kopiuj¹cy
Zbior::Zbior(const Zbior& org) : m_liczbaElementow(org.m_liczbaElementow), m_dolnaGranica(org.m_dolnaGranica), m_gornaGranica(org.m_gornaGranica)
{
	if (org.m_elementy != nullptr)
	{
		alokuj(org.m_liczbaElementow);
		for (int i = 0; i < m_liczbaElementow; i++)
			this->m_elementy[i] = org.m_elementy[i];
	}
}

Zbior& Zbior::operator=(Zbior&& org)
{
	if (this != &org)
	{
		if (this->m_elementy != nullptr)
			zwolnij();
		this->m_elementy = org.m_elementy;
		this->m_liczbaElementow = org.m_liczbaElementow;
		org.m_elementy = nullptr;
	}
	return *this;
}

double Zbior::sredniaArytmetyczna() const
{
	if (m_liczbaElementow == 0 || m_elementy == nullptr)
		return 0.0;

	double suma = 0.0;
	for (int i = 0; i < m_liczbaElementow; i++)
	{
		suma += m_elementy[i];
	}

	return suma / m_liczbaElementow;
}

bool funktor::operator()(double wartosc) const
{
	for (double element : refLista)
	{
		if (fabs(element - wartosc) <= tolerancja)
			return true;
	}
	return false;
}