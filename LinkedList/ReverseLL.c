#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n){
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node)); 
    first -> data = A[0];
    first -> next = NULL;
    last = first;

    for(i=1; i < n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t; 
    }
}

//Iterative
void Display(struct Node *p){
    while(p!= NULL){
        printf("%d ", p-> data);
        p = p->next;
    }
    printf("\n");
}

//Finding length of linked list - Iterative
int Count(struct Node *p){
    int l = 0;
    while(p != NULL){
        l++;
        p = p->next;
    }
    return l;
}

//Reversing an element
void Reverse1(struct Node *p){
    struct Node* q=p;
    int i;

    int *A;
    A = (int *)malloc(sizeof(int)*Count(first));

    while(q!=NULL){
        A[i] = q->data;
        i++;
        q=q->next;
    }
    q=p;
    i--;
    while(q!=NULL){
        q->data=A[i];
        i--;
        q=q->next;
    }
}
//Reversing links using loop
void Reverse2(struct Node *p){
    struct Node *q=NULL, *r=NULL;

    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

//Reversing links using rescursion
void Reverse3(struct Node *q, struct Node *p){
    if(p){
        Reverse3(p, p->next);
        p->next = q;
    }
    else{
        first=q;
    }
}
int main(){
    int A[] = {3,5,7,2,2,2,15,15,15};
    create(A, 9);
    Display(first);
    Reverse3(NULL, first);
    Display(first);
}