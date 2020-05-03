//Program to sort an Array using the Algorithm for Bubble sort
#include<stdio.h>
#include<malloc.h>

void sort(int *p, int n)       //sorting function
{
  int i, j, k, temp;
  for(i=1;i<n;i++)
  {
    for(j=0;j<n-i;j++)
    {
      if(*(p+j)>*(p+j+1))
      {
        temp = *(p+j);
        *(p+j) = *(p+j+1);
        *(p+j+1) = temp;
      }
    }
    printf("Pass %d : ", i);
    for(k=0;k<n;k++)
      printf("%d ",*(p+k));
    printf("\n");
  }
  printf("Sorting Completed.\n");
}

int main(void)
{
  int *p, n, i;
  printf("Enter the no. of Elements : ");
  scanf("%d", &n );
  p = (int*)malloc(n*sizeof(int));    //dynamically creating an Array.
  printf("Enter the Elements : ");
  for(i=0;i<n;i++)
    scanf("%d", p+i);
  sort(p,n);
  printf("Sorted Array \n");
  for(i=0;i<n;i++)
    printf("%d ", *(p+i));
  return 0;
}
