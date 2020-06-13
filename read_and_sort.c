//C program which inserts the elemnts into an array in a sorted fashion.
#include<stdio.h>
#include<malloc.h>

void sort(int *A, int n, int a)
{
  int temp;
  static int flag = 0;
  for(int i = 0; i<n; i++)
  {
    if((flag == 0) || (i == n-1))
    {
      flag = 1;
      A[i] = a;
      continue;
    }
    if(A[i] > a)
    {
      temp = A[i];
      A[i] = a;
      a = temp;
    }
  }
}

int main(void)
{
  int a,n;
  printf("Enter the limit : ");
  scanf("%d", &n);
  int *A = malloc(n*sizeof(*A));
  printf("Enter the input : ");
  for(int i = 0; i<n; i++)
  {
    scanf("%d", &a);
    sort(A, i+1, a);
  }
  printf("Sorted Array : ");
  for(int i=0; i<n; i++)
    printf("%d ", A[i]);
    free(A);
    return 0;
}
