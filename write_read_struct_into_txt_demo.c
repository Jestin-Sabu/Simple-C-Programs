//sample program to demostrate reading and writing a structure into ax txt file
#include<stdio.h>
#include<stdlib.h>

typedef struct employee
{
    char name[20],empid[20];
    int salary;
}employee_t;

int main(void)
{
    int n,i;
    employee_t e,temp;
    FILE *f1 = fopen("employee.txt","w");
    printf("Enter the number of employees : ");
    scanf("%d", &n);
    printf("Enter the Details\n");
    for(i=0;i<n;i++)
    {
        printf("Employee %d\n",i+1);
        printf("Name        : ");
        scanf("%s",e.name);
        printf("Employee id : ");
        scanf("%s",e.empid);
        printf("Salary      : ");
        scanf("%d",&e.salary);
        printf("\n");
        fprintf(f1,"%s %s %d\n",e.name,e.empid,e.salary);
    }
    fclose(f1);
    f1 = fopen("employee.txt","r");
    temp.salary = 0;
    while(fscanf(f1,"%s %s %d\n",e.name,e.empid,&e.salary) != EOF)
    {
        if(e.salary>temp.salary)
            temp = e;
    }
    printf("Employee with highest salary is \n");
    printf("Name        : ");
    printf("%s\n",temp.name);
    printf("Employee id : ");
    printf("%s\n",temp.empid);
    printf("Salary      : ");
    printf("%d\n",temp.salary);
    printf("\n");

    fclose(f1);
    return EXIT_SUCCESS;
}
