#include<stdio.h>
#include<stdlib.h>


struct Array {
    int *A;
    int size;
    int length;
};

int main(){
    struct Array arr;
    printf("Enter the size of array:");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(sizeof(int) * arr.size);
    arr.length = 0;
}
