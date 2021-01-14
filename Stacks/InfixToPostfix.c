#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
int pre(char x){
    if(x=='+'||x=='-')
        return 1;
    else if(x=='*'||x=='/')
        return 2;
    return 0;
}

int isOperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/')
        return 0;
    else 
        return 1;
}
int isEmpty(){
    return top==NULL;
}

char *IntoPost(char *infix){
    int i=0, j=0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len+1)*sizeof(char));

    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++]=infix[i++];
        } 
        else {
            if(pre(infix[i]) > pre(top->data))
                push(infix[i++]);
            else postfix[j++]=pop();
        } 
    }
    while(!isEmpty()){
        postfix[j++]=pop();
    }
    postfix[j++]='\0';
    return postfix;
}


int main(){
   char *infix = "a+b*c-d/e";
   push('#');
   char *postfix=IntoPost(infix);
   printf("%s ", postfix);
}