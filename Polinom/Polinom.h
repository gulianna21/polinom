#pragma once
#include <iostream>
#include <forward_list>
#include "Monom.h"

class Polinom
{
public:
	Polinom();
	~Polinom();

	Polinom operator+(Monom& m);
	Polinom operator+(Polinom & p);
	Monom& operator[](size_t index);
	Polinom& operator=(Polinom& p);

	friend std::ostream& operator<<(std::ostream& , Polinom&);
private:

	std::forward_list<Monom> monoms;
};

Polinom::Polinom()
{
//	monoms = new std::forward_list<Monom>;
}

Polinom::~Polinom()
{
	monoms.clear();
}

std::ostream& operator<<(std::ostream & os, Polinom& poli)
{

	for (Monom& elem : poli.monoms)
	{
		if (elem.getKoef() >= 0)
			os << "+";
		os << elem;
	}
	return os;
}

Polinom Polinom::operator+(Monom & m)
{
	bool find = false;
	Polinom tmp(*this);
	for (Monom& elem : tmp.monoms)
	{
		if (elem.isSumm(m))
		{
			elem = m;
			find = true;
		}
	}
	if (!find)
	{
		tmp.monoms.push_front(m);
	}
	return tmp;
}

Polinom Polinom::operator+(Polinom& p)
{
	Polinom tmp;
	std::forward_list<Monom> tmpm = p.monoms;
	for (Monom& elem : monoms)
	{
		bool find = false;
		for (Monom& t: tmpm)
		{
			if (elem.isSumm(t))
			{
				tmp = tmp + (elem + t);
				find = true;
				tmpm.remove(t);
				break;
			}
		}
		if (!find)
			tmp = tmp + elem;
	}
	for (Monom& t : tmpm)
	{
			tmp = tmp +  t;
			//tmpm.remove(t);
	}

	return tmp;
}

Monom & Polinom::operator[](size_t index)
{
	int i = 0;
	for (Monom& elem : monoms)
	{
		if (i++ == index)
			return elem;
	}
	throw 1;
}


Polinom& Polinom::operator=(Polinom& m)
{
	monoms.clear();
	for (Monom& elem : m.monoms)
	{
		monoms.push_front(elem);
	}
	return *this;
}
