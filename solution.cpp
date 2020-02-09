#include <cstdlib>
#include <iostream>
/* This program inputs two numbers x and y and outputs their sum */

int main1() {
    int x, y;
    std::cout << "Please enter two numbers: ";
    std::cin >> x >> y; // input x and y
    int sum = x + y; // compute their sum
    std::cout << "Their sum is " << sum << std::endl;
    // return EXIT SUCCESS; // terminate successfully
    return 0;
}
