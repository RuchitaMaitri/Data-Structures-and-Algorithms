#include<stdio.h>
#include<stdlib.h>

struct Array {
    int A[10];
    int size;
    int length;
};
void Display(struct Array Arr){
    int i;
    printf("Elements of array are: \n");
    for(i=0; i < Arr.length; i++){
        printf("%d ", Arr.A[i]);
    }
    printf("\n");
}
void swap(int *m, int *n){
    int temp;
    temp = *m;
    *m = *n;
    *n = temp;
}

void Reverse_1(struct Array *arr){
    int *B;
    int i,j;
    for(i=arr->length-1, j=0; i>=0;i--, j++){
        B[j] = arr->A[i];
    }
    for(i=0; i < arr->length; i++){
        arr->A[i] = B[i];
    }
}

void Reverse_2(struct Array *arr){
    int i, j;
    for(i=0, j=arr->length-1; i < j; i++, j--){
        swap(&arr->A[i], &arr->A[j]);
    }
}

int main(){
    struct Array arr={{2,3,4,5,6},10,5};
    Display(arr);

    Reverse_1(&arr);
    Display(arr);

    Reverse_2(&arr);
    Display(arr);
}