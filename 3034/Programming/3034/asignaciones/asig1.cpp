/*******************************************************************************
 * Programador: Diego A. Estrada Rivera     CCOM 3034 Sección 002              *
 * Número:      801-21-3626                 Primer Semestre 2023-24            *
 * Asignación:  1                           Prof. Rafael J. Colorado           *
 * Archivo:     asigna1.cpp                 Fecha: 05/09/23                    *
 *                                                                             *
 *****************************************************************************
 *                                                                             *
 * Propósito:   Este programa, dado el radio de un círculo,                    *
 *                              calcula y despliega su diámetro,               *
 *                              su circunferencia y su área,                   *
 *                                                                             *
 ****************************************************************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

/* === class declaration === */

/**
 *  @brief  A standard way of storing information related to circle objects.
 */
class Circle
{
      private:
        double _radius;

      public:
        /* default and parametrized constructor */
        Circle(double radius = std::nan("0")) ;

        /* destructor */
        ~Circle() ;

        /* modifying member functions */
        auto set_radius(double radius) -> void ;

        /* non-modifying member functions */
        [[nodiscard]] auto get_radius() const -> double ;
        [[nodiscard]] auto get_diameter() const -> double ;
        [[nodiscard]] auto get_circumference() const -> double ;
        [[nodiscard]] auto get_area() const -> double ;

        auto print() const -> void ;
        auto operator==(const Circle &rhs) const -> bool ;
        auto operator!=(const Circle &rhs) const -> bool ;
        auto operator+(const Circle &rhs) const -> Circle ;

        friend auto operator<<(std::ostream &lhs, const Circle &rhs)
            -> std::ostream & ;
        friend auto operator>>(std::istream &lhs, const Circle &rhs)
            -> std::istream & ;
} ;

/* === class definition === */

/**
 *  @brief  Default and parametrized constructor
 *
 *  @param  radius  Radius of the circle.
 *
 *  Initializes _radius member to radius, if not called with argument then the
 *  radius is initialized to std::nan("0").
 */
Circle::Circle(double radius) : _radius(radius)
{
        std::cout << "Constructor called" << std::endl ;
}

/**
 *  @brief  Destructor
 *
 *  Destroys a circle object.
 */
Circle::~Circle() { std::cout << "Destructor called" << std::endl ; }

/**
 *  @brief  Gets the radius of the cicrle.
 *
 *  @return  The radius of the circle.
 *
 *  Simply returns the radius _radius member.
 */
[[nodiscard]] auto Circle::get_radius() const -> double { return _radius; }

/**
 *  @brief  Gets the diameter of the circle.
 *
 *  @return  The diameter of the circle.
 *
 *  Returns the diameter of the circle via doubling the length of radius. Can
 *  overflow.
 */
[[nodiscard]] auto Circle::get_diameter() const -> double
{
        return _radius * 2.0 ;
}

/**
 *  @brief  Gets the circumference of the circle.
 *
 *  @return  The circumference of the circle.
 *
 *  Returns the circumference of the circle via 2 * pi * r. Can overflow.
 */
[[nodiscard]] auto Circle::get_circumference() const -> double
{
        return _radius * 2.0 * M_PI ;
}

/**
 *  @brief Gets the area of the circle.
 *
 *  @return  The area of the circle.
 *
 *  Returns the area of the circle via r * r * 2. Can overflow.
 */
[[nodiscard]] auto Circle::get_area() const -> double
{
        return _radius * _radius * M_PI ;
}

/**
 *  @brief  Sets the radius for the circle.
 *
 *  @param  radius  New radius for the circle.
 *
 *  Sets the _radius member of this circle to radius.
 */
auto Circle::set_radius(double radius) -> void { _radius = radius; }

/**
 *  @brief  Prints the radius to stdout.
 *
 *  Prints the radius of the circle to the screen.
 */
auto Circle::print() const -> void
{
        std::cout << std::fixed << std::setprecision(3) ;
        std::cout << "\n\tRadius: " << _radius << std::endl ;
}

/**
 *  @brief  Equal operator
 *
 *  @return  bool  Whether the circles are equal.
 *
 *  Checks whether two circles are equal.
 */
auto Circle::operator==(const Circle &rhs) const -> bool
{
        return _radius == rhs._radius;
}

/**
 *  @brief  Unequal operator
 *
 *  @return  bool  Whether the circles are not equal.
 *
 *  Checks whether two circles are not equal.
 */
auto Circle::operator!=(const Circle &rhs) const -> bool
{
        return _radius != rhs._radius;
}

/**
 *  @brief  Add operator
 *
 *  @return  Circle  New circle with the sum of the two previous circles.
 *
 *  Adds the radius of two circles and returns a new circle with that radius.
 */
auto Circle::operator+(const Circle &rhs) const -> Circle
{
        return Circle(_radius + rhs._radius) ;
}

/**
 *  @brief  << operator
 *
 *  @return  std::ostream  The std::ostream object.
 *
 *  Feeds the Circle object into std::ostream.
 */
auto operator<<(std::ostream &lhs, const Circle &rhs) -> std::ostream &
{
        lhs << std::fixed << std::setprecision(3) ;
        lhs << "\n\tRadius: " << rhs.get_radius() << std::endl ;
        return lhs;
}

/**
 *  @brief  >> operator
 *
 *  @return  std::ostream  The std::ostream object.
 *
 *  Feeds the Circle object into std::ostream.
 */
auto operator>>(std::istream &lhs, Circle &rhs) -> std::istream &
{
        auto radius = std::nan("0") ;
        do {
                std::cout << "\n\tInput radius: " ;
                lhs >> radius;
        } while (radius <= 0.0) ;

        rhs.set_radius(radius) ;

        return lhs;
}

auto read_radius() -> double ;
auto display_menu() -> int ;
auto execute_option(int option, Circle &circle) -> void ;

/* === client === */
auto main() -> int
{
        auto circle = Circle(10.0) ;
        auto selection = 0;

        do {
                selection = display_menu();
                execute_option(selection, circle);
        } while(selection != 6);
        return 0 ;
}

/* === custom functions === */

auto read_radius() -> double
{
        auto radius = std::nan("0") ;
        do {
                std::cout << "\n\tInput circle's radius: " ;
                std::cin >> radius;
        } while (radius <= 0.0) ;
        return radius;
}
auto display_menu() -> int
{
        auto selection = 0 ;

        do {
                std::cout << "\n\t<<< Circle's Menu >>>\n"
                          << "\n\t1. Display Radius"
                          << "\n\t2. Input Radius"
                          << "\n\t3. Display Diameter"
                          << "\n\t4. Display Circumference"
                          << "\n\t5. Display Area"
                          << "\n\t6. Exit Program" ;
                std::cout << "\n\tInput your option (1 - 6): " ;
                std::cin >> selection ;
        } while (selection < 1 || selection > 6) ;

        return selection ;
}
auto execute_option(int option, Circle &circle) -> void
{
        auto radius = std::nan("0") ;

        switch (option) {
        case 1: /*  Display Radius */
                circle.print() ;
                break ;
        case 2: /*  Input Radius */
                radius = read_radius() ;
                circle.set_radius(radius) ;
                break ;
        case 3: /*  Display Diameter */
                std::cout << "\n\tDiameter = " << circle.get_diameter()
                          << std::endl ;
                break ;
        case 4: /*  Display Circumference */
                std::cout << "\n\tCircumference = "
                          << circle.get_circumference() << std::endl ;
                break ;
        case 5: /*  Display Area */
                std::cout << "\n\tArea = " << circle.get_area() << std::endl ;
                break ;
        case 6: /*  Exit Program */
                break ;
        default:
                break ;
        } /* End of switch */
}
