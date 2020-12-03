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

int Get(struct Array arr, int index){
    if(index >= 0 && index < arr.length){
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array *arr, int index, int x){
    if(index >= 0 && index < arr->length){
        arr->A[index] = x;
    }
}

int Max(struct Array arr){
    int max = arr.A[0];
    int i;
    for (i=1; i<arr.length; i++){
        if(arr.A[i]> max){
            max = arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr){
    int min = arr.A[0];
    int i;
    for (i=1; i<arr.length; i++){
        if(arr.A[i]< min){
            min = arr.A[i];
        }
    }
    return min;
}

int Sum(struct Array arr){
    int sum = 0;
    int i;
    for(i=0; i < arr.length; i++){
        sum = sum + arr.A[i];
    }
    return sum;
}

float Avg(struct Array arr){
    return Sum(arr)/ arr.length;
}

int main(){
    struct Array arr={{2,3,4,5,6,7},10,6};
    Display(arr);

    //Get
    printf("\n %d\n", Get(arr, 4));

    //Set
    Set(&arr, 0, 10);
    Display(arr);

    //Max
    printf("\n %d\n", Max(arr));

    //Min
    printf("%d\n", Min(arr));

    //Sum
    printf("%d\n", Sum(arr));

    //Avg
    printf("%f\n", Avg(arr));
}