#include<stdio.h>
#include<stdlib.h>
struct Node {
    char data;
    struct Node *next;
}*top=NULL;

void push(char x){
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));

    if(t==NULL){
        printf("stack overflow!!\n");
    } else {
        t->next=top;
        t->data=x;
        top=t;
    }
}

char pop(){
    struct Node *t;
    char x=-1;
    if(top==NULL) return -1;
    else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

void Display(){
    struct Node *t;
    t=top;
    while(t!=NULL){
        printf("%d ", t->data);
        t=t->next;
    }
    printf("\n");
}

int isBalance(char *exp){
    int i;
    for(i=0; exp[i]!='\0';i++){
        if(exp[i]=='(') push(exp[i]);
        else if(exp[i]==')'){
            if(top==NULL) return 0;
            pop();
        }
    }
    if(top==NULL) return 1;
    else return 0;
}

int main(){
   char *exp = "((a+b)*(c-d))";
   printf("%d ", isBalance(exp));
}