//program to read a given .txt file and print the twice without closing it
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  FILE *f1;
  char ch,filename[20];
  printf("Enter the file name (with file extension) : ");
  scanf("%s",filename);
  f1 = fopen(filename,"r");
  if(f1 == NULL)
  {
    printf("File Does not Exist.\n");
    return EXIT_FAILURE;
  }
  while((ch=fgetc(f1)) != EOF)
    printf("%c",ch);
  rewind(f1);
  while((ch=fgetc(f1)) != EOF)
    printf("%c",ch);
  fclose(f1);
  return EXIT_SUCCESS;
}
