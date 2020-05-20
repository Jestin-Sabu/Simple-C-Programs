//Program to determine the digit sum using a recursive function
#include<stdio.h>
#include<stdlib.h>

int helper(int n, int ans)
{
  if(n==0)
    return ans;
  else
  {
    ans = ans+n%10;
    return helper(n/10,ans);
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
  printf("Digit sum is %d.\n",sum(n));
  return EXIT_SUCCESS;
}
