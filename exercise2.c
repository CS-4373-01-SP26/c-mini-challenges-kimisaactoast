// 2. Implement Archimedes algorithm to estimate pi for inscribed/circumscribed polygons with n sides, up to 100, doubling n at each step, and time it.

#include <stdio.h>
#include <math.h>
#include <time.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double get_time_diff(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

double archimedes_inscribed(int n) {
    return 2 * n * sin(M_PI / n);
}

double archimedes_circumscribed(int n) {
    return 2 * n * tan(M_PI / n);
}

int main () {
    int n = 6; // archimedes method starts with hexagon
    struct timespec start, end;
    printf("Inscribed: \n");
    
    // Inscribed
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (; n <= 100; n*=2) {
        double estimate = archimedes_inscribed(n) / 2.0;
        printf("%d\t%f\n", n, estimate);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);

    // clock tick difference must be divided by number of clock ticks per second
    printf("Time Taken (Inscribed): %.9f s\n\n", get_time_diff(start, end));

    printf("\n");

    // Circumscribed
    n = 6;
    printf("Circumscribed: \n");
    
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (; n <= 100; n*=2) {
        double estimate = archimedes_circumscribed(n) / 2.0;
        printf("%d\t%f\n", n, estimate);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);

    printf("Time Taken (Circumscribed): %.9f s\n", get_time_diff(start, end));

    return 0;
}