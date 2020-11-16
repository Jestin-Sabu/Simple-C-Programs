//C program to implement circular queue using arrays
#define SIZE 10
#include<stdio.h>

int A[SIZE];
int front = -1;
int rear = -1;

void EnQeue(){                                   //function to insert an element into the queue
  int a;
  if((front == 0 && rear == SIZE-1) || (rear == (front-1)%(SIZE-1))){
    printf("   Queue if full\n");
    return;
  }
  printf("   Enter the input : ");
  scanf("%d", &a);
  if(front == -1){
    front=rear=0;
    A[rear] = a;
  }
  else if(rear == SIZE-1 && front !=0){
    rear = 0;
    A[rear] = a;
  }
  else{
    A[++rear] = a;
  }
}

void print(){                                 //function to print elements in the queue
  if(front == -1){
    printf("   Queue is Empty\n");
    return;
  }
  printf("   Elements :");
  if(rear >= front)
    for(int i = front; i <= rear; i++)
      printf(" %d", A[i]);
  else{
    for(int i = front; i < SIZE; i++)
      printf(" %d", A[i]);
    for(int i = 0;i <= rear; i++)
      printf(" %d", A[i]);
  }
}

void DelQueue(){                          //function to delete an element from queue
  if(front == -1){
    printf("   Queue is Empty\n");
    return;
  }
  int data = A[front];
  if(front == rear)
    front = rear = -1;
  else if(front == SIZE-1)
    front = 0;
  else
    front++;
  printf("   Deleted data : %d\n", data);
}

int main(void){
  int ch, flag = 1;
  while(flag){
    printf("\nCircular Queue\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. View\n");
    printf("4. Exit\n");
    printf("   Enter your choice : ");
    scanf("%d", &ch);
    switch (ch) {
      case 1: EnQeue();
              print();
              break;
      case 2: DelQueue();
              print();
              break;
      case 3: print();
              break;
      case 4: flag = 0;
              break;
      default : printf("   Wrong Choice\n");
    }
  }
  return 0;
}
