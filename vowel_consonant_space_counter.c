//Program to read a string (ending with $ symbol) and count the number of vowels, consonants and spaces
#include<stdio.h>

int vowel(char word)
{
  int i;
  int reference[] = {'a','e','i','o','u','A','E','I','O','U'};
  for(i=0;i<10;i++)
  {
    if(reference[i] == word)
      return 1;
  }
  return 0;
}

int alphabet(char word)
{
  if((word>='A' && word<='z') || (word>='a' && word<='z'))
    return 1;
  else
    return 0;
}

int space(char word)
{
  if(word == ' ')
    return 1;
  else
    return 0;
}

int main(void)
{
  int i,v = 0,a = 0,s = 0;
  char word[50];
  printf("Enter the Sentence(end with $ symbol) : ");
  scanf("%[^\n]", word);
  for(i=0;word[i]!='$';i++)
  {
    v += vowel(word[i]);
    a += alphabet(word[i]);
    s += space(word[i]);
  }
  printf("No. of vowel(s) : %d.\n", v);
  printf("No. of consonant(s) : %d.\n", a-v);
  printf("No. of space(s) : %d.\n", s);
  return 0;
}
