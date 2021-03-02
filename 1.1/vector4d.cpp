#include <cmath>
#include "vector4d.h"

double vector4d::operator *(const vector4d& vec_in)
{
	return m_x * vec_in.m_x + m_y * vec_in.m_y + m_z * vec_in.m_z + m_t + vec_in.m_t;
}

double vector4d::get_length() const 
{ 
	return std::sqrt(m_x * m_x + m_y * m_y + m_z * m_z + m_t * m_t); 
}

vector4d vector4d::operator +(const vector4d& vec) const 
{ 
	return vector4d(m_x + vec.m_x, m_y + vec.m_y, m_z + vec.m_z, m_t + vec.m_t); 
}

vector4d vector4d::operator -(const vector4d& vec) const 
{ 
	return vector4d(m_x - vec.m_x, m_y - vec.m_y, m_z - vec.m_z, m_t - vec.m_t); 
}

std::ostream& operator <<(std::ostream& os, const vector4d& vec)
{
	return (os << vec.get_x() << ";" << vec.get_y() << ";" << vec.get_z() << ";" << vec.get_z());
}
