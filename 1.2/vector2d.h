#ifndef _VECTOR_2D_
#define _VECTOR_2D_

#include <iostream>

class vector2d
{
public:
	vector2d(double x, double y) : x(x), y(y) { }
	int* cross(const vector2d& vec2);
	static vector2d zero() { return vector2d(0, 0); }
	double get_x() const { return x; }
	double get_y() const { return y; }
	double get_len() const;

private:
	const double x = 0;
	const double y = 0;
};

std::ostream& operator<<(std::ostream& os, const vector2d& vec);

#endif
