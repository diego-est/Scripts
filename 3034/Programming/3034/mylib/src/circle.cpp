#include "../circle.hpp"
#include <iomanip>
#include <iostream>
#include <cmath>
#include <utility>

/**
 *  @brief  "Constructs a Circle object."
 *
 *  "Constructs a circle object using radius parameter. If not the Circle object
 *  will have a default radius of std::nan("0")."
 */
Circle::Circle(double radius) :m_radius(radius)
{
	std::cout << "Invocando al parametrized constructor\n";
}

/**
 *  @brief  "Changes the radius member"
 *
 *  @param  double  "The radius to set."
 *
 *  @return  void
 *
 *  "Changes them_radius member to radius."
 */
auto Circle::set_radius(double radius) -> void
{
m_radius = 1.0 >= radius ? 1.0 : radius;
}
/**
 *  @brief  "Gets the diameter of this circle object."
 *
 *  @return  double "The diameter."
 *
 *  "Returns the diameter of this circle object."
 */
auto Circle::get_diameter() const -> double
{
	return m_radius * 2;
}

auto Circle::get_radius() const -> double
{
	return m_radius;
}
/**
 *  @brief  "Gets the circumference of this Circle object."
 *
 *  @return  double  "The circumference."
 *
 *  "Returns the circumference of this Circle object."
 */
auto Circle::get_circumference() const -> double
{
	return m_radius * M_PI * 2;
}
/**
 *  @brief  "Gets the area of this Circle object."
 *
 *  @return  double  "The area."
 *
 *  "Returns the area of this Circle object. The formula is r^2 * PI"
 */
auto Circle::get_area() const -> double
{
	return std::pow(m_radius, 2) * M_PI;
}
/**
 *  @brief  "Prints the current state of the Circle object."
 *
 *  @return  void
 *
 *  "Prints the current state of the Circle object. Its radius."
 */
auto Circle::print() const -> void
{
	std::cout << "\n\tRadius: " <<m_radius << std::endl;
}
/**
 *  @brief  "Equal operator."
 *
 *  @param  const Circle&  "The Circle object to compare to."
 *
 *  @return  bool  "True if the Circles are equal."
 *
 *  "Checks whether two Circle objects are equal and returns true if so."
 */
auto Circle::operator==(const Circle& rhs) const -> bool
{
	return fabs(m_radius - rhs.m_radius) < std::numeric_limits<double>::epsilon();
}
/**
 *  @brief  "Add operator."
 *
 *  @param  const Circle&  "The Circle object to add."
 *
 *  @return  Circle  "A Circle object with the sum of both Circles."
 *
 *  "Sums the radii of both Circle objects and creates a new Circle object
 *  using that sum."
 */
auto Circle::operator+(const Circle& rhs) const -> Circle
{
	return Circle(m_radius + rhs.m_radius);
}

/**
 *  @brief  "Pipes a Circle object into a std::ostream object."
 *
 *  @param  std::ostream&  "The std::ostream object to pipe to."
 *  @param  const Circle&  "The Circle object to be piped."
 *
 *  @return  std::ostream&  "A std::ostream object."
 *
 *  "Pipes Circle members correctly into a std::ostream object."
 */
auto operator<<(std::ostream& lhs, const Circle& rhs) -> std::ostream&
{
	lhs << std::fixed << std::setprecision(3);
	lhs << "\n\tRadius: " << rhs.get_radius() << std::endl;
	return lhs;
}

/**
 *  @brief  "Mutates a Circle object from data from a std::istream."
 *
 *  @param  std::istream&  "The stream to receive data from."
 *  @param  Circle&  "The Circle object to mutate."
 *
 *  @return  std::istream&  "A std::istream object."
 *
 *  "Receives data from a std::istream object and mutates the necessary members
 *  in the Circle object."
 */
auto operator>>(std::istream& lhs, Circle& rhs) -> std::istream&
{
	auto radius = std::nan("0");

	do {
		lhs >> radius;
	} while (!(radius >= 1.0));
	rhs.set_radius(radius);
	return lhs;
}

