#include "physics_value.h"
#include "pressure.h"
#include "power.h"
#include "area.h"

#include <iostream>

int main()
{
	power p1(13);
	power p2(13);
	area a1(14);
	area a2(14);
	std::cout << p1 / p2 << "\n";

	std::cout << a1 - a2 << "\n";
	std::cout << "--------\n";
	return 0;
}
