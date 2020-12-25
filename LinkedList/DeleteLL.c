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

int Delete(struct Node *p, int index){

    struct Node *q;
    int x = -1;
    int i;

    //check if index is valid
    if(index < 1 || index > Count(p))
        return -1;
    if(index == 1){
        q = first;
        x = first -> data;
        first = first -> next;
        free(q);
        return x;
    }
    else {

        for(i=0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}

int main(){
    int A[] = {10,20,30,40,50};
    create(A, 5);
    Display(first);
    // printf("\n");
    Delete(first, 1);
    Display(first);
}