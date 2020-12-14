//Program to sort an array in ascending order using quick sort and insertion sort
#include<stdio.h>

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int QuickSort(int* A, int left, int right){
  int i = left + 1;
    int pivot = A[left] ;
    for(int j=left+1; j<=right; j++) {
          if(A[j]<pivot)
                 swap(A+(i++), A+j);
   }
   swap(A+left, A+(--i)) ;
   return i;
}

void InsertionSort(int* A, int left, int right){
  for(int i=left+1; i<=right; i++){
    int ref = A[i];
    int j = i-1;
    while(j>=0 && A[j] > ref)
      A[j+1] = A[j--];
    A[j+1] = ref;
  }
}

void ComboSort(int*A, int left, int right){
  if(left<right){
    if(left-right > 5){
      int pivot = QuickSort(A, left, right);
      ComboSort(A, left, pivot-1);
      ComboSort(A, pivot+1, right);
    }
    else
      InsertionSort(A, left, right);
  }
}

int main(void){
  int A[100], n;
  printf("Enter the no. of elements : ");
  scanf("%d", &n);
  printf("Enter the elements : ");
  for(int i=0; i<n; i++)
    scanf("%d", &A[i]);
  ComboSort(A, 0, n-1);
  for(int i=0; i<n; i++)
    printf("%d ", A[i]);
  return 0;
}
