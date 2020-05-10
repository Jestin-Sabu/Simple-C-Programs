//program to copy the contents of a given .txt file to a new .txt file
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    FILE *f1,*f2;
    char ch, filename[20];
    printf("Enter the filename(with file extension) : ");
    scanf("%s", filename);
    f1 = fopen(filename,"r");
    if(f1 == NULL)
    {
        printf("File does not exist.\n");
        return EXIT_FAILURE;
    }
    printf("Enter the new filename(with file extension) : ");
    scanf("%s", filename);
    f2 = fopen(filename,"w");
    while((ch=fgetc(f1)) != EOF)
        fputc(ch,f2);
    printf("Contents successfully copied.\n");
    fclose(f1);
    fclose(f2);
    return EXIT_SUCCESS;
}
