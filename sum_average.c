#include<stdio.h>
#include<malloc.h>

int main (void)
{
  int n,*p, i, s = 0;
  printf("Enter the no. of Elements : ");
  scanf("%d", &n);
  p = (int*)malloc(n*sizeof(int));
  printf("Enter the Elements : ");
  for(i=0;i<n;i++)
  {
    scanf("%d", p+i);
    s += *(p+i);
  }
  printf("Sum is %d.\n", s);
  printf("Average is %f.\n", s/(float)n);
  return 0;
}
