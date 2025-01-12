#include <stdio.h>
#include <omp.h>

#define n 1000 // Size of the array

int main() {
    int a[n]; // Array to hold the data
    int sum = 0; // Variable to hold the sum

    // Initialize the array with values
    for (int i = 0; i < n; i++) {
        a[i] = i + 1; // Fill the array with values 1, 2, ..., N
    }

    // Parallel computation of sum using reduction clause
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++) {
        sum = sum + a[i];
    }

    // Print the final result
    printf("Sum of array elements: %d\n", sum);

    return 0;
}
