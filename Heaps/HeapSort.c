#include<stdio.h>
#include<stdlib.h>
void Insert(int A[], int n){
    int temp=A[n];
    int i=n;
    while(i>1 && temp > A[i/2]){
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}

int Delete(int A[], int n){
    int i,j,x,temp,val;
    val=A[1];
    A[1]=A[n];
    A[n]=val;
    i=1;
    j=2*i;
    while(j<n-1){
        if(A[j+1]>A[j]){
            j=j+1;
        }
        if(A[i]<A[j]){
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=2*j;
        }
        else {
            break;
        }
    }
    return val;
}
int main(){
    int H[]={0,10,20,30,25,5,40,35};
    int i;
    for(i=2; i<=7; i++){
        Insert(H,i);
    }
    for(i=7; i>1; i--){
        Delete(H,i);
    }
    for(i=1; i<=7; i++){
        printf("%d ", H[i]);
    }
}