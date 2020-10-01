#include<stdio.h>

char* shifter(char a[], char b[], int i, int j){
    for(int k = i;a[k] != '\0'; k++){
        a[k] = a[k+j];
    }
    return a;
}

int main(void){
    int i,j=0,flag=1;
    char* c;
    char a[100], b[100];
    printf("Enter the main String : ");
    scanf("%s", a);
    printf("Enter the Sub-String : ");
    scanf("%s", b);
    int l;
    for(l = 0; b[l] != '\0';l++);               //finding the length fo string b
    for(i = 0; a[i] != '\0' && flag; i++){
        if(a[i] == b[j] && flag){               //checking the pattern
            if(j == l-1){
                flag = 0;
                c=shifter(a,b,i-j,j+1);         //deletes the string b from a, by shifting a forward fro the correct position
            }
            j++;
        }
        else
            j=0;
    }
    if(!flag)
        printf("%s",c);
    else
        printf("No modifications were made");
    
}
