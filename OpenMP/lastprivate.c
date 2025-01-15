#include <stdio.h>
#include <omp.h>

int main() {
    int x = 0;

    #pragma omp parallel for lastprivate(x)
    for (int i = 0; i < 5; i++) {
        x = i;
        printf("Thread %d: x = %d\n", omp_get_thread_num(), x);
    }

    printf("Final value of x after parallel region: %d\n", x);
    return 0;
}
