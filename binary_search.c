//program to search an element in an array using binary search algorithm
#include <stdio.h>
#include<malloc.h>

int main()
{
    int n,a;
    printf("Enter the array size : ");
    scanf("%d", &n);
    int *A = malloc(n*sizeof(*A));
    printf("Enter the elements\n");
    for(int i=0; i<n; i++)
        scanf("%d", &A[i]);
    printf("Enter the element to search : ");
    scanf("%d", &a);
    for(int i = 0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(A[j] < A[minIndex])
                minIndex = j;
            if(minIndex != i){
                int temp = A[i];
                A[i] = A[minIndex];
                A[minIndex] = temp;
            }
        }
    }
    int low = 0;
    int high = n;
    int flag = 0;
    int mid;
    while(low<high){
        mid = (low+high)/2;
        if(A[mid] == a){
            flag = 1;
            break;
        }
        else if(A[mid] < a)
            low = mid+1;
        else
            high = mid;
    }
    if(flag)
        printf("Element found at position %d.\n", mid+1);
    else
        printf("Element not found");
    free(A);
}
