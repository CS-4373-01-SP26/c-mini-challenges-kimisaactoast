// 4. Compare the speed of *,/,sqrt, sin operations/functions.

#include <stdio.h>
#include <time.h>
#include <math.h>

#define ITERATIONS 100000000

int main () {
    double x = 1.2345;
    double y = 6.7890;
    volatile double result = 0;

    // 1. multiplication

    clock_t start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        result = x * y;
    }
    clock_t end = clock();
    printf("Time Taken (Multiplication): %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 2. division

    start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        result = x / y;
    }
    end = clock();
    printf("Time Taken (Division): %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 3. sqrt

    start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        result = sqrt(x);
    }
    end = clock();
    printf("Time Taken (Sqrt): %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 4. sin function

    start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        result = sin(x);
    }
    end = clock();
    printf("Time Taken (Sin Function): %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}