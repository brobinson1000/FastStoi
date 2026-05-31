#include <iostream>
#include <string>
#include <cmath>
#include <chrono>
#include <string_view>

namespace fsti {

     int stoi(std::string& a) {
        const char* p = a.c_str();

        while (*p == ' ' || *p == '\t') p++;

        if (*p != '-' && (*p < '0' || *p > '9')) {return  0;}

        bool negative = false;
        if (*p == '-' ) { negative = true; p++; }
        else if ( *p == '+' ) { p++; }

        int result = 0;
        

        while (*p >= '0' && *p <= '9') {
            result = ((result << 3) + (result << 1)) + (*p - '0'); // attempt at bitshift op to reduce speed
            p++;
        }



        if (negative) result = -result;

        return result;




    }
}

int main() {

    std::string s = "12345";

    auto start = std::chrono::high_resolution_clock::now();

    int result = fsti::stoi(s);

    auto end = std::chrono::high_resolution_clock::now();

    auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    
    std::cout << "Result: " << result << "\n";
    std::cout << "Time: " << ns << " ns (" << us << " µs)\n";
}
