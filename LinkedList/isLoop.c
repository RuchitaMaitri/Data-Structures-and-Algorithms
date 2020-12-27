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
int isLoop(struct Node *f){
    struct Node *p, *q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        q=q!=NULL?q->next:NULL;
    }while(p && q && p != q);
    if(p==q)
        return 1;
    else 
        return 0;
}
int main(){
    int A[] = {3,5,7,12,15};
    create(A, 5);

    //to make linked list into a loop
    struct Node *t1, *t2;

    t1= first->next->next;
    t2= first->next->next->next->next;
    t2->next=t1;

    printf("%d\n", isLoop(first));
    
}
