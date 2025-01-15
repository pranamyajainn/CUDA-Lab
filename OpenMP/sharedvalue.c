#include <stdio.h>
#include <omp.h>

int main() {
    int shared_var = 0;

    #pragma omp parallel num_threads(4)
    {
        int thread_id = omp_get_thread_num();

        #pragma omp critical
        {
            shared_var++;
            printf("Thread %d incremented shared_var to %d\n", thread_id, shared_var);
        }
    }

    printf("Final value of shared_var: %d\n", shared_var);
    return 0;
}
