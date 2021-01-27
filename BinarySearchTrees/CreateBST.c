#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;

void Insert(int key){
    struct Node *p=root;
    struct Node *r=NULL, *t;

    if(root==NULL){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        root=t;
        return;
    }

    while(p!=NULL){
        r=p;
        if(key<p->data)
            p=p->lchild;
        else if(key>p->data)
            p=p->rchild;
        else return;
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data=key;
    t->lchild=t->rchild=NULL;

    if(r->data<key) r->rchild=t;
    else r->lchild=t;
}

void Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}
struct Node * Search(int key){
    struct Node *t=root;

    while(t!=NULL){
        if(key==t->data)
            return t;
        else if(key < t->data)
            t=t->lchild;
        else 
            t=t->rchild;
    }
    return NULL;
}

struct Node * RInsert(struct Node *p, int key){

    struct Node *t;
    if(p==NULL){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }

    if(key < p->data)
    {
        p->lchild=RInsert(p->lchild,key);
    } else if(key > p->data) {
        p->rchild=RInsert(p->rchild,key);
    }

    return p;
}

int Height(struct Node *p){
    if(p==NULL) return 0;

    int x,y;
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y?x+1:y+1;
}
struct Node * InPre(struct Node *p){
    if(p && p->rchild)
        p=p->rchild;
    return p;
}

struct Node * InSucc(struct Node *p){
    if(p && p->lchild)
        p=p->lchild;
    return p;
}

struct Node * Delete(struct Node *p, int key){
    struct Node *q;
    if(p==NULL) 
        return NULL;
    if(p->lchild==NULL && p->rchild==NULL){
        if(p==root)
            root=NULL;
        free(p);
        return NULL;
    }
    if(key < p->data)
        p->lchild=Delete(p->lchild,key);
    else if(key > p->data)
        p->rchild=Delete(p->rchild,key);
    else {
        if(Height(p->lchild)>Height(p->rchild)){
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        } else {
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}
int main(){
    struct Node *temp;
    root=RInsert(root,10);
    RInsert(root,5);
    RInsert(root,20);
    RInsert(root,8);
    RInsert(root,30);
    Delete(root,20);
    Inorder(root);
    printf("\n");

    temp = Search(20);
    if(temp!=NULL) printf("Element %d is found", temp->data);
    else printf("Element is not found");

    return 0;
}

