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
void Append(struct Array *Arr, int x){
    if ( Arr -> length < Arr -> size){
        Arr->A[Arr->length] = x;
        Arr->length++;
    }

}
int main(){
    struct Array arr={{2,3,4,5,6},10,5};
    Append(&arr,10);
    Display(arr);
}