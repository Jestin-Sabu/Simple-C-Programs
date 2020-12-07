//Program to sort an Array using the algorithm for selection sort
#include <stdio.h>

void main(void)
{
  int A[100], n, k, temp;
  printf("Enter the number of elements : ");
  scanf("%d", &n);
  printf("Enter the elements : ");
  for(int i=0; i<n; i++)
    scanf("%d", &A[i]);
  for(int i=0; i<n-1; i++)
  {
    k = i;
    for(int j = i+1; j<n; j++)
      if(A[j]<A[i])
        k=j;
    if(k != i){
      temp = A[i];
      A[i] = A[k];
      A[k] = temp;
    }
  }
  printf("Sorted Array : ");
  for(int i=0; i<n; i++)
      printf("%d ", A[i]);
}
