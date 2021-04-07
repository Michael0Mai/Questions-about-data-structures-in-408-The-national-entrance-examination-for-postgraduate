#include <stdio.h>
#include <stdlib.h>

int A[] = {3, 2, 5};
int count = 3;

int find_min_unshow(int A[], int count){
    int B[count+2];
    int i;
    for(i=0; i<=count; i++){
        B[i] = 0;
    }
    for(i=0; i<count; i++){
        if(abs(A[i])<=count){
            B[A[i]]++;
        }
    }
    for(i=1; i<count+2; i++){
        if(B[i]==0){
            return i;
        }
        else{
            return count+1;
        }
    }
}

void main(){
    int u = find_min_unshow(A, count);
    printf("%d", u);
}