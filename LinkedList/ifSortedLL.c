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

int isSorted(struct Node *p){
    int x = -2147483648;
    while(p!=NULL){
        if(p-> data < x){
            return 0;
        }
        x = p->data;
        p=p->next;
    }
    return 1;
}

void RemoveDuplicates(struct Node* p){
    struct Node *q=first->next;
    while(q!=NULL){
        if(p->data != q->data){
            p=q;
            q=q->next;
        } 
        else{
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

int main(){
    int A[] = {3,5,7,2,2,2,15,15,15};
    create(A, 7);
    RemoveDuplicates(first);
    Display(first);
}



