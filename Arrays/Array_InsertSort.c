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

void InsertSort(struct Array *arr, int x){
    if(arr->length == arr->size){
        return;
    } 
    int i = arr->length - 1;
    while(i >= 0 && arr->A[i] > x){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length ++;
}

int IsSorted(struct Array arr){
    int i;
    for(i=0; i<arr.length -1; i++){
        if(arr.A[i] > arr.A[i+1]){
            return 0;
        }
    }
    return 1;
}

void NegativeOnLeft(struct Array *arr){
    int i, j;
    i = 0;
    j = arr->length - 1;
    while(i < j){
        while(arr->A[i] < 0) { i++;}
        while(arr->A[j] > 0) { j--;}        
        if(i < j){
            swap(&arr->A[i], &arr->A[j]);
        }
    }
}

int main(){
    struct Array arr={{2,3,4,5,6},10,5};
    Display(arr);

    InsertSort(&arr, 1);
    Display(arr);

    printf("%d", IsSorted(arr));

    struct Array arr2 = {{-1,2,-3,4,-9,8,-7,6,-2},10,9};
    NegativeOnLeft(&arr2);
    Display(arr2);
}