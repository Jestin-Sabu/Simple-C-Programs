//C program that implement a stack
#define SIZE 5
#include<stdio.h>

typedef struct Stack{                     //structure that stores the stack and the top
    int A[SIZE];
    int top;
}stack_t;

void push(stack_t* s){                  //inserts an element to the stack
    int n;
    if(s->top == SIZE-1){
        printf("Stack already full !!!");
    }
    else{
        printf("Enter the input : ");
        scanf("%d", &n);
        s->top = s->top + 1;
        s->A[s->top] = n;
    }
}

void print(stack_t s){               //prints the elements in the stack
    if(s.top == -1){
        printf("Stack is Empty !!!");
    }
    else{
        printf("\n");
        for(int i = 0; i<=s.top; i++){
            printf("%d ", s.A[i]);
        }
    }
}

int pop(stack_t* s){               //deletes an element from the stack
    int a;
    if(s->top == -1){
        printf("Stack is Empty");
    }
    else{
        a = s->A[s->top];
        s->top = s->top - 1;
    }
    return a;
}

int main(void){
    stack_t s;
    s.top = -1;
    int ch, flag = 1;
    while(flag){
        printf("\nStack Operations\n\n");
        printf("1. Push into Stack\n");
        printf("2. Pop out of Stack\n");
        printf("3. View Stack\n");
        printf("4. Exit\n");
        printf("   Enter your choice : ");
        scanf("%d", &ch);
        switch(ch){
            case 1: push(&s);
                    print(s);
                    break;
            case 2: ch = pop(&s);
                    printf("Poped item : %d\n", ch);
                    print(s);
                    break;
            case 3:print(s);
                    break;
            case 4:flag = 0;
                    break;
            default: printf("Wrong Choice !!!");
        }
    }
    return 0;
}
