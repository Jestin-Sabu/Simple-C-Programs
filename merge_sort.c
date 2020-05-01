/* Program to Sort two arrays and merge into a new array dynamically*/
#include <stdio.h>
#include<malloc.h>

int* assign(int *n)                     //Read value into a dynamic array and returns the array
{
    int i;
    printf("Enter the no. of elements: ");
    scanf("%d,",n);
    int *p = malloc((*n)*sizeof(int));
    printf("Enter the elements : ");
    for(i=0;i<*n;i++)
        scanf("%d",p+i);
    return p;
}

void swap(int *a, int *b)            //function to swap the values two variables
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *p, int n)                 //quick sort function (ascending order)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(*(p+i)<*(p+j))
                swap(p+i, p+j);
        }
    }
}

int* merge(int *A, int *B, int a, int b)      //merge two arrays in the ascending order
{
    int n=0,i=0,j=0;
    int *p = malloc((a+b)*sizeof(int));
    while(i<a && j<b)
    {
        if(*(A+i) < *(B+j))
            *(p+n) = *(A+i++);
        else
            *(p+n)= *(B+j++);
        n++;
    }
    while(i<a)
        *(p+n++) = *(A+i++);
    while(j<b)
        *(p+n++) = *(B+j++);
    return p;
}

int main(void)            //main function
{
    int *A = NULL, *B = NULL, *merge_sorted = NULL;
    int a, b, c, i;
    printf("First Array\n");
    A = assign(&a);
    printf("Second Array\n");
    B = assign(&b);
    sort(A, a);
    sort(B, b);
    merge_sorted = merge( A, B, a, b);
    c = a+b;
    printf("Merge Sorted Array : ");
    for(i=0;i<c;i++)
        printf("%d ", *(merge_sorted+i));
    return 0;
}
