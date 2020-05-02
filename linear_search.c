//Program tosearch for an element in the array using an algorithm for Linear Search
#include<stdio.h>
#include<malloc.h>

int main()
{
  int n, *p, i, a, flag = 0;
  printf("Enter the no. of Elements : ");
  scanf("%d", &n);
  p = (int*)malloc(n*sizeof(int));
  printf("Enter the Elements : ");
  for(i=0;i<n;i++)
    scanf("%d", p+i);
  printf("Enter the Element to be searched : ");
  scanf("%d", &a);
  for(i=0;i<n;i++)
  {
    if(*(p+i) == a)
    {
      printf("Element found at position %d.\n", i+1);
      flag = 1;
    }
  }
  if(flag = 0)
    printf("Element not found.\n");
  return 0;
}
