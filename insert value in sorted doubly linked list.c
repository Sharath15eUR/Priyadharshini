//insert value in sorted doubly linked list
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node *head, *temp, *newnode;

void create(){
    int n, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("enter the elements in a sorted way: ");
    for(i=0;i<n;i++){
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter the data: ");
        scanf("%d", &newnode->data);
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

void insert_at_pos(){
    int x;
    printf("enter the element to be inserted: ");
    scanf("%d", &x);
    struct node* new_insert = (struct node *)malloc(sizeof(struct node));
    new_insert->data=x;
    new_insert->prev=NULL;
    new_insert->next=NULL;
    temp=head;
    while(temp != NULL) {
        if(x < temp->data) {
            new_insert->next = temp;
            if(temp->prev != NULL) {
                temp->prev->next = new_insert;
                new_insert->prev = temp->prev;
            } else {
                head = new_insert;
            }
            temp->prev = new_insert;
            break;
        } else if(temp->next == NULL) {
            temp->next = new_insert;
            new_insert->prev = temp;
            break;
        }
        temp = temp->next;
    }
}

void display(){
    temp=head;
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp= temp->next;
    }
    printf("NULL\n");
}

int main(){
    create();
    printf("the created linked list: ");
    display();
    insert_at_pos();
    display();
}

