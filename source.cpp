#include <iostream>
#include <cstdlib>
#include <string>
#include <climits>
#include <cerrno>

int main(int argc, char* argv[]) {
    if(argc != 3 || std::string(argv[1]) != "--number") {
        std::cerr << "Usage: " << argv[0] << " --number value" << std::endl;
        return 1;
    }

    errno = 0;
    long long number = std::strtoll(argv[2], nullptr, 10);
    if(errno == ERANGE || number > INT_MAX || number < INT_MIN) {
        return 1;
    }

    number += 1;

    if(number > INT_MAX) {
        return 1;
    }

    std::cout << number << std::endl;

    return 0;
}