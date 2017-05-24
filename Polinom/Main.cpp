#include <iostream>
#include "Monom.h"
#include "Polinom.h"


int main()
{

	Monom *test = new Monom(1, 4);
	Monom *test1 = new Monom(1, 4);

	(*test)[0] = 5;
	(*test)[1] = 2;
	(*test)[2] = 6;
	(*test)[3] = 8;

	(*test1)[0] = 5;
	(*test1)[1] = 2;
	(*test1)[2] = 6;
	(*test1)[3] = 8;

	Monom test2 = *test * *test1;
	Polinom pol;
	pol = pol + *test;
	pol = pol + *test1;

	(*test1)[0] = 1;
	(*test1)[1] = 2;
	(*test1)[2] = 3;
	(*test1)[3] = 4;
	pol = pol + *test1;
	pol = pol + test2;


	Monom *test3 = new Monom(3, 4);
	Monom *test4 = new Monom(9, 4);

	(*test3)[0] = 5;
	(*test3)[1] = 2;
	(*test3)[2] = 6;
	(*test3)[3] = 8;

	(*test4)[0] = 5;
	(*test4)[1] = 2;
	(*test4)[2] = 6;
	(*test4)[3] = 8;
	Monom test5 = *test3 + *test4;
	Polinom pol2;
	pol2 = pol2 + *test3;
	pol2 = pol2 + *test4;

	(*test4)[0] = 1;
	(*test4)[1] = 2;
	(*test4)[2] = 3;
	(*test4)[3] = 4;
	pol2 = pol2 + *test4;

	pol2 = pol2 + test5;

	std::cout << pol <<std::endl;
	std::cout << pol2 << std::endl;
	Polinom pol3 = pol2 + pol;

	std::cout << pol3;



	std::cin.get();

}