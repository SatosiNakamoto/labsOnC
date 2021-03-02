#include "vector2d.h"
#include <iostream>

int main()
{
	vector2d v(1,1);
	std::cout << v << "\n";
	vector2d v2(11,199);
	std::cout << v.cross(v2)[0] << " " << v.cross(v2)[1] << " " <<  v.cross(v2)[2] << "\n";
	return 0;
}