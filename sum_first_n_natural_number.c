//Program to determine the sum of first n natural numbers using a recursive function
#include<stdio.h>
#include<stdlib.h>

int helper(int n, int ans)
{
  if(n==0)
    return ans;
  else
  {
    ans = ans+n;
    return helper(n-1,ans);
  }
}

int sum(int n)
{
  if(n<0)
    n = n*(-1);
  return helper(n,0);
}

int main(void)
{
  int n;
  printf("Enter the number : ");
  scanf("%d",&n);
  if(n<0)
  {
    fprintf(stderr,"Enter a natural number.\n");
    return EXIT_FAILURE;
  }
  printf("Sum is %d.\n",sum(n));
  return EXIT_SUCCESS;
}
