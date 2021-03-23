#include "SharedPtr.h"
#include "UniquePtr.h"

#include <iostream>

int main()
{
	struct point
	{
		int x, y;
		point(int xin, int yin) : x(xin), y(yin){}
	};

	SharedPtr<point> p1(new point(1,1));
	auto p2(p1);
	std::cout << "x: " << p2->x << " y: " << p2->y << std::endl;
	UniquePtr<point> ptr1(new point(2,2));
    UniquePtr<point> ptr2(std::move(ptr1));
    std::cout << "x: " << ptr2->x << " y: " << ptr2->y << std::endl;
	return 0;
}