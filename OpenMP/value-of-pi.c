#include <stdio.h>
#include <omp.h>

int main() {
    int num_steps = 1000000; // Number of terms
    double pi = 0.0;
    double step = 1.0 / num_steps;

    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < num_steps; i++) {
            double x = (i + 0.5) * step;
            #pragma omp critical
            pi += 4.0 / (1.0 + x * x);
        }
    }

    pi *= step; // Final computation
    printf("Value of PI: %.6f\n", pi);
    return 0;
}
