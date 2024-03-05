//insert or delete and count the number of elements in a queue
#include <stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x){
    if(rear==N-1){
        printf("overflow\n");
    }
    else if((front==-1)&&(rear==-1)){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}

void dequeue(){
    if((front==-1)&&(rear==-1)){
        printf("\nunderflow");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        front++;
    }
}

void display(){
    if((front==-1)&&(rear==-1)){
        printf("\nqueue is empty");
    }
    else{
        for(int i=front;i<rear+1;i++){
            printf("%d  ", queue[i]);
        }
    }
    printf("\n");
}

void count(){
    int countVar=0;
    if((front==-1)&&(rear==-1)){
        countVar=0;
    }
    else{
        for(int i=front;i<=rear;i++){
            countVar++;
        }
    }
    printf("no. of elements in the queue: %d\n", countVar);
}
void main(){
    printf("initialize a queue!\n");
    count();
    printf("insert some elements into the queue: \n");
    enqueue(1);
    enqueue(2);
    enqueue(3);
    printf("the queue elements are: \n");
    display();
    printf("delete two elements from the said queue: \n");
    dequeue();
    dequeue();
    printf("the queue elements are: \n");
    display();
    count();
    printf("insert another element into the queue: \n");
    enqueue(4);
    printf("the queue elements are: \n");
    display();
    count();
}

