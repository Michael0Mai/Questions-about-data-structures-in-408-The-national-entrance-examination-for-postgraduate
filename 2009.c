#include <stdio.h>
#include <stdlib.h>

int R[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int k = 6;

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode;

LNode *build(int R[], int lenR){
    LNode *temp, *head, *p;
    head = (LNode*)malloc(sizeof(LNode));
    p = head;
    for(int i=0; i<lenR; i++){
        temp = (LNode*)malloc(sizeof(LNode));
        temp->data = R[i];
        temp->next = NULL;
        p->next = temp;
        p = temp;
    }
    return head;
}

int list_k(){
    int lenR = 10;
    if(k>lenR){
        return 0;
    }
    LNode *head = build(R, lenR);
    LNode *p = head, *q = head;
    for(int i=0; i<k-1; i++){
        q = q->next;
    }
    while(q->next){
        p = p->next;
        q= q->next;
    }
    return p->data;
}
 void main(){
    int i;
    i = list_k();
    printf("%d", i);
 }