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

//Seach function - Iterative

struct Node * LSearch(struct Node *p, int key){
    struct Node* q = NULL;

    while(p!= NULL){
        if(key == p->data){
            q->next = p->next;
            p->next=first;
            first=p;
            return p;
        }
        q = p;
        p = p -> next;
    }
    return NULL;
}

//Search function - Recursive
struct Node * RSearch(struct Node *p, int key){
    if(p == NULL){
        return NULL;
    }
    if(p->data == key){
        return p;
    }
    return RSearch(p->next, key);
}

int main(){
    int A[] = {3,5,7,10,15,8,12,20};
    create(A, 8);
    // Display(first);
    // RDisplay(first);
    // RDisplayRecursive(first);
    // printf("length is %d \n", CountR(first));
    // printf("Sum is %d \n", SumR(first));
    // printf("Max is %d", MaxR(first));
    struct Node* temp;
    temp= LSearch(first, 15);
    temp= LSearch(first, 20);
    if(temp){
        printf("Key is found %d\n", temp->data);
    }
    else {
        printf("No key found");
    }
    Display(first);
}