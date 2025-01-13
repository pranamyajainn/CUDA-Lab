#include <stdio.h>

#define N 2 // Matrix size (N x N)

// CUDA kernel for matrix addition
__global__ void matrixAdd(int *a, int *b, int *c) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < N * N) {
        c[idx] = a[idx] + b[idx];
    }
}

int main() {
    int size = N * N; // Total number of elements
    int a[N][N] = {{1, 2}, {3, 4}}; // Matrix A
    int b[N][N] = {{5, 6}, {7, 8}}; // Matrix B
    int c[N][N]; // Resultant matrix C

    int *d_a, *d_b, *d_c;

    // Allocate memory on the device
    cudaMalloc((void **)&d_a, size * sizeof(int));
    cudaMalloc((void **)&d_b, size * sizeof(int));
    cudaMalloc((void **)&d_c, size * sizeof(int));

    // Copy input matrices to the device
    cudaMemcpy(d_a, a, size * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, size * sizeof(int), cudaMemcpyHostToDevice);

    // Launch the kernel
    matrixAdd<<<1, size>>>(d_a, d_b, d_c);

    // Copy result back to host
    cudaMemcpy(c, d_c, size * sizeof(int), cudaMemcpyDeviceToHost);

    // Print the result
    printf("Resultant Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Free device memory
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    return 0;
}
