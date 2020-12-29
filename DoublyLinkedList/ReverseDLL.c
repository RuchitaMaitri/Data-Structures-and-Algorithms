#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n){
    int i;
    struct Node *t, *last;

    first=(struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    first->prev = NULL;
    last=first;

    for(i=1;i<n;i++){
        t= (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}
void Display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}
int Length(struct Node *p){
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}
void Reverse(struct Node *p){
    struct Node *temp;
    while(p!=NULL){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL) {
            first=p;
    }    
    }
}
int main(){
    int A[] = {10,20,30,40,50};
    create(A,5);
    Reverse(first);
    Display(first);
}