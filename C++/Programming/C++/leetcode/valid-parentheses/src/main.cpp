/* ========================================================================
 *
 *     Filename:  
 *  Description:  
 *       Author:  
 *      Version:  0.0.1
 *
 * ======================================================================== */
#include <iostream>
#include <string>
#include <stack>

auto isValid(std::string s) -> bool;

auto main() -> int
{
	std::cout << isValid("()") << std::endl;
	return 0;
}

auto isValid(std::string s) -> bool
{
	auto st = std::stack<char>();

	for (const auto& ch : s) {
		char check = '\0';
		switch (ch) {
			case '(':
			case '{':
			case '[':
				st.push(ch);
				continue;
			case ')':
				check = '(';
				break;
			case '}':
				check = '{';
				break;
			case ']':
				check = '[';
				break;
			default: continue;
		}
		if (not st.empty()) {
			if (st.top() == check)
				st.pop();
			else
				return false;
		} else {
			return false;
		}
			

	}

	return st.empty();
}
