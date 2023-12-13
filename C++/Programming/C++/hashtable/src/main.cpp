/* ========================================================================
 *
 *     Filename:  
 *  Description:  
 *       Author:  
 *      Version:  0.0.1
 *
 * ======================================================================== */
#include <iostream>
#include <fstream>

template<typename T>
using ptr = T*;

template<typename T>
using ref = T&;

auto count_words(ref<std::ifstream> stream) -> size_t
{
	auto ctr = 0lu;
	auto ch = '\0';
	while (!stream.eof()) {
		ch = stream.get();
		while (ch == ' ') ch = stream.get();
		++ctr;
	}
	return ctr;
}

struct FreqKV {

};

auto main() -> int
{
	auto file_path = "shakespeare.txt";
	auto f = std::ifstream(file_path, std::ios::binary);
	std::cout << (char)f.peek() << std::endl;
	std::cout << (char)f.peek() << std::endl;
	std::cout << (char)f.peek() << std::endl;
	std::cout << (char)f.peek() << std::endl;
	// std::cout << "words is: " << count_words(f) << "\n";
	return 0;
}

