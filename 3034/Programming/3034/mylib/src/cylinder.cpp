#include "../cylinder.hpp"
#include <cmath>
#include <iomanip>
#include <iostream>

/**
 *  @brief  "Cylinder class derived from Circle class."
 *
 *  "Cylinder class to store cylindrical data. Both the radius and height of the
 *  Cylinder object are set to std::nan("0")."
 */
Cylinder::Cylinder(double radius, double height) : Circle(radius), m_height(height)
{
	std::cout
	    << "Invocando el constructor parametrizado del derived class.\n";
}

/**
 *  @brief  "Simple destructor."
 *
 *  "Destroys a Cylinder object."
 */
Cylinder::~Cylinder()
{
	std::cout << "Invocando el destructor del derived class.\n";
}

/**
 *  @brief  "Sets the heigt for this cylinder object."
 *
 *  @param  double  "The height to set."
 *
 *  @return  void
 *
 *  "Changes the height of this Cylinder object to height."
 */
auto Cylinder::set_height(double height) -> void
{
m_height = (height > 1.0) ? height : 1.0;
}

/**
 *  @brief  "Sets both the height and radius of this Cylinder object."
 *
 *  @param  double  "The radius to set."
 *  @param  double  "The height to set."
 *
 *  @return  void
 *
 *  "Sets both the radius and the height of this Cylinder object. Has bounds
 *  checking."
 */
auto Cylinder::set_dimensions(double radius, double height) -> void
{
	set_radius(radius);
m_height = height;
}

/**
 *  @brief  "Gets the dimensions of this Cylinder object."
 *
 *  @param  double&  "The radius to write to."
 *  @param  double&  "The height to write to."
 *
 *  @return  void
 *
 *  "Writes the members radius and height to the parameters radius and height."
 */
auto Cylinder::get_dimensions(double& radius, double& height) const -> void
{
	radius = get_radius();
	height =m_height;
}

/**
 *  @brief  "Gest the height of this Cylinder object."
 *
 *  @return  double "Height of this Cylinder object."
 *
 *  "Returns a copy of this Cylinder's height."
 */
auto Cylinder::get_height() const -> double
{
	return m_height;
}

/**
 *  @brief  "Gets the area of this Cylinder object."
 *
 *  @return  double  "The area of this Cylinder's object."
 *
 *  "Returns the area of this Cylinder object via the formula:
 *  2 * PI * radius * (radius + height)."
 */
auto Cylinder::get_surface_area() const -> double
{
	return 2 * M_PI * get_radius() * (get_radius() +m_height);
}

/**
 *  @brief  "Gets the volume of this Cylinder object."
 *
 *  @return  double  "The volume of this Cylinder object."
 *
 *  "Returns the volume of this Cylinder object via the formula:
 *  PI * radius^2 * height."
 */
auto Cylinder::get_volume() const -> double
{
	return M_PI * std::pow(get_radius(), 2) *m_height;
}

auto Cylinder::print() const -> void
{
	std::cout << "\n\tRadius: " << get_radius() << std::endl;
	std::cout << "\n\tHeight: " <<m_height << std::endl;
}

/**
 *  @brief  "Equal operator."
 *
 *  @param  const Cylinder&  "The Cylinder object to compare to."
 *
 *  @return  bool  "True when both Cylinder objects are equal."
 *
 *  "Checks whether two Cylinder objects are equal."
 */
auto Cylinder::operator==(const Cylinder& rhs) -> bool
{
	return fabs(m_height - rhs.m_height) < std::numeric_limits<double>::epsilon() && fabs(get_radius() - rhs.get_radius()) < std::numeric_limits<double>::epsilon();
}

/**
 *  @brief  "Add operator."
 *
 *  @param  const Cylinder&  "The Cylinder object to add."
 *
 *  @return  Cylinder  "A Cylinder object with the sum of both Cylinder object."
 *
 *  "Sums the radii and heights of both Cylinders and returns a Cylinder with
 *  data members as that sum."
 */
auto Cylinder::operator+(const Cylinder& rhs) -> Cylinder
{
	return Cylinder(get_radius() + rhs.get_radius(),m_height + rhs.get_height());
}

/**
 *  @brief  "Mutates a Cylinder from a std::ostream object."
 *
 *  @param  std::ostream&  "The std::ostream object to receive from."
 *  @param  const Cylinder&  "The Cylinder object to mutate."
 *
 *  @return  std::ostream&  "The std::ostream object to return."
 *
 *  "Mutates a Cylinder object from data from a std::ostream object."
 */
auto operator<<(std::ostream& lhs, const Cylinder& rhs) -> std::ostream&
{
	lhs << "Radius: " << rhs.get_radius() << std::endl;
	lhs << "Height: " << rhs.get_height() << std::endl;
	return lhs;
}

/**
 *  @brief  "Sends a Cylinder object to a std::istream object."
 *
 *  @param  std::istream&  "The std::istream object to send to."
 *  @param  Cylinder&  "The Cylinder to to write to."
 *
 *  @return  std::istream&  "The std::istream object that was written to."
 *
 *  "Sends input from std::istream into a Cylinder object."
 */
auto operator>>(std::istream& lhs, Cylinder& rhs) -> std::istream&
{
	auto radius = std::nan("0");
	auto height = std::nan("0");
	do {
		lhs >> radius;
		lhs >> height;
	} while (radius <= 0.0 || height <= 0.0);
	rhs.set_dimensions(radius, height);
	return lhs;
}

