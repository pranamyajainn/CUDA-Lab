#include <stdio.h>

// CUDA kernel to print a message
__global__ void printMessage() {
    int threadId = threadIdx.x + blockIdx.x * blockDim.x; // Unique thread ID
    printf("Thread %d: Welcome to Parallel Programming!\n", threadId);
}

int main() {
    int threads, blocks; // User-defined threads and blocks

    // Get user input
    printf("Enter the number of threads per block: ");
    scanf("%d", &threads);
    printf("Enter the number of blocks per grid: ");
    scanf("%d", &blocks);

    // Launch the kernel with user-defined configuration
    printMessage<<<blocks, threads>>>();

    // Wait for GPU to finish before exiting
    cudaDeviceSynchronize();

    return 0;
}
