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

int BinarySearch_Iterative(struct Array arr, int key){
    int l, h, mid;
    l = 0;
    h = arr.length - 1;

    while(l <= h){
        mid = (l + h)/ 2;
        if(key == arr.A[mid]){
            return mid;
        } else if (key < arr.A[mid]){
            h = mid - 1;
        } else {
            l = mid + 1;
        } 
    }
    return -1;
}
int BinarySearch_Recursive(int arr[], int l, int h, int key){
    int mid;
    if(l <= h){
        mid = (l + h)/ 2;
        if(key == arr[mid]){
            return mid;
        } else if (key < arr[mid]){
            return BinarySearch_Recursive(arr, l, mid - 1, key);
        } else {
            return BinarySearch_Recursive(arr, mid + 1, h, key);
        } 
    }
    return -1;
}

int main(){
    struct Array arr={{2,3,4,5,6},10,5};
    printf("%d\n" , BinarySearch_Iterative(arr, 4));
    printf("%d\n" , BinarySearch_Recursive(arr.A,0,arr.length - 1, 4));
    Display(arr);
}