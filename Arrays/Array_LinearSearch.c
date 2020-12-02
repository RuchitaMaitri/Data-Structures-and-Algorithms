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
}
int LinearSearch(struct Array *arr, int key){
    int i;
    for(i = 0; i < arr->length; i++){
        if(arr->A[i] == key){
            return i;
        }
    }
    return -1;
}
void swap(int *m, int *n){
    int temp;
    temp = *m;
    *m = *n;
    *n = temp;
}
int LinearSearch_Transposition(struct Array *arr, int key){
    int i;
    for(i = 0; i < arr->length; i++){
        if(arr->A[i]==key){
            swap(&arr->A[i], &arr->A[i-1]);
            return i;        
        }
    }
    return -1;
}
int LinearSearch_MoveToHead(struct Array *arr, int key){
    int i;
    for(i = 0; i < arr->length; i++){
        if(arr->A[i]==key){
            swap(&arr->A[i], &arr->A[0]);
            return i;        
        }
    }
    return -1;
}

int main(){
    struct Array arr={{2,3,4,5,6},10,5};
    // printf("%d\n",LinearSearch(&arr,6));
    // printf("%d\n",LinearSearch_Transposition(&arr,6));
    printf("%d\n",LinearSearch_MoveToHead(&arr,6));
    Display(arr);
}