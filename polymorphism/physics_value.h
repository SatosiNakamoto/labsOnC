#ifndef PHYSICS_VALUE
#define PHYSICS_VALUE

#include <iostream>
#include "types.h"
#include <memory>

#define abstract

abstract class physics_value
{
public:
	physics_value() {};
	virtual ~physics_value() = default;

	virtual double get_value() const = 0;
	virtual type get_type() const = 0;
	
	std::unique_ptr<physics_value> operator+(const physics_value& value) const;
	std::unique_ptr<physics_value> operator-(const physics_value& value) const;
	std::unique_ptr<physics_value> operator*(const physics_value& value) const;
	std::unique_ptr<physics_value> operator/(const physics_value& value) const;
	friend std::ostream& operator<<(std::ostream&, const physics_value&);
	friend std::ostream& operator<<(std::ostream& os, std::unique_ptr<physics_value> in_value);
	
protected:
private:
};

std::ostream& operator<<(std::ostream&, const physics_value&);

std::ostream& operator<<(std::ostream& os, std::unique_ptr<physics_value> in_value);

#endif
