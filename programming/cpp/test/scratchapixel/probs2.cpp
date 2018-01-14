// Taken from
// https://www.scratchapixel.com/lessons/mathematics-physics-for-computer-graphics/monte-carlo-methods-mathematical-foundations/expected-value

// This program will roll a die 1000 times, each time adding the
// result of the throw to the running sum and dividing by the total
// number of throws to get the running mean

#include <random> 
#include <cstdlib> 
#include <cstdio>
#include <math.h>
 
int main(int argc, char **argv) 
{ 
    std::mt19937 rng; 
    rng.seed(2013); 
    std::uniform_int_distribution<uint32_t> die(1,6); 
    int sum = 0; 
    for (int n = 1; n <= 1000; n++) { // number of trials = n 
        int rnd = die(rng); // result of our random variable X 
        sum += rnd; // update sum 
        printf("Trial #%d: result = %i, running mean = %f\n", n, rnd, float(sum) / n); // print out sample mean 
    } 
 
    return 0; 
} 
