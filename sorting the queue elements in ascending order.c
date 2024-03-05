//sorting the queue elements in ascending order
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
}

void sort(){
    int n=rear - front +1;
    int i, j, temp;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(queue[i]>queue[j]){
                temp=queue[i];
                queue[i]=queue[j];
                queue[j]=temp;
            }
        }
    }
}
void main(){
    enqueue(4);
    enqueue(2);
    enqueue(7);
    enqueue(5);
    enqueue(1);
    printf("\nbefore sorting:  ");
    display();
    sort();
    printf("\nafter sorting:  ");
    display();
    
}

