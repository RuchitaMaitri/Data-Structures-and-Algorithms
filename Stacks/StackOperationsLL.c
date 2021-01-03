#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
}*top=NULL;

void push(int x){
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));

    if(t==NULL){
        printf("stack overflow!!\n");
    } else {
        t->next=top;
        t->data=x;
        top=t;
    }
}

int pop(){
    struct Node *t;
    int x=-1;
    if(top==NULL) return -1;
    else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

void Display(){
    struct Node *t;
    t=top;
    while(t!=NULL){
        printf("%d ", t->data);
        t=t->next;
    }
    printf("\n");
}
int stacktop()
{
    if (top==NULL) return -1;
    else return top->data;
}
int isEmpty(){
    return top==NULL;
}
int isFull(){
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    int r= t?0:1;
    free(t);
    return r;
}
int main(){
    push(10);
    push(20);
    push(30);
    Display();
    printf("%d \n", isEmpty());
    printf("%d \n", isFull());
    printf("%d \n", stacktop());
}