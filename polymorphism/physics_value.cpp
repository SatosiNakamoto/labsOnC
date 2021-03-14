#include <iostream>
#include <memory>

#include "physics_value.h"
#include "power.h"
#include "area.h"
#include "pressure.h"
#include "exceptions.h"

#define function typename

template<function F>
constexpr physics_value* calculation(const physics_value* in_value, const physics_value* current_value, F f)
{
	physics_value* p;
	const physics_value* temp_in_value;
	const physics_value* temp_current_value;

	if((dynamic_cast<const area*>(in_value)) && (dynamic_cast<const area*>(current_value))){
		temp_in_value = dynamic_cast<const area*>(in_value);
		temp_current_value = dynamic_cast<const area*>(current_value);
		std::cout << "area" << " area\n";
		p = new area(f(in_value -> get_value(), current_value -> get_value()));
	}

	else if((dynamic_cast<const power*>(in_value)) && (dynamic_cast<const power*>(current_value))){
		temp_in_value = dynamic_cast<const power*>(in_value);
		temp_current_value = dynamic_cast<const power*>(current_value);
		p = new power(f(in_value -> get_value(), current_value -> get_value()));
	}
	
	else if((dynamic_cast<const pressure*>(in_value)) && (dynamic_cast<const pressure*>(current_value))){
		temp_in_value = dynamic_cast<const pressure*>(in_value);
		temp_current_value = dynamic_cast<const pressure*>(current_value);
		p = new pressure(f(in_value -> get_value(), current_value -> get_value()));
	}
	else
		throw typeException();
	return p;
}

std::unique_ptr<physics_value> physics_value::operator+(const physics_value& in_value) const
{
	std::unique_ptr<physics_value> ret(calculation(&in_value, this, [](double a, double b){return a + b;}));
	return ret;
}

std::unique_ptr<physics_value> physics_value::operator-(const physics_value& in_value) const
{
	std::unique_ptr<physics_value> ret(calculation(&in_value, this, [](double a, double b){return a - b;}));
	return ret;
}

std::unique_ptr<physics_value> physics_value::operator*(const physics_value& in_value) const
{
	std::unique_ptr<physics_value> ret(calculation(&in_value, this, [](double a, double b){return a * b;}));
	return ret;
}

std::unique_ptr<physics_value> physics_value::operator/(const physics_value& in_value) const
{
	if(in_value.get_value() == 0)
		throw zeroDivisionException();

	std::unique_ptr<physics_value> ret(calculation(&in_value, this, [](double a, double b){return a - b;}));
	return ret;
}

std::ostream& operator<<(std::ostream& os, const physics_value& in_value)
{
	const char* name = (dynamic_cast<const pressure*>(&in_value)) ? " Pa" : (dynamic_cast<const power*>(&in_value)) ? " Nuton" : (dynamic_cast<const area*>(&in_value))  ? " me" : " ";

	return (os << in_value.get_value() << name);
}

std::ostream& operator<<(std::ostream& os, std::unique_ptr<physics_value> in_value)
{
	physics_value* ptr = in_value.get();
	const char* name = (dynamic_cast<const pressure*>(ptr)) ? " Pa" : (dynamic_cast<const power*>(ptr)) ? " Nuton" : (dynamic_cast<const area*>(ptr))  ? " me" : " ";

	return (os << in_value.get() -> get_value() << name);
}
