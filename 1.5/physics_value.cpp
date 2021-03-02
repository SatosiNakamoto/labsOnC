#include "physics_value.h"

#include "power.h"
#include "area.h"
#include "pressure.h"

#define function typename

template<function F>
constexpr physics_value calculation(const physics_value& in_value, F f, double m_value)
{
	if(dynamic_cast<const power*>(&in_value))
		return power(f(in_value.get_value(),m_value));
	else if(dynamic_cast<const pressure*>(&in_value))
		return pressure(f(in_value.get_value(),m_value));
	else if(dynamic_cast<const area*>(&in_value))
		return area(f(in_value.get_value(),m_value));

	return physics_value(f(in_value.get_value(), m_value));
}

physics_value physics_value::operator+(const physics_value& in_value) const
{
	return calculation(in_value, [](double a, double b){return a + b;}, m_value);
}

physics_value physics_value::operator-(const physics_value& in_value) const
{
	return calculation(in_value, [](double a, double b){return a - b;}, m_value);
}

physics_value physics_value::operator*(const physics_value& in_value) const
{
	return calculation(in_value, [](double a, double b){return a * b;}, m_value);
}

physics_value physics_value::operator/(const physics_value& in_value) const
{
	if(in_value.get_value() == 0)
	{
		return physics_value(get_value() / 0.00000001);
	}

	return calculation(in_value, [](double a, double b){return a / b;}, m_value);
}

std::ostream& operator<<(std::ostream& os, const physics_value& in_value)
{
	return (os << in_value.m_value << ' ');
}
