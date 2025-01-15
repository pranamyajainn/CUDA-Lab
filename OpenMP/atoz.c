#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel for
    for (char c = 'a'; c <= 'z'; c++) {
        printf("%c ", c);
    }
    printf("\n");
    return 0;
}
