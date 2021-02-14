#include<stdio.h>
#include<stdlib.h>
void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void Bubble(int A[], int n){
    int i,j,flg;
    for(i=0;i<n-1;i++){
        flg=0;
        for(j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                swap(&A[j], &A[j+1]);
                flg=1;
            }
        }
        if(flg==0) break;
    }
}
void Insertion(int A[], int n){
    int i,j,x;
    
    for(i=1;i<n;i++){
        x=A[i];
        j=i-1;
        while(j>-1 && A[j]>x){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}
int main(){
    int A[]={3,7,9,10,6,5,12,4,11,2};
    int n=10;
    // Bubble(A,10);
    Insertion(A,10);
    int i;
    for(i=0;i<10;i++){
        printf("%d ", A[i]);
    }
}