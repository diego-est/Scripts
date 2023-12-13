#include "../sphere.hpp"
#include <iomanip>
#include <iostream>
#include <cmath>


Sphere::Sphere(double radius) : Circle(radius)
{
}

Sphere::~Sphere()
{
}

/**
 *  @brief  "Gets the volume of this Sphere object."
 *
 *  @return  double  "The volume of this Sphere object."
 *
 *  "Calculates the volume of this Sphere object via the formula:
 *  4/3 * PI * r^3."
 */
auto Sphere::get_volume() const -> double
{
	return 4.0 / 3.0 * M_PI * std::pow(get_radius(), 3);
}

/**
 *  @brief  "Gets the surface area of this Sphere object."
 *
 *  @return  double  "The surface area of this Sphere object."
 *
 *  "Calculates the surface area of this Sphere object via the formula:
 *  4 * PI * r^2."
 */
auto Sphere::get_surface_area() const -> double
{
	return 4 * M_PI * std::pow(get_radius(), 2);
}

/**
 *  @brief  "Checks whether two spheres are equal."
 *
 *  @param  Sphere const&  "The Sphere to compare to."
 *
 *  @return  bool  "True when both Sphere objects are equal."
 *
 *  "Returns true when the radii of both Spheres are equal."
 */
auto Sphere::operator==(Sphere const& rhs) const -> bool
{
	return fabs(get_radius() - rhs.get_radius()) < std::numeric_limits<double>::epsilon();
}

/**
 *  @brief  "Constructs a new sphere out of two other spheres."
 *
 *  @param  Sphere const&  "The sphere to add."
 *
 *  @return  Sphere  "A sphere with the sum of the radii."
 *
 *  "Returns a Sphere object with the sum of both radii."
 */
auto Sphere::operator+(Sphere const& rhs) const -> Sphere
{
	return Sphere(get_radius() + rhs.get_radius());
}

/**
 *  @brief  "Pipes a Sphere object into a std::ostream object."
 *
 *  @param  std::ostream&  "The std::ostream object to pipe to."
 *  @param  const Sphere&  "The Sphere object to be piped."
 *
 *  @return  std::ostream&  "A std::ostream object."
 *
 *  "Pipes Sphere members correctly into a std::ostream object."
 */
auto operator<<(std::ostream& lhs, Sphere const& rhs) -> std::ostream&
{
	lhs << std::fixed << std::setprecision(3);
	lhs << "\n\tRadius: " << rhs.get_radius() << std::endl;
	return lhs;
}

/**
 *  @brief  "Mutates a Sphere object from data from a std::istream."
 *
 *  @param  std::istream&  "The stream to receive data from."
 *  @param  Sphere&  "The Sphere object to mutate."
 *
 *  @return  std::istream&  "A std::istream object."
 *
 *  "Receives data from a std::istream object and mutates the necessary members
 *  in the Sphere object."
 */
auto operator>>(std::istream& lhs, Sphere& rhs) -> std::istream&
{
	auto radius = std::nan("0");

	do {
		lhs >> radius;
	} while (radius <= 0.0);
	rhs.set_radius(radius);
	return lhs;
}

