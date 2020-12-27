#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
}*Head;

void create(int A[], int n){
    int i;
    struct Node *t, *last;

    Head=(struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last=Head;

    for(i=1; i <n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last=t;
    }
}
//Iterative version
void Display(struct Node *h){
    do {
        printf("%d ",h->data);
        h=h->next;
    }while(h!=Head);
    printf("\n");
}
//Length function
int Length(struct Node *p){
    int len=0;
    do{
        len++;
        p=p->next;

    }while(p!=Head);
    return len;
}
//Insert function
void Insert(struct Node *p, int index, int x){
    struct Node *t;
    int i;

    //check for valid index
    if(index < 0 || index > Length(p))
        return;

    //Insert at head location
    if(index == 0){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        //check if Head is Null
        if(Head==NULL){
            Head=t;
            Head->next=Head;
        } //if Head is not Null
        else{
            t->next=Head;
            Head=t;
            while(p->next!=Head) p=p->next;
            p->next=t;
        }
    } 
    else //inserting at given position
    {
        for(i=0; i<index-1;i++){
            p=p->next;
        }
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next=p->next;
        p->next=t;
    }
    
}
int main() {
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    Insert(Head,2,6);
    Display(Head);
}

