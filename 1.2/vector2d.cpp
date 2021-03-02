#include <cmath>
#include "vector2d.h"

double vector2d::get_len() const
{ 
	return std::sqrt(x * x + y * y); 
}

//можно, кншн, напрячься и создать, например базовый класс, унаследовать от него отдельный виды векторов или еще что-то такое жоское 
int* vector2d::cross(const vector2d& vec)
{
	int* resCoor = new int[3];
	resCoor[0] = 0; 
    resCoor[1] = 0; 
    resCoor[2] = x * vec.get_y() - y * vec.get_x();
	return resCoor;
}

std::ostream& operator<<(std::ostream& os, const vector2d& vec)
{
	return (os << '{' << vec.get_x() << ", " << vec.get_y() << '}');
}
