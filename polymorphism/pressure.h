#ifndef _PRESSURE_
#define _PRESSURE_

#include "physics_value.h"
#include "types.h"
class pressure : public physics_value
{
public:
	pressure(double in_value) : physics_value(), m_value(in_value) {  data = malloc(15);}
	double get_value() const { return m_value; };
	type get_type() const { return NIUTONS; };
private:
	void* data;
	double m_value;

};

#endif
