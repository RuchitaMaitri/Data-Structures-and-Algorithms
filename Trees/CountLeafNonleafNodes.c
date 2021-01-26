#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

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
    if((q->rear+1)%q->size==q->front){
        printf("Queue is full");
    }
    else {
            q->rear=(q->rear+1)%q->size;
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

int countLeafNodes(struct Node *p){
    if(p==NULL) 
        return 0;
    if(!p->lchild && !p->rchild)
        return countLeafNodes(p->lchild) + countLeafNodes(p->rchild) + 1;
    return countLeafNodes(p->lchild) + countLeafNodes(p->rchild);
}

int countNonLeafNodes(struct Node *p){
    if(p==NULL) 
        return 0;
    if(p->lchild || p->rchild)
        return countNonLeafNodes(p->lchild) + countNonLeafNodes(p->rchild) + 1;
    return countNonLeafNodes(p->lchild) + countNonLeafNodes(p->rchild);
}

int countDegTwoNodes(struct Node *p){
    if(p==NULL) 
        return 0;
    if(p->lchild && p->rchild)
        return countDegTwoNodes(p->lchild) + countDegTwoNodes(p->rchild) + 1;
    return countDegTwoNodes(p->lchild) + countDegTwoNodes(p->rchild);
}

int countDegOneNodes(struct Node *p){
    if(p==NULL) 
        return 0;
    if(p->lchild != NULL ^ p->rchild !=NULL)
        return countDegOneNodes(p->lchild) + countDegOneNodes(p->rchild) + 1;
    return countDegOneNodes(p->lchild) + countDegOneNodes(p->rchild);
}


int main(){

    createTree();
    printf("count of leaf nodes = %d \n", countLeafNodes(root));
    printf("count of non leaf nodes = %d \n", countNonLeafNodes(root));   
    printf("count of degree 2 nodes = %d \n", countDegTwoNodes(root));
    printf("count of degree 1 nodes = %d \n", countDegOneNodes(root));
}