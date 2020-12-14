//Program to sort an arrays in ascending order using merge sort algorithm
#include <stdio.h>

void Merge(int* A, int l, int m, int r){
  int n1 = m-l+1;
  int n2 = r-m;
  int B[n1], C[n2], i,j,k;
  for(i=0; i<n1; i++)
    B[i] = A[l+i];
  for(i=0; i<n2; i++)
    C[i] = A[m+i+1];
  for(i=0, j=0, k=l; i<n1 && j<n2; k++)
    A[k] = B[i]<=C[j]?B[i++]:C[j++];
  while(i<n1)
    A[k++] = B[i++];
  while(j<n2)
    A[k++] = C[j++];
}

void MergeSort(int* A, int l, int r){
  if(l<r){
    int m = (l+r-1)/2;
    MergeSort(A, l, m);
    MergeSort(A, m+1, r);
    Merge(A, l, m, r);
  }
}

int main(void){
  int A[100], n;
  printf("Enter the no. of elements : ");
  scanf("%d", &n);
  printf("Enter the elements : ");
  for(int i=0; i<n; i++)
    scanf("%d", &A[i]);
  MergeSort(A, 0, n-1);
  for(int i=0; i<n; i++)
    printf("%d ", A[i]);
  return 0;
}
