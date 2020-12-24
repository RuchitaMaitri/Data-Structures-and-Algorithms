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

//finding length of linked list - Iterative
int Count(struct Node *p){
    int l = 0;
    while(p != NULL){
        l++;
        p = p->next;
    }
    return l;
}

void Insert(struct Node *p, int index, int x){
    if(index < 0 || index > Count(p))
        return;
    
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t -> data = x;

    int i;
    if(index==0){
        t->next=first;
        first=t;
    } else{
        for(i=0; i < index-1; i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=p;
    }
}

int main(){
    int A[] = {3,5,7};
    create(A, 3);
   
    Insert(first,0,10);
    Display(first);
}