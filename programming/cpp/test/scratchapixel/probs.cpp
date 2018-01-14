// Taken from
// https://www.scratchapixel.com/lessons/mathematics-physics-for-computer-graphics/monte-carlo-methods-mathematical-foundations/probability-distribution-part1

// The program will calculate the probability of rolling a n for n =
// 0-N. Run the program with N as the input

#include <iostream>
#include <cstdlib> 
#include <cstdio> 
#include <iostream>

// Original file didn't have the math header included
#include <math.h>

inline uint64_t fact(uint64_t x) { 
  return (x <= 1 ? 1 : x * fact(x - 1)); 
} 
 
int main(int argc, char **argv) 
{ 
    uint64_t N = atoi(argv[1]); 
    uint64_t Nfac = fact(N); 
    for (uint64_t n = 0; n <= N; ++n) { 
        uint64_t CnN = Nfac / (fact(n) * fact(N-n)); 
        double prob = CnN * powf(0.5, n) * powf(1 - 0.5, N - n); 
        std::cout << n << " " << prob << std::endl; 
    } 
 
    return 0; 
}
