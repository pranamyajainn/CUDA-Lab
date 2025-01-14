%%cuda
#include <stdio.h>
#include <cuda.h>

#define N 256

__global__ void vectorMultiply(int *a, int *b, int *c, int n) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < n) {
        c[i] = a[i] * b[i];
    }
}

int main() {
    int n = N;

    int *a = (int *)malloc(n * sizeof(int));
    int *b = (int *)malloc(n * sizeof(int));
    int *c = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        b[i] = (i + 1) * 2;
    }

    int *d_a, *d_b, *d_c;

    cudaMalloc((void **)&d_a, n * sizeof(int));
    cudaMalloc((void **)&d_b, n * sizeof(int));
    cudaMalloc((void **)&d_c, n * sizeof(int));

    cudaMemcpy(d_a, a, n * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, n * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_c, c, n * sizeof(int), cudaMemcpyHostToDevice);

    int threadsPerBlock = 256;
    int blocksPerGrid = (n + threadsPerBlock - 1) / threadsPerBlock;
    vectorMultiply<<<blocksPerGrid, threadsPerBlock>>>(d_a, d_b, d_c, n);

    cudaDeviceSynchronize();

    cudaMemcpy(c, d_c, n * sizeof(int), cudaMemcpyDeviceToHost);

    int dotProduct = 0;
    for (int i = 0; i < n; i++) {
        dotProduct += c[i];
    }

    printf("Dot Product: %d\n", dotProduct);

    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);
    free(a);
    free(b);
    free(c);

    return 0;
}
