#include <stdio.h>
#include <omp.h>

int main() {
    // Print the number of processors available
    int num_procs = omp_get_num_procs();
    printf("Number of processors available: %d\n", num_procs);

    // Print maximum threads OpenMP can use
    int max_threads = omp_get_max_threads();
    printf("Maximum threads OpenMP can use: %d\n", max_threads);

    // Start a parallel region
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();   // Get thread ID
        int total_threads = omp_get_num_threads(); // Get total threads
        if (thread_id == 0) {
            printf("Total threads in parallel region: %d\n", total_threads);
        }

        printf("Hello from thread %d\n", thread_id);
    }

    return 0;
}
