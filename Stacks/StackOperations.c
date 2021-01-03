#include<stdio.h>
#include<stdlib.h>
struct Stack{
    int size;
    int top;
    int *S;
};
void create(struct Stack *st){
    printf("Enter the size: ");
    scanf("%d", &st->size);
    st->top=-1;
    st->S=(int *)malloc(st->size * sizeof(int));
}
void Display(struct Stack st){
    int i;
    for(i=st.top; i>=0; i--){
        printf("%d ", st.S[i]);
    }
    printf("\n");
}
//Inserts an element at the top
void push(struct Stack *st, int x){
    if(st->top == st->size -1)
        printf("Stack Overflow!!\n");
    else {
        st->top++;
        st->S[st->top]=x;
    }
}
//Deletes an element at the top
int pop(struct Stack *st){
    int x = -1;
    if(st->top == -1)
        printf("Stack underflow!!\n");
    else {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}
//Returns an element at given index
int peek(struct Stack st, int index){
    int x = -1;
    if(st.top - index  + 1 < 0)
        printf("Invalid position");
    else {
        x = st.S[st.top-index+1];
    }
    return x;
}
//Returns an element at the top
int stackTop(struct Stack st){
    if(st.top==-1) return -1;
    else return st.S[st.top];
}
//Tells if stack is empty
int isEmpty(struct Stack st){
    return st.top== -1;
}
//Tells if stack is full
int isFull(struct Stack st){
    return st.top == st.size -1;
}
int main(){
    struct Stack s;
    create(&s);
    push(&s,10);
    // push(&s,20);
    // push(&s,30);
    // push(&s,40);
    // push(&s,50);
    Display(s);

    pop(&s);
    pop(&s);
    Display(s);
    push(&s,20);
    push(&s,30);
    Display(s);
    return 0;
}