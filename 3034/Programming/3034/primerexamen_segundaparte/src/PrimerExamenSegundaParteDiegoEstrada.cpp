/* ========================================================================
 *
 *     Filename:  main.cpp
 *  Description:  Primer examen segunda parte
 *       Author:  Diego A. Estrada Rivera
 *      Version:  0.0.1
 *
 * ======================================================================== */
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

/* === Person class declaration === */
#ifndef PERSON_H
#define PERSON_H
class Person {
      private:
	std::string m_first;
	std::string m_last;

      public:
	/* parameterized constructor with default parameters */
	Person(std::string const& first = "", std::string const& last = "");

	/* Destructor */
	~Person();

	/* Getters */
	auto get_first_name() const -> std::string;
	auto get_last_name() const -> std::string;
	auto get_full_name(std::string& first, std::string& last) const -> void;
	auto print() const -> void;

	/* Setters */
	auto set_first_name(std::string const& first) -> void;
	auto set_last_name(std::string const& last) -> void;
	auto set_full_name(std::string const& first, std::string const& last)
	    -> void;
};
#endif
/* === Person class definition === */
Person::Person(std::string const& first, std::string const& last)
    : m_first(first), m_last(last)
{
}

/* Destructor */
Person::~Person()
{
}

/* Getters */
auto Person::get_first_name() const -> std::string
{
	return m_first;
}

auto Person::get_last_name() const -> std::string
{
	return m_last;
}

auto Person::get_full_name(std::string& first, std::string& last) const -> void
{
	first = m_first;
	last = m_last;
}

auto Person::print() const -> void
{
	std::cout << "\n\tFirst name: " << m_first;
	std::cout << "\n\tLast name: " << m_last << "\n";
}

/* Setters */
auto Person::set_first_name(std::string const& first) -> void
{
	m_first = first;
}

auto Person::set_last_name(std::string const& last) -> void
{
	m_last = last;
}

auto Person::set_full_name(std::string const& first, std::string const& last)
    -> void
{
	m_first = first;
	m_last = last;
}

/* === Employee class declaration === */
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
class Employee : public Person {
      private:
	double m_salary;
	double m_hours;

      public:
	/* parameterized constructor with default parameters. */
	Employee(std::string const& first, std::string const& last, double hs,
		 double hw);

	/* Destructor */
	~Employee();

	/* Getters */
	auto get_hourly_salary() const -> double;
	auto get_hours_worked() const -> double;
	auto get_weekly_salary() const -> double;
	auto print() const -> void;

	/* Setters */
	auto set_hourly_salary(double hs) -> void;
	auto set_hours_worked(double hw) -> void;
};
#endif
/* === Employee class definition === */
Employee::Employee(std::string const& first, std::string const& last, double hs,
		   double hw)
    : Person(first, last), m_salary(hs), m_hours(hw)
{
}

/* Destructor */
Employee::~Employee()
{
}

/* Getters */
auto Employee::get_hourly_salary() const -> double
{
	return m_salary;
}

auto Employee::get_hours_worked() const -> double
{
	return m_hours;
}

auto Employee::get_weekly_salary() const -> double
{
	return m_salary * m_hours;
}

auto Employee::print() const -> void
{
	Person::print();
	std::cout << "\n\tHourly salary: " << m_salary;
	std::cout << "\n\tHours worked: " << m_hours;
	std::cout << "\n\tWeekly salary: " << get_weekly_salary();
}

/* Setters */
auto Employee::set_hourly_salary(double hs) -> void
{
	m_salary = hs;
}

auto Employee::set_hours_worked(double hw) -> void
{
	m_hours = hw;
}

/* === class application === */
auto read_payroll(std::vector<Employee>& payroll) -> void;
auto display_payroll(std::vector<Employee> const& payroll) -> void;

auto main() -> int
{
	auto size = 0u;

	do {
		std::cout << "\nInput number of employees (> 0): ";
		std::cin >> size;
	} while (size < 1);

	auto payroll = std::vector<Employee>(size, Employee("", "", 0.0, 0.0));
	read_payroll(payroll);
	display_payroll(payroll);
	return 0;
}

auto read_payroll(std::vector<Employee>& payroll) -> void
{
	auto first = std::string("");
	auto last = std::string("");
	auto hs = std::nan("0");
	auto hw = std::nan("0");
	auto ctr = 1;

	for (auto& employee : payroll) {
		std::cout << "\nInput data for employee " << ctr << ")"
			  << std::endl;
		std::cout << "Input first name: ";
		std::cin >> first;
		std::cout << "Input last name: ";
		std::cin >> last;
		std::cout << "Input hourly salary: ";
		std::cin >> hs;
		std::cout << "Input hours worked: ";
		std::cin >> hw;

		employee.set_first_name(first);
		employee.set_last_name(last);
		employee.set_hourly_salary(hs);
		employee.set_hours_worked(hw);
		ctr++;
	}
}

auto display_payroll(std::vector<Employee> const& payroll) -> void
{
	std::cout << "\n<<< Payroll file >>>\n";
	auto ctr = 1;
	for (auto const& employee : payroll) {
		std::cout << std::endl
			  << "Employee " << ctr << ")" << std::endl;
		employee.print();
		ctr++;
	}
	std::cout << std::endl;
}
