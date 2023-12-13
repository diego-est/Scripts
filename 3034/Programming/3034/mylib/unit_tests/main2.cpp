#include "../data.hpp"
#include "../stack.hpp"

auto display_binary(Stack bs) -> void;
auto read_decimal() -> int;
auto repeated_division(int decimal) -> Stack;

auto main() -> int
{
	auto input = 0;
	auto answer = std::string("");
	do {
		std::cout << "Continue (y/n): ";
		std::cin >> answer;
	} while (answer == "y" || answer == "Y");
	auto binary = Stack();
	auto decimal = read_decimal();
	binary = repeated_division(decimal);
	display_binary(binary);
}

auto display_binary(Stack bs) -> void
{
	bs.print();
}

auto read_decimal() -> int
{
	auto a = 0;
	std::cin >> a;
	return a;
}

auto repeated_division(int decimal) -> Stack
{
	auto tmp = Stack();
	if (decimal == 0) tmp.push(0);
	while (decimal != 0)
		tmp.push(decimal % 2), decimal /= 2;
	return tmp;
}
