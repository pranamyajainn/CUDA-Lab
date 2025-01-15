#include <stdio.h>
#include <omp.h>

#pragma omp threadprivate(x)
int x = 0;

int main() {
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();

        if (thread_id == 0) {
            x = 10;
        } else if (thread_id == 1) {
            x = 20;
        }

        printf("Thread %d: x = %d\n", thread_id, x);
    }

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        printf("Thread %d (after second region): x = %d\n", thread_id, x);
    }

    return 0;
}
