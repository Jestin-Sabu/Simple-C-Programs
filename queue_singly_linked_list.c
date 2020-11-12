#include<stdio.h>
#include<malloc.h>

typedef struct queue{
  struct queue* NEXT;
  int DATA;
}queue_t;

queue_t* createnode(){
  queue_t* temp = malloc(sizeof(temp));
  temp->NEXT = NULL;
  return temp;
}

void InQueue(queue_t* HEAD){
  int temp;
  printf("   Enter the integer data to insert: ");
  scanf("%d", &temp);
  queue_t* new = createnode();
  new->DATA = temp;
  queue_t* ptr = HEAD;
  while(ptr->NEXT != NULL)
    ptr = ptr->NEXT;
  ptr->NEXT = new;
}

void DelQueue(queue_t* HEAD){
  queue_t* ptr = HEAD->NEXT;
  if(ptr == NULL){
    printf("   Empty Queue, failed to delete\n");
    return;
  }
  printf("   Deleted item = %d\n", ptr->DATA);
  HEAD->NEXT = ptr->NEXT;
  free(ptr);
}

void print(queue_t* HEAD){
  queue_t* ptr = HEAD->NEXT;
  while(ptr != NULL){
    printf("%d ", ptr->DATA);
    ptr = ptr->NEXT;
  }
  printf("\n");
}

void freequeue(queue_t* HEAD){
  queue_t* temp;
  queue_t* ptr = HEAD->NEXT;
  free(HEAD);
  while(ptr != NULL){
    temp = ptr;
    ptr = ptr->NEXT;
    free(temp);
  }
}

int main(void){
  queue_t* HEAD = createnode();
  int ch, flag = 1;
  while(flag){
      printf("\nQueue Operations");
      printf("\n^^^^^^^^^^^^^^^^\n");
      printf("1. Insert into Queue\n");
      printf("2. Delete from Queue\n");
      printf("3. View Queue\n");
      printf("4. Exit\n");
      printf("   Enter your choice : ");
      scanf("%d", &ch);
      switch(ch){
          case 1:InQueue(HEAD);
                 print(HEAD);
                 break;
          case 2:DelQueue(HEAD);
                 print(HEAD);
                 break;
          case 3:print(HEAD);
                 break;
          case 4:flag = 0;
                 freequeue(HEAD);
                 break;
          default: printf("Wrong Choice !!!");
      }
  }
  return 0;
}
