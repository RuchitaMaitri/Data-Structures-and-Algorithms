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
void Insert(struct Array *Arr, int ind, int x){
    if ( Arr -> length < Arr -> size && ind >= 0 && ind < Arr -> length) {
        int i;
        for(i = Arr -> length; i > ind; i--){
            Arr -> A[i] = Arr -> A[i-1];
        }
        Arr->A[ind] = x;
        Arr->length++;
    }
}

int main(){
    struct Array arr={{1,2,3,4,5,6,7,8,9},10,9};
    Insert(&arr,8,10);
    Display(arr);
}