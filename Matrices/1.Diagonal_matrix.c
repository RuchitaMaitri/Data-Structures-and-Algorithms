#include<stdio.h>
#include<stdlib.h>
struct Matrix
{
    int A[10]; // to store diagonal elements
    int n; //length of diagonal
};

//Set function
void Set(struct Matrix *m, int i, int j, int x){
    if(i == j){
        m->A[i-1] = x;
    }
}

//Get function
int Get(struct Matrix m, int i, int j){
    if (i == j){
        return m.A[i-1];            
    }
    else 
        return 0;
}

//Display function 

void Display(struct Matrix m){
    int i, j;
    for(i = 0; i < m.n; i++) {
        for(j = 0; j < m.n; j++){
            if(i == j){
                printf("%d ", m.A[i]);
            }
            else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main(){
    struct Matrix m;
    m.n = 4;

    Set(&m, 1, 1, 3);
    Set(&m, 2, 2, 4);
    Set(&m, 3, 3, 5);
    Set(&m, 4, 4, 6);

    Display(m);
    printf("%d ", Get(m, 2, 2));
    
}