#include <stdio.h>
#include <stdlib.h>

int A[8] = {0, 5, 5, 3, 5, 1, 5, 7};
int len = 8;

void main(){
    int temp = -1;
    int count = 0;
    for(int i=0; i<len; i++){
        if(count == 0){
            temp = A[i];
            count++;
        }
        if(count > 0){
            if(temp == A[i]){
                count++;
            }
            else{
                count--;
            }
        }
    }
    count = 0;
    for(int k=0; k<len; k++){
        if(temp == A[k]){
            count++;
        }
    }
    if(count > len/2){
        printf("%d", temp);
    }
    else{
        printf("%d", -1);
    }
}