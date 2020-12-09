#include<stdio.h>
#include<stdlib.h>
int main(){

    //lower case to upper case
    char A[] = "welcome";
    int i;
    for(i=0; A[i] != '\0'; i++){
        A[i] = A[i] - 32;
    }
    printf("%s \n", A);     

    //upper case to lower case
     char B[] = "WELCOME";
    int j;
    for(j=0; B[j] != '\0'; j++){
        B[j] = B[j] + 32;
    }
    printf("%s \n", B);

    //toggle
    char C[] = "WeLcOme@";
    int l;
    for(l=0; C[l] != '\0'; l++){
        if (C[l] >= 65 && C[l] <= 90){
            C[l] = C[l] + 32;
        } else if (C[l] >= 97 && C[l] <= 122){
            C[l] = C[l] - 32;
        }
    }
    printf("%s \n", C);
    }
    