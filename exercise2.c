// 2. Implement Archimedes algorithm to estimate pi for inscribed/circumscribed polygons with n sides, up to 100, doubling n at each step, and time it.

#include <stdio.h>
#include <math.h>
#include <time.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double archimedes_inscribed(int n) {
    return 2 * n * sin(M_PI / n);
}

double archimedes_circumscribed(int n) {
    return 2 * n * tan(M_PI / n);
}

int main () {
    int n = 6; // archimedes method starts with hexagon
    printf("Inscribed: \n");
    
    // Inscribed
    clock_t start = clock();
    for (; n <= 100; n*=2) {
        double estimate = archimedes_inscribed(n) / 2.0;
        printf("%d\t%f\n", n, estimate);
    }
    clock_t end = clock();

    // clock tick difference must be divided by number of clock ticks per second
    printf("Time Taken (Inscribed): %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

    printf("\n");

    // Circumscribed
    n = 6;
    printf("Circumscribed: \n");
    
    start = clock();

    for (; n <= 100; n*=2) {
        double estimate = archimedes_circumscribed(n) / 2.0;
        printf("%d\t%f\n", n, estimate);
    }
    end = clock();

    printf("Time Taken (Circumscribed): %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}