//C program to read the details of n students with the fields name, rollno, marks and write the details in to a file. Then read the details from the file and display the name of the student who scored highest mark.
#include<stdio.h>
#include<stdlib.h>

typedef struct student                                    //struct to store the details of the student
{
    char name[20];
    int roll_no;
    float marks;
}s_t;

void read(s_t *p)                                          //read details from stdin
{
    printf("\nEnter the first name : ");
    scanf("%s", p->name);
    printf("Enter the Roll no: ");
    scanf("%d", &(p->roll_no));
    printf("Enter the marks : ");
    scanf("%f", &(p->marks));
}

void write(char filename[20], s_t p)                      // write details to the file
{
    FILE *f = fopen(filename, "a");
    if(f == NULL)
    {
        fprintf(stderr,"Failed to open the file");
        exit -1;
    }
    fprintf(f,"%s %d %f\n", p.name, p.roll_no, p.marks);
    fclose(f);
}
int main(void)
{
    s_t p,temp;
    char filename[20];
    int n, i;
    printf("Enter the filename : ");
    scanf("%s", filename);
    printf("Enter the number of students : ");
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        printf("Enter the details of student %d.\n", i+1);
        read(&p);
        write(filename,p);
    }
    FILE *f = fopen(filename, "r");
    i=0;
    while(fscanf(f,"%s %d %f\n", p.name, &(p.roll_no), &(p.marks) ) != EOF)
    {
        if(i == 0 || temp.marks<p.marks)
            temp = p;
        i=1;
    }
    fclose(f);
    printf("Student with highest mark is %s", temp.name);
    return 0;
}
