//Program to check whether the given number is prime or not
#include<stdio.h>

int main()
{
  int a, b = 0, i;
  printf("Enter the number : ");
  scanf("%d", &a);
  if(a < 2)
  {
    printf("%d is not a Prime Number.", a);
    return 0;
  }
  for(i=2;i<=a/2;i++);
  {
    if(a%i==0)
      b = 1;
      break;
  }
  if(b==0)
    printf("%d is a Prime Number.\n", a);
  else
    printf("%d is not a Prime Number.\n", a);
  return 0;
}
