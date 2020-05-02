//Program to reverse the order of elements in an array
#include<stdio.h>
#include<malloc.h>

int main(void)
{
  int n, i, j, temp;
  int *p;
  printf("Enter the no. of Elements : ");
  scanf("%d", &n);
  p = (int*)malloc(n*sizeof(int));
  printf("Enter the elements : ");
  for(i=0;i<n;i++)
    scanf("%d", p+i);
  for(i=0,j=n-1;i<n/2;i++,j--)
  {
    temp = *(p+i);
    *(p+i) = *(p+j);
    *(p+j) = temp;
  }
  printf("Reversed Array : ");
  for(i=0;i<n;i++)
    printf("%d ", *(p+i));
  return 0;
}
