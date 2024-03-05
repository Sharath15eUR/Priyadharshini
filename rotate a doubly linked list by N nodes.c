//rotate a doubly linked list by N nodes
#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    struct node* prev;
    struct node* next;
};

struct node *head, *temp, *newnode;

void create(){
    int n, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter the data: ");
        scanf(" %c", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }
}

void display(){
    temp=head;
    while(temp!=NULL){
        printf("%c -> ", temp->data);
        temp= temp->next;
    }
    printf("NULL\n");
}

void rotate(){
    int n;
    printf("enter the number of positions to be rotated: ");
    scanf("%d", &n);
    if(n==0){
        return;
    }
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;
    head->prev=temp;
    int count=1;
    while(count<=n){
        head=head->next;
        temp=temp->next;
        count++;
    }
    temp->next=NULL;
    head->prev=NULL;
    printf("\nlinked list after rotation:  ");
    display();
}
int main(){
    create();
    printf("the created linked list: ");
    display();
    rotate();
}

