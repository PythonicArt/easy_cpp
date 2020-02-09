#include "a.h"
#include <iostream>

extern int mm;

int f();

int main(int argc, char const *argv[]) {
    int a = f();
    std::cout <<a << std::endl;
    std::cout << mm <<std::endl;
    return 0;
}
