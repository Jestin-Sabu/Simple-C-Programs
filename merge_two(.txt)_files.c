//program to merge two given .txt files into a new .txt file of your choice
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    FILE *f1,*f2;
    char ch, filename1[20], filename2[20], filename3[20];
    printf("Enter the file name(with file extension) : ");
    scanf("%s", filename1);
    f1 = fopen(filename1,"a");
    printf("Enter the Second file name(with file extension) : ");
    scanf("%s", filename2);
    f2 = fopen(filename2,"r");
    if(f2 == NULL)
    {
        printf("Second file does not exist.\n");
        return EXIT_FAILURE;
    }
    while((ch=fgetc(f2)) != EOF)
    {
        fputc(ch,f1);
    }
    printf("Enter the new filename : ");
    scanf("%s", filename3);
    fclose(f1);
    fclose(f2);
    rename(filename1, filename3);
    remove(filename2);
    return EXIT_SUCCESS;
}
