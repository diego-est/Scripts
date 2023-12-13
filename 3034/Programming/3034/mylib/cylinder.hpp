#pragma once
#include "circle.hpp"
#include <iostream>

class Cylinder : public Circle {
      private:
	double m_height;

      public:
	Cylinder(double radius = 1.0, double height = 1.0);
	~Cylinder();

	/* function setters */
	auto set_height(double height) -> void;
	auto set_dimensions(double radius, double height) -> void;

	/* function getters */
	auto get_surface_area() const -> double;
	auto get_volume() const -> double;
	auto get_height() const -> double;
	auto get_dimensions(double& radius, double& height) const -> void;
	auto print() const -> void;

	/* operators */
	auto operator==(const Cylinder& rhs) -> bool;
	auto operator+(const Cylinder& rhs) -> Cylinder;
	friend auto operator<<(std::ostream& lhs, const Cylinder& rhs)
	    -> std::ostream&;
	friend auto operator>>(std::istream& lhs, Cylinder& rhs)
	    -> std::istream&;
};

