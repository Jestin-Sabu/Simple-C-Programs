//C program that implements a priority queue
#define SIZE 10
#include<stdio.h>

typedef struct queue{
  int data;
  int priority;
}queue_t;

queue_t q[SIZE];
int front = -1;
int rear = -1;

void InQueue(int data, int priority){     //function to insert data into queue
  int i;
  if(front == 0 && rear == SIZE-1){
    printf("   Queue already full\n");
    return;
  }
  if(front == -1){
    front = rear = 0;
    q[rear].data = data;
    q[rear].priority = priority;
  }
  /*else if(rear == SIZE-1){            //to shift the entire queue to the front, to recapture lost space
    for(i=front; i<=rear; i++){
      q[i-front] = q[i];
      rear = rear-front;
      front=0;
      for(i=rear; i>front; i--){
        if(priority > q[i].priority)
          q[i+1] = q[i];
        else
          break;
        q[i+1].data = data;
        q[i+1].priority = priority;
        rear++;
      }
    }
  }*/
  else{
    for(i = rear;i>=front;i--){
      if(priority>q[i].priority)
        q[i+1] = q[i];
      else
        break;
    }
    q[i+1].data = data;
    q[i+1].priority = priority;
    rear++;
  }
}

void print(){                               //function to dispaly queue
  printf("Contents\n");
  for(int i=front; i<=rear; i++)
    printf("   Data = %d\tPriority = %d\n", q[i].data, q[i].priority);
}

void DelQueue(){                            //function to delete an element from front
  if(front == -1){
    printf("   Empty Queue\n");
    return;
  }
  printf("   Deleted Element(data, priority) : %d, %d\n", q[front].data, q[front].priority);
  if(front == rear)
    front = rear = -1;
    else
      front++;
}

int main(void){
    int data, priority, ch, flag = 1;
    while(flag){
        printf("\nPriority Queue Operations\n\n");
        printf("1. Insert into Queue\n");
        printf("2. Delete from Queue\n");
        printf("3. View Queue\n");
        printf("4. Exit\n");
        printf("   Enter your choice : ");
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("   Enter the number of data : ");
                    scanf("%d", &ch);
                    printf("   Enter the data and priority\n");
                    for(int i = 0; i<ch; i++){
                      printf("   ");
                      scanf("%d %d", &data, &priority);
                      InQueue(data, priority);
                    }
                    print();
                    break;
            case 2: DelQueue();
                    print();
                    break;
            case 3:print();
                    break;
            case 4:flag = 0;
                    break;
            default: printf("   Wrong Choice !!!");
        }
    }
    return 0;
}
