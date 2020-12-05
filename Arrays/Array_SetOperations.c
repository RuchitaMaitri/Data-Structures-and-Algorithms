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
// set operations on Un-sorted arrays A and B
// Union of sets A and B
struct Array * Union(struct Array *arr1, struct Array *arr2){
    int i,j,k,l;
    j = 0;
    k = 0; 
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    for(i = 0; i < arr1->length; i++){
        arr3->A[k] = arr1->A[i];
        k++;
    }
    int m = k;
    while (j < arr2->length) {
       l = 0;       
        while(l < m){
        if(arr2->A[j] == arr3->A[l]){
            j++;
            break;
        }
            l++;
    }
        arr3->A[k] = arr2->A[j];
        k++;
        j++;
    }
    arr3->length = k;
    arr3-> size = 10;
    return arr3;
}

//Intersection of sets A and B
struct Array * Intersection(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i = 0;
    k = 0; 
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while (i < arr1->length) {   
        j = 0;   
        while(j < arr2->length){
        if(arr1->A[i] != arr2->A[j]){
            j++;
        } else {
            arr3->A[k] = arr2->A[j];
            k++;
            break;
        }
    }
        i++;        
    }
    arr3->length = k;
    arr3-> size = 10;
    return arr3;
}

//Difference
struct Array * Difference(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i = 0;
    k = 0; 
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while (i < arr1->length) {   
        j = 0;   
        while(j < arr2->length){
        if(arr1->A[i] == arr2->A[j]){
            i++;
        }
        j++;
    }
        arr3->A[k] = arr1->A[i];
        i++;       
        k++; 
    }
    arr3->length = k;
    arr3-> size = 10;
    return arr3;
}


// set operations on sorted arrays A and B
//Union of two sets
struct Array * UnionSort(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i = 0;
    j = 0;
    k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i < arr1->length && j < arr2->length) {
        if(arr1->A[i] < arr2->A[j]){
            arr3->A[k] = arr1->A[i];
            k ++;
            i ++;
        } else if(arr1->A[i] > arr2->A[j]){
            arr3->A[k] = arr2->A[j];
            k ++;
            j ++;
        } else {
            arr3->A[k] = arr2->A[i];
            k ++;
            i ++;
            j ++;
        }
    }

    for (; i < arr1->length; i++){
        arr3->A[k] = arr1->A[i];
        k++;
    }
    for (; j < arr2->length; j++){
        arr3->A[k] = arr2->A[j];
        k ++;
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}
//Intersection of two sets
struct Array * IntersectionSort(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i = 0;
    j = 0;
    k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i < arr1->length && j < arr2->length) {
        if(arr1->A[i] < arr2->A[j]){
            i ++;
        } else if(arr1->A[i] > arr2->A[j]){
            j ++;
        } else {
            arr3->A[k] = arr2->A[i];
            k ++;
            i ++;
            j ++;
        }
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

//Difference between two sets A-B
struct Array * DifferenceSort(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i = 0;
    j = 0;
    k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i < arr1->length && j < arr2->length) {
        if(arr1->A[i] < arr2->A[j]){
            arr3->A[k] = arr1->A[i];
            k ++;
            i ++;
        } else if(arr1->A[i] > arr2->A[j]){
            j ++;
        } else {
            i ++;
            j ++;
        }
    }
    for (; i < arr1->length; i++){
        arr3->A[k] = arr1->A[i];
        k++;
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

int main(){
    struct Array arr1={{3,6,10,15,25},10,5};
    struct Array arr2={{1,6,7,18,20},10,5};
    struct Array *arr3;
    arr3 = Difference(&arr1, &arr2);
    Display(*arr3);
}