#include<stdio.h>
#include<omp.h>
#define n 3
int main() {
  int A[n][n], B[n][n], C[n][n];

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      A[i][j]= i+j;
      B[i][j]= i-j;
      C[i][j]=0;
    }
  }
#pragma omp parallel for collapse(2)
for(int i=0; i<n;i++){
   for(int j=0; j<n; j++){
        for(int k=0; k<n; k++){
          C[i][j] +=A[i][k] * B[k][j];
        }
   }
}
printf("RESULT:\n");
for(int i=0; i<n;i++){
   for(int j=0; j<n; j++){
      printf("%d ", C[i][j]);
   }
printf("\n");
}
return 0;
}

