#pragma once
#include "circle.hpp"
#include <iostream>

class Sphere : public Circle {
      public:
	Sphere(double radius = 1.0);
	~Sphere();

	auto get_volume() const -> double;
	auto get_surface_area() const -> double;
	auto operator==(Sphere const& rhs) const -> bool;
	auto operator+(Sphere const& rhs) const -> Sphere;
	auto friend operator>>(std::istream& lhs, Sphere& rhs)
	    -> std::istream&;
	auto friend operator<<(std::ostream& lhs, Sphere const& rhs)
	    -> std::ostream&;
};
