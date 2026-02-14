// 4. Compare the speed of *,/,sqrt, sin operations/functions.

#include <stdio.h>
#include <time.h>
#include <math.h>

#define ITERATIONS 100000000

double get_time_diff(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

int main () {
    double x = 1.2345;
    double y = 6.7890;
    volatile double result = 0;

    struct timespec start, end;

    // 1. multiplication

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < ITERATIONS; i++) {
        result = x * y;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("Time Taken (Multiplication): %.9f s\n", get_time_diff(start, end));

    // 2. division

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < ITERATIONS; i++) {
        result = x / y;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("Time Taken (Division): %.9f s\n", get_time_diff(start, end));

    // 3. sqrt

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < ITERATIONS; i++) {
        result = sqrt(x);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("Time Taken (Sqrt): %.9f s\n", get_time_diff(start, end));

    // 4. sin function

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < ITERATIONS; i++) {
        result = sin(x);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("Time Taken (Sin Function): %.9f s\n", get_time_diff(start, end));

    return 0;
}