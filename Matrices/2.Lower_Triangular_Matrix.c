#include<stdio.h>
#include<stdlib.h>
struct Matrix
{
    int *A; // to store non zero elements
    int n; //dimension of matrix
};

// This is using row major formula
//Set function
void Set(struct Matrix *m, int i, int j, int x){
    if(i >= j){
        m->A[i*(i-1)/2 + j-1] = x;
    }
}

//Get function
int Get(struct Matrix m, int i, int j){
    if (i >= j){
        return m.A[i * (i-1)/2 + j - 1];            
    }
    else 
        return 0;
}

//Display function 
void Display(struct Matrix m){
    int i, j;
    for(i = 1; i <= m.n; i++) {
        for(j = 1; j <= m.n; j++){
            if(i >= j){
                printf("%d ", m.A[i * (i-1)/2 + j - 1]);
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
    int i, j, x;
    m.A = (int *)malloc(m.n * (m.n + 1)/2 * sizeof(int));

    printf("Enter dimension:");
    scanf("%d", &m.n); 

    printf("Enter all elements:");
    for(i = 1; i <= m.n; i++){
        for(j = 1; j <= m.n; j++){
            scanf("%d", &x);
            Set(&m, i, j, x);
        }
    }
    printf("\n\n");
     Display(m);
}