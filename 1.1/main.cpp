//FIRST TASK
#include <iostream>

#include "vector4d.h"
#include "complex.h"
#include "amper.h"
#include "position.h"

int main()
{
	vector4d v(1,1,1,1);
	std::cout << v << "\n";
	complex c(1,1);
	std::cout << c << "\n";
	amper a(1);
	for (int i = 0; i < 10; ++i)
		a.get_value();
	std::cout << a.totalCount();
	return 0;	
}
