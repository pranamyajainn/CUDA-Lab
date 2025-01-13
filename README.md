# CUDA-Lab

Prerequisites
CUDA Toolkit: Ensure you have the CUDA Toolkit installed on your system. You can download it from NVIDIA's official website.
OpenMP Support: Ensure your compiler supports OpenMP (e.g., gcc for Linux).
Compiler:
Use nvcc for CUDA programs.
Use gcc for OpenMP programs.

How to Run the Programs
CUDA Programs (Locally)
Open a terminal.
Navigate to the directory containing the .cu files.
Compile the desired program using nvcc (e.g., nvcc -o output_file source_file.cu).
Run the compiled program (e.g., ./output_file).
Example:

nvcc -o <file_name.cu> <file_name.out>

./<file_name.out>


OpenMP Programs
Open a terminal.
Navigate to the directory containing the .c files.
Compile the desired program using gcc with the -fopenmp flag (e.g., gcc -o output_file source_file.c -fopenmp).
Run the compiled program (e.g., ./output_file).
Example:

gcc -fopenmp <file_name.c> -o <file_name.out>

./<file_name.out>
