//program to check whether the given string(word) is palindrome or not
#include<stdio.h>

int main(void)
{
  int i, c, flag = 1;
  char word[50];
  printf("Enter the string(word) : ");
  scanf("%s", word);
  for(c=0;word[c]!='\0';c++);   // finding the length of string
  for(i=0;i<c/2;i++)
  {
    if(word[i]!=word[c-i-1])
      flag = 0;
  }
  if(flag == 1)
    printf("The word \"%s\" is a palindrome.", word);
  else
      printf("The word \"%s\" is not a palindrome.", word);
  return 0;
}
