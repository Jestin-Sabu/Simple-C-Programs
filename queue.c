//C program that implement a queue
#define SIZE 5
#include<stdio.h>

typedef struct Queue{                       //structure that stores queue, front and rear
    int A[SIZE];
    int front;
    int rear;
}queue_t;

void InQueue(queue_t *q){                     //insert an element into queue
    if(q->rear == SIZE - 1){
        printf("Queue already full");
    }
    else{
        if(q->rear == -1 && q->front == -1){
            q->front = 0;
        }
        int a;
        q->rear = q->rear + 1;
        printf("Enter the input : ");
        scanf("%d", &a);
        q->A[q->rear] = a;
    }
}

void print(queue_t q){                    //prints the elements in queue
    if(q.front == -1){
        printf("Queue is empty");
    }
    else{
        for(int i = q.front; i <= q.rear; i++){
            printf("%d ", q.A[i]);
        }
    }
}

int DelQueue(queue_t *q){               //delete an element from queue
    int a;
    if(q->front == -1){
        printf("Queue is Empty");
    }
    else{
        a = q->A[q->front];
        if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    }
        else{
        q->front = q->front + 1;
        }
    }
    return a;
}

int main(void){
    queue_t q;
    q.front = -1;
    q.rear = -1;
    int ch, flag = 1;
    while(flag){
        printf("\nQueue Operations\n\n");
        printf("1. Insert into Queue\n");
        printf("2. Delete from Queue\n");
        printf("3. View Queue\n");
        printf("4. Exit\n");
        printf("   Enter your choice : ");
        scanf("%d", &ch);
        switch(ch){
            case 1: InQueue(&q);
                    print(q);
                    break;
            case 2: ch = DelQueue(&q);
                    printf("Poped item : %d\n", ch);
                    print(q);
                    break;
            case 3:print(q);
                    break;
            case 4:flag = 0;
                    break;
            default: printf("Wrong Choice !!!");
        }
    }
    return 0;
}
