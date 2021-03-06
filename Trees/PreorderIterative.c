#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Stack{
    int size;
    int top;
    struct Node **S;
};

void createStack(struct Stack *st, int size){
    st->size=size;
    st->top=-1;
    st->S=(struct Node **)malloc(st->size * sizeof(struct Node *));
}

void push(struct Stack *st, struct Node * x){
    if(st->top == st->size -1)
        printf("Stack Overflow!!\n");
    else {
        st->top++;
        st->S[st->top]=x;
    }
}
struct Node * pop(struct Stack *st){
    struct Node * x = NULL;
    if(st->top == -1)
        printf("Stack underflow!!\n");
    else {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int isEmptyStack(struct Stack st){
    return st.top== -1;
}

struct Queue {
    int size;
    int front;
    int rear;
    struct Node  **Q;
};

void create(struct Queue *q, int size){
    q->size=size;
    q->front=q->rear=0;
    q->Q=(struct Node **)malloc(q->size*sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *x){
    if((q->rear+1) % q->size == q->front){
        printf("Queue is full");
    }
    else {
            q->rear=(q->rear + 1) % q->size;
            q->Q[q->rear]=x;
        }
}
struct Node * dequeue(struct Queue *q){
    struct Node * x=NULL;
    if(q->front==q->rear){
        printf("Queue is empty");
    }else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q){
    return q.front==q.rear;
}
struct Node *root=NULL;

void createTree(){
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q,100);

    root=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter root value");
    scanf("%d", &x);
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q, root);

    while(!isEmpty(q)){

        p=dequeue(&q);

        printf("Enter left child of %d", p->data);
        scanf("%d", &x);
        if(x!=-1){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("Enter right child of %d", p->data);
        scanf("%d", &x);
        if(x!=-1){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }

    }

}

void preorder(struct Node *p){
    if(p){
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node *p){
    if(p){ 
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

void postorder(struct Node *p){
    if(p){ 
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}

void preorderIt(struct Node *p){
    struct Stack st;
    createStack(&st, 100);
    while(p!=NULL || !isEmptyStack(st)){
        if(p!=NULL){
            printf("%d ", p->data);
            push(&st, p);
            p=p->lchild;
        }
        else{
            p = pop(&st);
            p = p->rchild;
        }
    }
}

void ineorderIt(struct Node *p){
    struct Stack st;
    createStack(&st,100);
    while(p!=NULL || !isEmptyStack(st)){
        if(p!=NULL){
            push(&st, p);
            p=p->lchild;
        }
        else{
            p = pop(&st);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

void levelOrder(struct Node *p){
    struct Queue q;
    create(&q,100);

    printf("%d ", p->data);
    enqueue(&q, p);

    while(!isEmpty(q)){
        p = dequeue(&q);
        if(p->lchild){
            printf("%d ", p->lchild->data);
            enqueue(&q, p->lchild);
        }
        if(p->rchild){
            printf("%d ", p->rchild->data);
            enqueue(&q, p->rchild);
        }
    }
}

int main(){

    createTree();
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);

    printf("\n");
    preorderIt(root);
    printf("\n");
    postorder(root);
    printf("\n");
    levelOrder(root);
}