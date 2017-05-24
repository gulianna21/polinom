#pragma once
#include <iostream>


class Monom
{
public:
	~Monom();
	Monom::Monom(int koef = 1, size_t countVar = 0);
	bool isSumm(const Monom& monom);
	Monom operator+(Monom& monom);
	Monom operator*(Monom& monom);
	Monom& operator=(Monom& monom);
	bool operator==(const Monom& monom);
	int& operator[](size_t index);
	int getKoef();
	void getKoef(int koef);
	friend std::ostream& operator<<(std::ostream& os, Monom& m);

private:
	int koef;
	size_t countVar;
	int *stepen;
};

Monom::Monom(int koef, size_t countVar)
{
	this->koef = koef;
	this->countVar = countVar;
	stepen = new int[countVar];
}
Monom& Monom::operator=(Monom& monom)
{
	this->koef = monom.koef;
	this->countVar = monom.countVar;
	stepen = new int[countVar];
	for (size_t i = 0; i < countVar; i++)
		stepen[i] = monom[i];
	return *this;
}
bool Monom::operator==(const Monom& monom)
{
	if (isSumm(monom) && koef == monom.koef)
		return true;
	return false;
}

int& Monom::operator[](size_t index)
{
	if (index >= countVar)
		throw 2;
	return stepen[index];
}

inline int Monom::getKoef()
{
	return koef;
}

inline void Monom::getKoef(int koef)
{
	this->koef = koef;
}

std::ostream& operator<<(std::ostream & os, Monom & m)
{
	os << m.koef<<"*";
	for (size_t i = 0; i < m.countVar; i++)
	{
		if (m[i] != 0)
		{
			os << "x(" << i << ")^" << m[i];
		}
	}

	return os;
}

Monom Monom::operator+(Monom& monom)
{
	if (!isSumm(monom))
		throw 1;

	size_t min = countVar < monom.countVar ? countVar : monom.countVar;
	Monom tmp(koef + monom.koef, min);
	for (size_t i = 0; i < min; i++)
		tmp[i] = monom[i];

	return tmp;
}

Monom Monom::operator*(Monom& monom)
{

	size_t max = countVar > monom.countVar ? countVar : monom.countVar;
	size_t min = countVar < monom.countVar ? countVar : monom.countVar;
	Monom tmp(koef*monom.koef, max);
	for (size_t i = 0; i < min; i++)
		tmp[i] = monom[i] + stepen[i];

	for (size_t i = min; i < max; i++)
	{
		if (countVar > monom.countVar)
			tmp[i] = monom[i];
		else
			tmp[i] = stepen[i];
	}
		
	return tmp;
}


bool Monom::isSumm(const Monom& monom)
{
	int end = 0;
	for (size_t i = 0; i < countVar && i <monom.countVar; i++)
	{
			if (stepen[i] != monom.stepen[i])
				return false;
			end = i;
	}

	if (countVar>monom.countVar)
		for (size_t i = end; i < countVar; i++)
		{
			if (stepen[i] != 0)
				return false;
		}

	if (countVar<monom.countVar)
		for (size_t i = end; i < monom.countVar; i++)
		{
			if (monom.stepen[i] != 0)
				return false;
		}

	return true;
}

Monom::~Monom()
{
	if (stepen == 0)
		delete[] stepen;
}