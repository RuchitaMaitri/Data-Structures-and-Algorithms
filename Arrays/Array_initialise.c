#include<stdio.h>
#include<stdlib.h>


struct Array {
    int *A;
    int size;
    int length;
};
void Display(struct Array A){
    int i;
    printf("Elements of array are: \n");
    for(i=0; i < A.length; i++){
        printf("%d ", A.A[i]);
    }
}
int main(){
    struct Array arr;
    printf("Enter the size of array:\n");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(sizeof(int) * arr.size);
    arr.length = 0;

    int n;
    printf("Enter the number of numbers:\n");
    scanf("%d",&n);
    printf("Enter all elements: \n");

    int i;
    for(i = 0; i < n; i++){
        scanf("%d",&arr.A[i]);
    }
   arr.length = n;
   Display(arr);
}