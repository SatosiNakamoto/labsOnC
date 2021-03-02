#ifndef PHYSICS_VALUE
#define PHYSICS_VALUE

#include <iostream>
#include "types.h"

class physics_value
{
public:
	physics_value(double in_value, type in_name = NONE) : m_value(in_value), m_name(in_name) { }
	virtual ~physics_value() = default;

	double get_value() const { return m_value; }
	
	physics_value operator+(const physics_value& value) const;
	physics_value operator-(const physics_value& value) const;
	physics_value operator*(const physics_value& value) const;
	physics_value operator/(const physics_value& value) const;
	
	friend std::ostream& operator<<(std::ostream&, const physics_value&);
	
protected:
	double m_value;
	type m_name;
private:
};

std::ostream& operator<<(std::ostream&, const physics_value&);

#endif
