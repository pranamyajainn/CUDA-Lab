#include <stdio.h>
#include <omp.h>

int main() {
    int n;

    // Input the size of the arrays
    printf("Enter the size of the arrays: ");
    scanf("%d", &n);

    int A[n], B[n], C_add[n], C_sub[n];

    // Initialize arrays A and B
    printf("Enter elements of array A:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter elements of array B:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    // Parallel sections for addition and subtraction
    #pragma omp parallel sections
    {
        // Section 1: Perform addition
        #pragma omp section
        {
            for (int i = 0; i < n; i++) {
                C_add[i] = A[i] + B[i];
                printf("Thread %d: A[%d] + B[%d] = %d\n",
                       omp_get_thread_num(), i, i, C_add[i]);
            }
        }

        // Section 2: Perform subtraction
        #pragma omp section
        {
            for (int i = 0; i < n; i++) {
                C_sub[i] = A[i] - B[i];
                printf("Thread %d: A[%d] - B[%d] = %d\n",
                       omp_get_thread_num(), i, i, C_sub[i]);
            }
        }
    }

    // Print the results
    printf("\nResult of Addition:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", C_add[i]);
    }
    printf("\n");

    printf("\nResult of Subtraction:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", C_sub[i]);
    }
    printf("\n");

    return 0;
}
