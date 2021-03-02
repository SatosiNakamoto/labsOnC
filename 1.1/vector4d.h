#ifndef _VECTOR_
#define _VECTOR_

#include <ostream>

class vector4d
{
public:
	vector4d(double x = 0, double y = 0, double z = 0, double t = 0) : m_x(x), m_y(y), m_z(z), m_t(t) { }

	double get_x() const { return m_x; }
	double get_y() const { return m_y; }
	double get_z() const { return m_z; }
	double get_t() const { return m_t; }
	double get_length() const;

	vector4d normalized() const;
	
	double operator *(const vector4d& vec_in);
	vector4d operator +(const vector4d& vec) const;
	vector4d operator -(const vector4d& vec) const;

private:
	double m_x;
	double m_y;
	double m_z;
	double m_t;
};

std::ostream& operator<<(std::ostream& os, const vector4d& vec);

#endif
