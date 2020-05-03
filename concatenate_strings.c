//Program to read two strings(each one ending with a $ symbol), store them in an array and concatenate without using string library functions
#include<stdio.h>
#include<malloc.h>

char* read()
{
  char c, *str;
  int i=0;
  str = (char*)malloc(sizeof(char));    //dynamically allocating first position of str
  while((c=getchar()) !='\n')
  {
    str = (char*)realloc(str, (sizeof(char)));   //extending the sizing of str with demand
    *(str+i) = c;
    i++;
  }
  *(str+i) = '\0';
  return str;
}

char* concat(char *str1, char *str2)
{
  char *str3;
  int i,j;
  str3 = (char*)malloc(sizeof(char));
  for(i=0;*(str1+i)!='$';i++)
  {
    *(str3+i) = *(str1+i);
    str3 = (char*)realloc(str3, (sizeof(char)));
  }
  for(j=i;*(str2+j-i)!='\0';j++)
  {
    *(str3+j) = *(str2+j-i);
    str3 = (char*)realloc(str3, (sizeof(char)));
  }
  *(str3+j) = '\0';
  return str3;
}

int main(void)
{
  char *str1, *str2, *str3;
  printf("Enter String 1(end with $ symbol) : ");
  str1 = read();
  printf("Enter String 2(end with $ symbol) : ");
  str2 = read();
  str3 = concat(str1, str2);
  printf("Concatenated String : %s", str3);
  return 0;
}
