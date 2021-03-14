#ifndef _AREA_
#define _AREA_

#include "physics_value.h"
#include "types.h"

class area : public physics_value
{
public:
	area(double in_value) : physics_value(), m_value(in_value) { }
	double get_value() const { return m_value; };
	type get_type() const { return NIUTONS; };
private:
	double m_value;

};

#endif
