//Program to check whether a given number is armstrong or not
#include<stdio.h>
#include<math.h>

int main(void)
{
    int a, b, l=0, s=0;
    printf("Enter the number : ");
    scanf("%d", &a);
    b = a;
    while(b!=0)
    {
      b /= 10;
      l++;
    }
  b = a;
  while(b!=0)
  {
    s += pow(b%10,l);
    b /= 10;
  }
  if(s == a)
    printf("%d is an Armstrong Number.\n", a);
  else
    printf("%d is not an Armstrong Number.\n", a );
  return 0;
}
