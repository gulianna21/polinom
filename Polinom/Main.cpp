#include <iostream>
#include "Monom.h"
#include "Polinom.h"


int main()
{
	setlocale(NULL, "RUSSIAN");

	Monom *test = new Monom(1, 4);
	Monom *test1 = new Monom(1, 4);

	(*test)[0] = 51;
	(*test)[1] = 22;
	(*test)[2] = 63;
	(*test)[3] = 84;

	(*test1)[0] = 51;
	(*test1)[1] = 21;
	(*test1)[2] = 61;
	(*test1)[3] = 81;

	Monom test2 = *test * *test1;
	Polinom pol;
	pol = pol + *test;
	pol = pol + *test1;

	(*test1)[0] = 11;
	(*test1)[1] = 21;
	(*test1)[2] = 31;
	(*test1)[3] = 14;
	pol = pol + *test1;
	pol = pol + test2;


	std::cout << pol << std::endl;
	std::cout << pol[0] << std::endl;
	std::cout << pol[1] << std::endl;
	std::cout << pol[2] << std::endl;

	Monom *test3 = new Monom(3, 4);
	Monom *test4 = new Monom(9, 4);

	(*test3)[0] = 15;
	(*test3)[1] = 12;
	(*test3)[2] = 61;
	(*test3)[3] = 81;

	(*test4)[0] = 51;
	(*test4)[1] = 21;
	(*test4)[2] = 61;
	(*test4)[3] = 81;
	Monom test5;
	try {
		test5 = *test3 + *test4;
	
		Polinom pol2;
	pol2 = pol2 + *test3;
	pol2 = pol2 + *test4;

	(*test4)[0] = 1;
	(*test4)[1] = 2;
	(*test4)[2] = 3;
	(*test4)[3] = 4;
	pol2 = pol2 + *test4;

	pol2 = pol2 + test5;

	std::cout << pol << std::endl;
	std::cout << pol2 << std::endl;
	Polinom pol3 = pol2 + pol;

	std::cout << pol3;
	}
	catch (int e)
	{
		std::cout << "сложение разных мономов";
	}



	std::cin.get();



	std::cin.get();

}