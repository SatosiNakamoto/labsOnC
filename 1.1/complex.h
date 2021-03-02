#ifndef _COMPLEX_
#define _COMPLEX_

#include <ostream>

class complex
{
public:
	complex(int real, int imagine) : m_real(real), m_imagine(imagine) { }
	
	int get_real() const { return m_real; }
	int get_imagin() const { return m_imagine; }

	void set_real(int real_in) { m_real = real_in;}
	void set_imagine(int img_in) { m_real = img_in;}

	complex operator+(const complex& number) const;
	complex operator-(const complex& number) const;
	complex operator*(const complex& number) const;
protected:
		
private:	
	int m_real; 
	int m_imagine;
};

std::ostream& operator<<(std::ostream& os, const complex& in_complex);

#endif
