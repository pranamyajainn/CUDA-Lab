#include<stdio.h>
#include<omp.h>
#define n 10

int main(){
  int array[n] = {1,2,3,5,7,8,9,13,10,4};
  int largest_parallel = array[0];
  int largest_serial= array[0];

  #pragma omp parallel for
  for(int i=0;i<n;i++){
    #pragma omp critical{
      if(array[i] >largest_parallel){
          largest_parallel = array[i];
      }
  }
for(int i=0; i<n; i++){
  if(array[i] > largest_serial){
    largest_serial = array[i];
    }
}

printf("largest element in parallel: %d\n", largest_parallel);
printf("largest element in series: %d\n", largest_serial);

if(largest_parallel == largest_serial){
  printf("RESULT MATCHED.");
} else{ 
  printf("DONT MATCH.");
}
return 0;
}
