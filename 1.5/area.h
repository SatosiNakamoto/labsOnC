#ifndef _AREA_
#define _AREA_

#include "physics_value.h"
#include "types.h"
class area : public physics_value
{
public:
	area(double in_value) : physics_value(in_value, METERS) { }
};

#endif
