#include <iostream>
#include "Decryptor.hh"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Please pass filename as argument" << std::endl;
        return -1;
    }
    Decryptor c(argv[1], 5);
    std::cout << "Preprocessing finished" << std::endl;
    while (std::cin) {
        std::string key;
        std::cin >> key;
        std::cout << c.GetValue(key) << std::endl;
    }
    return 0;
}
