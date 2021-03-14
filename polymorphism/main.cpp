#include "physics_value.h"
#include "pressure.h"
#include "power.h"
#include "area.h"

#include <iostream>
#include "exceptions.h"

void test1()
{
	for(int i = 1; i < 10; ++i)
	{
		pressure pr1(i);

		pressure pr2(i);

		(pr1 + pr2);
		(pr1 - pr2);
		(pr1 / pr2);
		(pr1 * pr2);
	}
}

int main()
{
	try
	{
		std::cout << "start\n";
		power p1(13);
		power p2(13);
		
		std::cout << (p2 + p1) << "\n";
		
		pressure pr1(23);
		pressure pr2(13);
		std::cout << (pr1 - pr2) << "\n";

		area a1(14);
		area a2(14);
		
		std::cout << (a1 + pr2) << "\n";
		//test1();
		std::cout << "--------\n";
	}
	catch(typeException e)
	{
		std::cout << e.message; 
	}
	catch(zeroDivisionException e)
	{
		std::cout << e.message; 
	}
	return 0;
}
