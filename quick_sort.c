//Program to sort an array in ascending order using quick sort algorithm
#include<stdio.h>

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int QuickSortHelper(int* A, int left, int right){
  int i = left + 1;
  int pivot = A[left] ;
  for(int j=left+1; j<=right; j++) {
        if(A[j]<pivot)
               swap(A+(i++), A+j);
 }
 swap(A+left, A+(--i)) ;
 return i;
}

void QuickSort(int* A, int left, int right){
  if(left<right){
    int pivot = QuickSortHelper(A, left, right);
    QuickSort(A, left, pivot-1);
    QuickSort(A, pivot+1, right);
  }
}

int main(void){
  int A[100], n;
  printf("Enter the no. of elements : ");
  scanf("%d", &n);
  printf("Enter the elements : ");
  for(int i=0; i<n; i++)
    scanf("%d", &A[i]);
  QuickSort(A, 0, n-1);
  for(int i=0; i<n; i++)
    printf("%d ", A[i]);
  return 0;
}
