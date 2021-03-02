#ifndef _POWER_
#define _POWER_

#include "physics_value.h"
#include "types.h"

class power : public physics_value
{
public:
	power(double in_value) : physics_value(in_value, NIUTONS) { }
};

#endif