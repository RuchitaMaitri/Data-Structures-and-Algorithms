#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
}*first=NULL, *second=NULL, *third=NULL;

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

void create2(int A[], int n){
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node)); 
    second -> data = A[0];
    second -> next = NULL;
    last = second;

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

// Concatenate
void Concatenate(struct Node *p, struct Node *q){

    third = p;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
}

void Merge(struct Node *p, struct Node *q){
    struct Node *last;
    if(p->data < q->data){
        third=last=p;
        p=p->next;
        third->next=NULL;
    }else{
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q){
        if(p->data < q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p) last->next=p;
    if(q) last->next=q;
}

int main(){
    int A[] = {3,5,7,12,15};
    int B[] = {10,20,30,40,50};
    create(A, 5);
    create2(B, 5);
    printf("First\n");
    Display(first);
    printf("\n\n");
    printf("Second\n");
    Display(second);
    printf("\n\n");

    Merge(first,second);
    Display(third);

}