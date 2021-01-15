#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node {
    int data;
    struct Node *next;
}*top=NULL;

void push(int x){
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

int pop(){
    struct Node *t;
    int x=-1;
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

int Eval(char * postfix){
    int i, x1, x2, r;
    for(i=0;postfix[i]!='\0';i++){
        if(isOperand(postfix[i])){
            push(postfix[i]-'0');
        } else {
            x2=pop();
            x1=pop();
            switch (postfix[i]){
                case '+': r=x1+x2; break;
                case '-': r=x1-x2; break;
                case '*': r=x1*x2; break;
                case '/': r=x1/x2; break;
            }
            push(r);
        }
    }
    return top->data;
}

int main(){
   char *postfix = "234*+82/-";
   printf("Result is %d", Eval(postfix));
}