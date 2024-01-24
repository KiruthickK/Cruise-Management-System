#include <iostream>
#include <sstream>
#include <string>

int main() {
    // Example string
    std::string input_string = "6 7 8 9 10 11 12 13 14 15";

    // Use std::istringstream to split the string
    std::istringstream iss(input_string);
    std::string word;

    // Read each word from the stringstream
    while (iss >> word) {
        std::cout << word << std::endl;
    }

    return 0;
}
