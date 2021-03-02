#include "complex.h"

complex complex::operator+(const complex& in_complex) const
{
	return complex(m_real + in_complex.m_real, m_imagine + in_complex.m_imagine);
}

complex complex::operator-(const complex& in_complex) const
{
	return complex(m_real - in_complex.m_real, m_imagine - in_complex.m_imagine);
}

complex complex::operator*(const complex& in_complex) const
{
	return complex(m_real * in_complex.m_real - m_imagine * in_complex.m_imagine,  m_imagine * in_complex.m_real + m_real * in_complex.m_imagine);
}

std::ostream& operator<<(std::ostream& os, const complex& in_complex)
{
	return (os << in_complex.get_real() << " + " << in_complex.get_imagin() << 'i');
}
