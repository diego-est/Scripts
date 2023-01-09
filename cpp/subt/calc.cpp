#include <iostream>
#include <string>

int main(int argc,const char** argv) {
    if(argc==3) {
        const long double subt1 = std::stold(argv[1]);
        const long double subt2 = std::stold(argv[2]);
        std::cout << subt1 - subt2 << std::endl;
    } else {
        std::cout << "subt: Please provide two decimal-number arguments." << std::endl;
        return 1;
    }

    return 0;
}
