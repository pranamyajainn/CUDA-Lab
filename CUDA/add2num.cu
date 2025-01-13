#include <stdio.h>

// CUDA kernel to add two numbers
__global__ void addNumbers(int *a, int *b, int *c) {
    *c = *a + *b;
}

int main() {
    int a = 5, b = 3, c;
    int *d_a, *d_b, *d_c;

    // Allocate memory on the device
    cudaMalloc((void **)&d_a, sizeof(int));
    cudaMalloc((void **)&d_b, sizeof(int));
    cudaMalloc((void **)&d_c, sizeof(int));

    // Copy input values to the device
    cudaMemcpy(d_a, &a, sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, &b, sizeof(int), cudaMemcpyHostToDevice);

    // Launch the kernel
    addNumbers<<<1, 1>>>(d_a, d_b, d_c);

    // Copy result back to host
    cudaMemcpy(&c, d_c, sizeof(int), cudaMemcpyDeviceToHost);

    printf("Result: %d + %d = %d\n", a, b, c);

    // Free device memory
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    return 0;
}
