#include <iostream>

#define HELLO 1
#define MAX_SIZE 20

int main() {
    unsigned int byte = 13;
    byte <<= 3;
    byte >>= 3;

    std::cout << byte << " " << HELLO << std::endl;
    int a = HELLO;
    std::cout << a << std::endl;
    a = ++a;
    std::cout << a << std::endl;
    a = a++;
    std::cout << a << std::endl;
    return 0;
}