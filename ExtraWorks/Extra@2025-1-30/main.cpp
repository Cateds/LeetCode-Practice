#include <cmath>
#include <format>
#include <iostream>
#include <numeric>

int main(void) {
    long long length = 343720 * 2, width = 233333 * 2;
    long long dx = 15, dy = 17;
    long long step = std::lcm(dx, length) / dx;
    for (long long i = step; true; i += step) {
        if (i * dy % width)
            continue;
        std::cout << std::format("t: {}\n", i);
        std::cout << std::format(
            "length: {:.2f}\n",
            i * sqrt(dx * dx + dy * dy));
        break;
    }
}