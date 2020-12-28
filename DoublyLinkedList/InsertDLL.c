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
void Insert(struct Node *p, int index, int x){
    struct Node *t;
    int i;
    if(index < 0 || index > Length(p))
        return;

    if(index == 0){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }else {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        
        for(i=0;i<index-1;i++){
            p=p->next;
        }
        t->next=p->next;
        t->prev=p;
        p->next=t;
        if(p->next!=NULL) p->next->prev=t;
    }
}
    

int main(){
    int A[] = {10,20,13,15,16};
    create(A,5);
    Insert(first,0,25);
    Display(first);
}