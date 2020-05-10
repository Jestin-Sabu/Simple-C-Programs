//program to count the no of vowels in a given .txt file
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    FILE *f1;
    char ch,filename[20];
    char vowel[]={'A','E','I','O','U','a','e','i','o','u'};
    int i, count = 0;
    printf("Enter the file name(with file extension) : ");
    scanf("%s", filename);
    f1 = fopen(filename,"r");   //opening the file
    if(f1 == NULL)        //checking whether the file has opened
    {
        printf("Failed to open the file.\n");
        return EXIT_FAILURE;
    }
    while((ch=fgetc(f1))!=EOF)    //reading upto the END OF FILE
    {
     for(i=0;i<10;i++)
     {
         if(ch == vowel[i])
            count++;
     }
    }
    fclose(f1);           //closing the file
    printf("No.of vowels in the given file is : %d.\n", count);
    return EXIT_SUCCESS;
}
