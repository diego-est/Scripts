#pragma once
#include <iostream>

class Circle {
	double m_radius;

      public:
	Circle(double radius = 1.0);

	/* function setter */
	auto set_radius(double radius) -> void;

	/* function getters */
	auto get_radius() const -> double;
	auto get_diameter() const -> double;
	auto get_circumference() const -> double;
	auto get_area() const -> double;
	auto print() const -> void;

	/* operators */
	auto operator==(const Circle& rhs) const -> bool;
	auto operator+(const Circle& rhs) const -> Circle;
	friend auto operator<<(std::ostream& lhs, const Circle& rhs)
	    -> std::ostream&;
	friend auto operator>>(std::istream& lhs, Circle& rhs) -> std::istream&;
};
