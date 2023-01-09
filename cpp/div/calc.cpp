#include <iostream>
#include <string>

int main (int argc,const char** argv) {
    if(argc==3) {
        const long double div1 = std::stold(argv[1]);
        const long double div2 = std::stold(argv[2]);
        std::cout << div1 / div2 << std::endl;
    } else {
        std::cout << "div: Please provide two decimal-number arguments." << std::endl;
        return 1;
    }

    return 0;
}
