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
int Delete(struct Array *Arr, int ind){
    int x = Arr->A[ind];
    if (ind >= 0 && ind < Arr -> length) {
        int i;
        for(i = ind; i < Arr -> length - 1; i++){
            Arr -> A[i] = Arr -> A[i+1];
        }
        Arr->length--;
        return x;
    }
    return 0;
}

int main(){
    struct Array arr={{2,3,4,5,6},10,5};
    printf("%d\n",Delete(&arr,3));
    Display(arr);
}