#include <stdio.h>
#include <stdlib.h>

int elem[] = {252, 229, 924, 391, 375, 858, 909, 808, 585, 170, 771, 3, 458, 235, 818, 919};
int len = sizeof(elem) / sizeof(int);

int sepera(int elem[], int len){
    int temp, i=0, k, p=0, q=len, key;
    while(i != len/2-1){
        i = p;
        k = p + 1;
        key = elem[p];
        while(k<q){
            if(elem[k]<key){
                temp = elem[k];
                elem[k] = elem[i+1];
                elem[i+1] = temp;
                i++;
            }
            k++;
        }
        elem[p] = elem[i];
        elem[i] = key;
        if(i < len/2-1){
            p = i + 1;
        }
        if(i > len/2-1){
            q = i;
        }
    }
    if(len%2 == 0){
        return i;
    }
    else{
        return i+1;
    }
    
    
}

void main(){
    int mid = sepera(elem, len);
    for(int i=0; i<len; i++){
        printf("%d\n", elem[i]);
    }
    printf("%d\n", mid);
}