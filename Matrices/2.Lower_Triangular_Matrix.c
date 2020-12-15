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

// This is using column major formula
//Set function
void SetC(struct Matrix *m, int i, int j, int x){
    if(i >= j){
        m->A[m->n*(j-1) - (j-2)*(j-1)/2 + i - j] = x;
    }
}

//Get function
int GetC(struct Matrix m, int i, int j){
    if (i >= j){
        return m.A[m.n*(j-1) - (j-2)*(j-1)/2 + i - j];            
    }
    else 
        return 0;
}

//Display function 
void DisplayC(struct Matrix m){
    int i, j;
    for(i = 1; i <= m.n; i++) {
        for(j = 1; j <= m.n; j++){
            if(i >= j){
                printf("%d ", m.A[m.n*(j-1) - (j-2)*(j-1)/2 + i - j]);
            }
            else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}


int main(){
    //validation for row major
    struct Matrix m;
    int i, j, x;
    
    printf("Enter dimension:");
    scanf("%d", &m.n); 
    m.A = (int *)malloc(m.n * (m.n + 1)/2 * sizeof(int));

    printf("Enter all elements:");
    for(i = 1; i <= m.n; i++){
        for(j = 1; j <= m.n; j++){
            scanf("%d", &x);
            Set(&m, i, j, x);
        }
    }
    printf("\n\n");
    Display(m);

    printf("\n\n");
    //validation for column major
    struct Matrix b;

    printf("Enter dimension:");
    scanf("%d", &b.n); 
    b.A = (int *)malloc(b.n * (b.n + 1)/2 * sizeof(int));

    printf("Enter all elements:");
    for(i = 1; i <= b.n; i++){
        for(j = 1; j <= b.n; j++){
            scanf("%d", &x);
            SetC(&b, i, j, x);
        }
    }
    printf("\n\n");
     DisplayC(b);
}