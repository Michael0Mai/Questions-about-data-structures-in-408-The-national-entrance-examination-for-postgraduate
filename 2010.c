#include <stdio.h>
#include <stdlib.h>

int R[10] = {1, 2, 3, 4, 5, 6, 9, 8, 9, 10};
int P = 5;

void c_left(int R[], int len, int P){
    int temp;
    int k;
    temp = R[0];
    for(int i=0; i<P; i++){
        k = i;
        temp = R[i];
        while(k < len){
            if(k+P < len) R[k] = R[k+P];
            k = k + P;
        }
        R[k-P] = temp;
    }
}

void main(){
    for(int i=0; i<10; i++)
        printf("%d\n", R[i]);
    c_left(R, 10, P);
    for(int i=0; i<10; i++)
        printf("%d\n", R[i]);
}