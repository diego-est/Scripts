#include <iostream>

void helpText()
{
    std::cout << "Usage: ale [azimuth angle] [crit. hour start] [crit. hour end] [\% efficiency]\n";
}

int main(int argc, char** argv) {
    int azimuth = (int) strtol(argv[1], NULL, 0);
    int angle = std::min(azimuth, abs(azimuth - 360) );

    while(angle >= 360) {
        angle = std::min(angle, abs(angle - 360) );
    }
    std::cout << angle;
    //helpText();

    return 0;
}
