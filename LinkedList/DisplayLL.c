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
//Recursive
void RDisplay(struct Node *p){
    if(p!=NULL){
        printf("%d ", p->data);
        RDisplay(p->next);
    }
    printf("\n");
}
//Print in reverse - Recursive
void RDisplayRecursive(struct Node *p){
    if(p!=NULL){
        RDisplayRecursive(p->next);
        printf("%d ", p->data);
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
//finding length of linked list - Recursive version
int CountR(struct Node *p){
    if(p != NULL){ 
        return Count(p->next) + 1;
    } else {
        return 0;
    }
}
//finding sum of linked list - Iterative
int Sum(struct Node *p){
    int s = 0;
    while(p != NULL){
        s = s + p->data;
        p = p->next;
    }
    return s;
}

//finding sum of linked list - Recursive version
int SumR(struct Node *p){
    if(p != NULL){ 
        return SumR(p->next) + p->data;
    } else {
        return 0;
    }
}

//Max of all elements of linked list - Iterative
int Max(struct Node *p){
    int max = -2147483648;
    while(p != NULL){
        if(p->data > max){
            max = p->data;
            }
        p = p->next;
    }
    return max;
}
//Max of all elements of linked list - Recursive
int MaxR(struct Node *p){
    int max = -2147483648;
    if (p==0)
        return -2147483648;

    max = MaxR(p->next);
    if (max > p->data){
        return max;
    } else {
        return p->data;
    } 
}

int main(){
    int A[] = {3,5,7,10,15,8,12,20};
    create(A, 8);
    // Display(first);
    // RDisplay(first);
    // RDisplayRecursive(first);
    // printf("length is %d \n", CountR(first));
    // printf("Sum is %d \n", SumR(first));

    printf("Max is %d", MaxR(first));
}