#include <stdio.h>
#include <stdlib.h>

int A[5] = { 13, 15, 17, 18};
int B[5] = {2, 4,  8, 20};
int len = 4;

int find_mid(int A[], int B[], int len){
    int a = 0;
    int b = 0;
    for(int i=0; i<len-1; i++){
        if(A[a] > B[b]){
            b = b + 1;
        }
        else{
            a = a + 1;
        }
    }
    if(A[a] > B[b]){
        return B[b];
    }
    else{
        return A[a];
    }
}


void main(){
    int mid;
    mid = find_mid(A, B, len);
    printf("%d", mid);
}
