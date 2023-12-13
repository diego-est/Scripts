/* === circle.h === */
#ifndef CIRCLE_H_
#define CIRCLE_H_
#include <iostream>

class Circle {
	double _r;

      public:
	Circle(double radius = 1.0);

	/* function setter */
	auto set_radius(double radius) -> void;

	/* function getters */
	inline auto get_radius() const -> double
	{
		return _r;
	}
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
#endif

/* === circle.cpp === */
// #include "circle.h"
#include <cmath>
#include <iomanip>
#include <iostream>

/**
 *  @brief  "Constructs a Circle object."
 *
 *  "Constructs a circle object using radius parameter. If not the Circle object
 *  will have a default radius of std::nan("0")."
 */
Circle::Circle(double radius) : _r(radius)
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
 *  "Changes the _r member to radius."
 */
auto Circle::set_radius(double radius) -> void
{
	_r = 1.0 >= radius ? 1.0 : radius;
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
	return this->_r * 2;
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
	return this->_r * M_PI * 2;
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
	return std::pow(_r, 2) * M_PI;
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
	std::cout << "\n\tRadius: " << _r << std::endl;
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
	return _r == rhs.get_radius();
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
	return Circle(_r + rhs.get_radius());
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

/* === cylinder.h === */
#ifndef CYLINDER_H_
#define CYLINDER_H_
// #include "circle.h"
#include <iostream>

class Cylinder : public Circle {
      private:
	double _h;

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
#endif

/* === cylinder.cpp === */
// #include "cylinder.h"
#include <cmath>
#include <iomanip>
#include <iostream>

/**
 *  @brief  "Cylinder class derived from Circle class."
 *
 *  "Cylinder class to store cylindrical data. Both the radius and height of the
 *  Cylinder object are set to std::nan("0")."
 */
Cylinder::Cylinder(double radius, double height) : Circle(radius)
{
	set_height(height);
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
	_h = (height > 1.0) ? height : 1.0;
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
	_h = height;
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
	height = _h;
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
	return _h;
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
	return 2 * M_PI * get_radius() * (get_radius() + _h);
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
	return M_PI * std::pow(get_radius(), 2) * _h;
}

auto Cylinder::print() const -> void
{
	std::cout << "\n\tRadius: " << get_radius() << std::endl;
	std::cout << "\n\tHeight: " << _h << std::endl;
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
	return _h == rhs.get_height() && get_radius() == rhs.get_radius();
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
	return Cylinder(get_radius() + rhs.get_radius(), _h + rhs.get_height());
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

/* === sphere.h === */
#ifndef SPHERE_H
#define SPHERE_H
#include <iostream>
// #include "circle.h"

class Sphere : public Circle {
      public:
	Sphere(double radius = 1.0);
	~Sphere();

	auto get_volume() const -> double;
	auto get_surface_area() const -> double;
	auto operator==(Sphere const& rhs) const -> bool;
	auto operator+(Sphere const& rhs) const -> Sphere;
	auto friend operator>>(std::istream& lhs, Sphere const& rhs)
	    -> std::istream&;
	auto friend operator<<(std::ostream& lhs, Sphere const& rhs)
	    -> std::ostream&;
};
#endif

/* === sphere.cpp === */
// #include "sphere.h"
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
	return get_radius() == rhs.get_radius();
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

/* === main.cpp === */
enum ClassType {
	CircleClass,
	CylinderClass,
	SphereClass,
};

auto read_radius(ClassType class_type) -> double;
auto read_radius_and_height() -> std::pair<double, double>;
auto display_menu(ClassType class_type) -> int;
auto execute_option(int option, Circle& circle) -> void;
auto execute_option(int option, Cylinder& cylinder) -> void;
auto execute_option(int option, Sphere& sphere) -> void;

auto main() -> int
{
	auto circle = Circle(10.0);
	auto selection = 0;
	do {
		selection = display_menu(ClassType::CircleClass);
		execute_option(selection, circle);
	} while (selection != 6);

	auto cylinder = Cylinder(circle.get_radius());
	selection = 0;
	do {
		selection = display_menu(ClassType::CylinderClass);
		execute_option(selection, cylinder);
	} while (selection != 8);

	auto sphere = Sphere(cylinder.get_radius());
	selection = 0;
	do {
		selection = display_menu(ClassType::SphereClass);
		execute_option(selection, sphere);
	} while (selection != 7);

	return 0;
}

auto read_radius(ClassType class_type) -> double
{
	auto radius = std::nan("0");
	switch (class_type) {
	case ClassType::SphereClass:
		do {
			std::cout << "\n\tInput sphere's radius: ";
			std::cin >> radius;
		} while (radius < 1.0);
		break;
	case ClassType::CircleClass:
		do {
			std::cout << "\n\tInput circle's radius: ";
			std::cin >> radius;
		} while (radius < 1.0);
		break;
	default:
		break;
	}
	return radius;
}

auto read_radius_and_height() -> std::pair<double, double>
{
	auto radius = std::nan("0");
	auto height = std::nan("0");
	do {
		std::cout << "\n\tInput cylinder's radius: ";
		std::cin >> radius;
	} while (radius < 1.0);
	do {
		std::cout << "\n\tInput cylinder's height: ";
		std::cin >> height;
	} while (radius < 1.0);
	return {radius, height};
}

auto display_menu(ClassType class_type) -> int
{
	auto message = std::string("");
	auto selection = 0;
	switch (class_type) {
	case ClassType::CircleClass:
		message = "\n\t<<< Sphere's Menu >>>"
			  "\n\t1. Display radius."
			  "\n\t2. Input radius."
			  "\n\t3. Display diameter."
			  "\n\t4. Display circumference."
			  "\n\t5. Display area."
			  "\n\t6. Exit program."
			  "\n\tInput your option (1 - 6): ";
		do {
			std::cout << message;
			std::cin >> selection;
		} while (selection < 1 || selection > 6);
		break;
	case ClassType::CylinderClass:
		message = "\n\t<<< Cylinder's Menu >>>"
			  "\n\t1. Display radius."
			  "\n\t2. Input radius and height."
			  "\n\t3. Display height."
			  "\n\t4. Display diameter."
			  "\n\t5. Display circumference."
			  "\n\t6. Display surface area."
			  "\n\t7. Display volume."
			  "\n\t8. Exit program."
			  "\n\tInput your option (1 - 8): ";
		do {
			std::cout << message;
			std::cin >> selection;
		} while (selection < 1 || selection > 8);
		break;
	case ClassType::SphereClass:
		message = "\n\t<<< Sphere's Menu >>>"
			  "\n\t1. Display radius."
			  "\n\t2. Input radius."
			  "\n\t3. Display diameter."
			  "\n\t4. Display circumference."
			  "\n\t5. Display surface area."
			  "\n\t6. Display volume."
			  "\n\t7. Exit program."
			  "\n\tInput your option (1 - 7): ";
		do {
			std::cout << message;
			std::cin >> selection;
		} while (selection < 1 || selection > 7);
		break;
	default:
		break;
	}
	return selection;
}

auto execute_option(int option, Circle& circle) -> void
{
	auto radius = std::nan("0");

	switch (option) {
	case 1: /* Display radius. */
		circle.print();
		break;
	case 2: /* Input radius. */
		radius = read_radius(ClassType::CircleClass);
		circle.set_radius(radius);
		break;
	case 3: /* Display diameter. */
		std::cout << "\n\tDiameter = " << circle.get_diameter()
			  << std::endl;
		break;
	case 4: /* Display circumference. */
		std::cout << "\n\tCircumference = "
			  << circle.get_circumference() << std::endl;
		break;
	case 5: /* Display area. */
		std::cout << "\n\tArea = " << circle.get_area() << std::endl;
		break;
	case 6: /* Exit program. */
		break;
	default:
		break;
	} /* End of switch. */
}

auto execute_option(int option, Cylinder& cylinder) -> void
{
	auto radius = std::nan("0");
	auto height = std::nan("0");

	switch (option) {
	case 1: /* Display radius. */
		cylinder.print();
		break;
	case 2: /* Input radius. */
		std::tie(radius, height) = read_radius_and_height();
		cylinder.set_dimensions(radius, height);
		break;
	case 3: /* Display height. */
		std::cout << "\n\tHeight = " << cylinder.get_height()
			  << std::endl;
		break;
	case 4: /* Display diameter. */
		std::cout << "\n\tDiameter = " << cylinder.get_diameter()
			  << std::endl;
		break;
	case 5: /* Display circumference. */
		std::cout << "\n\tCircumference = "
			  << cylinder.get_circumference() << std::endl;
		break;
	case 6: /* Display surface area. */
		std::cout << "\n\tSurface Area = "
			  << cylinder.get_surface_area() << std::endl;
		break;
	case 7: /* Display volume. */
		std::cout << "\n\tVolume = " << cylinder.get_volume()
			  << std::endl;
		break;
	case 8: /* Exit program. */
		break;
	default:
		break;
	} /* End of switch. */
}

auto execute_option(int option, Sphere& sphere) -> void
{
	auto radius = std::nan("0");

	switch (option) {
	case 1: /* Display radius. */
		sphere.print();
		break;
	case 2: /* Input radius. */
		radius = read_radius(ClassType::SphereClass);
		sphere.set_radius(radius);
		break;
	case 3: /* Display diameter. */
		std::cout << "\n\tDiameter = " << sphere.get_diameter()
			  << std::endl;
		break;
	case 4: /* Display circumference. */
		std::cout << "\n\tCircumference = "
			  << sphere.get_circumference() << std::endl;
		break;
	case 5: /* Display surface area. */
		std::cout << "\n\tSurface Area = " << sphere.get_surface_area()
			  << std::endl;
		break;
	case 6: /* Display volume. */
		std::cout << "\n\tVolume = " << sphere.get_volume()
			  << std::endl;
		break;
	case 7: /* Exit program. */
		break;
	default:
		break;
	} /* End of switch. */
}
