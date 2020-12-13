//Program to sort an array in ascending order using heap sort algorithm
#include<stdio.h>

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Heapify(int* A, int n, int p){
  int s = p;
  int l = 2*p + 1;
  int r = 2*p + 2;
  if(l<n && A[l] < A[s])
    s = l;
  if(r<n && A[r] < A[s])
    s = r;
  if(s != p){
    swap(A+p, A+s);
    Heapify(A, n, s);
  }
}


void HeapSort(int* A, int n){
  for(int p = n/2-1; p>=0; p--)
    Heapify(A,n,p);
  for(int i=n-1; i>=0; i--){
    swap(A, A+i);
    Heapify(A, i, 0);
  }
}

int main(void){
  int A[100], n;
  printf("Enter the array size : ");
  scanf("%d", &n);
  printf("Enter the elements : ");
  for(int i=0; i<n; i++)
    scanf("%d", &A[i]);
  HeapSort(A,n);
  printf("\nSorted Array : ");
  for(int i=0; i<n; i++)
    printf("%d ", A[i]);
  return 0;
}
