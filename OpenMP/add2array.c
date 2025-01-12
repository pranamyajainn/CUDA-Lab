#include <stdio.h>
#include <omp.h>

int main() {
    int n = 5; // Size of the arrays
    int a[5] = {1, 2, 3, 4, 5}; // First array
    int b[5] = {5, 4, 3, 2, 1}; // Second array
    int c[5]; // Resultant array

    int chunk_size = 2; // Define chunk size for dynamic scheduling

    // Perform parallel addition
    #pragma omp parallel for schedule(dynamic, chunk_size)
    for (int i = 0; i < n; i++) {
        c[i] = a[i] + b[i]; // Add corresponding elements
        printf("Thread %d added index %d: %d + %d = %d\n",
               omp_get_thread_num(), i, a[i], b[i], c[i]);
    }

    // Print the resulting array
    printf("\nResulting array C:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");

    return 0;
}
