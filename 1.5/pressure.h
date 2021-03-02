#ifndef _PRESSURE_
#define _PRESSURE_

#include "physics_value.h"
#include "types.h"
class pressure : public physics_value
{
public:
	pressure(double in_value) : physics_value(in_value, PASCALS) { }
};

#endif
