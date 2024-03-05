//reverse the string using stack
#include <stdio.h>
#define N 100
char stack[N];
int top=-1;
void push(char x){
   if(top==N-1){
       printf("overflow");
   }
   else{
       top++;
       stack[top]=x;
   }
}
void pop(){
    if(top==-1){
        printf("underflow");
    }
    else{
        printf("%c", stack[top]);
        top--;
    }
}
int main(){
    char string[N];
    printf("enter the string to be reversed: ");
    scanf("%s", string);
    int size = sizeof(string)/sizeof(string[0]);
    for(int i=0;i<size;i++){
        push(string[i]);
    }
    for(int i=0;i<size;i++){
        pop();
    }
}


