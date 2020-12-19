#include<stdio.h>
#include<stdlib.h>
struct Element 
{
    int i;
    int j;
    int x;
};

struct Sparse 
{
    int m;
    int n;
    int num;
    struct Element *ele;
};

//Create function
void Create(struct Sparse *s){
    printf("Enter dimension of matrix: ");
    scanf("%d%d", &s->m, &s->n);
    printf("Enter num of non-zero elements: ");
    scanf("%d", &s->num);

    printf("Enter elements");
    s->ele = (struct Element *)malloc(s->num * sizeof(struct Element));


    int i;
    for(i = 0; i < s->num; i++){
        scanf("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
    }
}

//Display function 
void Display(struct Sparse s){
   int i, j, k = 0;

   for(i=0; i<s.m; i++){
       for(j=0; j<s.n; j++){
           if(i==s.ele[k].i && j==s.ele[k].j){
               printf("%d ", s.ele[k].x);
               k++;
           } else {
               printf("0 ");
           }
       }
       printf("\n");
   }
}

int main(){
    struct Sparse s;
    Create(&s);
    Display(s);
}