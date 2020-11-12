//Program to implement stack operations using linked list

#include<stdio.h>
#include<malloc.h>

typedef struct stack{                               //structure that represent each node in the linked list
  struct stack* NEXT;
  int DATA;
}stack_t;

stack_t* createnode(){                                //function to create new node of the linked list
  stack_t* temp = malloc(sizeof(temp));
  temp->NEXT = NULL;
  return temp;
}

void push(stack_t* HEAD){                             //function to push data to the linked list
  int temp;
  printf("   Enter the integer data to insert : ");
  scanf("%d", &temp);
  stack_t* new = createnode();
  new->DATA = temp;
  new->NEXT = HEAD->NEXT;
  HEAD->NEXT = new;
}

void pop(stack_t* HEAD){                              //function to pop data out of the linked list
  stack_t* ptr = HEAD->NEXT;
  if(ptr == NULL){
    printf("   Empty stack, failed to pop\n");
    return;
  }
  printf("   Popped Item = %d\n", ptr->DATA);
  HEAD->NEXT = ptr->NEXT;
  free(ptr);
}

void print(stack_t* HEAD){                          //function to print data in the linked list
  stack_t* ptr = HEAD->NEXT;
  printf("   ");
  while(ptr != NULL){
    printf("%d ", ptr->DATA);
    ptr = ptr->NEXT;
  }
}

void freestack(stack_t* HEAD){                //function to free heap
  stack_t* temp;
  stack_t* ptr = HEAD->NEXT;
  free(HEAD);
  while(ptr != NULL){
    temp = ptr;
    ptr = ptr->NEXT;
    free(temp);
  }
}

int main(void){
  int flag = 1, ch;
  stack_t* HEAD = createnode();
  while(flag){
      printf("\nStack Operations");
      printf("\n^^^^^^^^^^^^^^^^\n");
      printf("1. Push into Stack\n");
      printf("2. Pop out of Stack\n");
      printf("3. View Stack\n");
      printf("4. Exit\n");
      printf("   Enter your choice : ");
      scanf("%d", &ch);
      switch(ch){
          case 1: push(HEAD);
                  print(HEAD);
                  break;
          case 2: pop(HEAD);
                  print(HEAD);
                  break;
          case 3: print(HEAD);
                  break;
          case 4: flag = 0;
                  freestack(HEAD);
                  break;
          default: printf("Wrong Choice !!!");
      }
    }
  return 0;
}
