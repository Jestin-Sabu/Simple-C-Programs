//Program to sort an Array using insertion sort Algorithm
#include<stdio.h>

void main(void){
  int A[100], n, temp;
  printf("Enter the no. of elements : ");
  scanf("%d", &n);
  printf("Enter the elements : ");
  for(int i=0; i<n; i++){
    scanf("%d", &A[i]);
    for(int j=i; j>0; j--)
      if(i > 0 && A[j-1] > A[j]){
        temp = A[j];
        A[j] = A[j-1];
        A[j-1] = temp;
      }
  }
  printf("Sorted Array : ");
  for(int i=0; i<n; i++)
      printf("%d ", A[i]);
}
