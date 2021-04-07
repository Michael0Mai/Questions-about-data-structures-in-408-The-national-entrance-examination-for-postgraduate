#include <stdio.h>
#include <stdlib.h>


typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *Linklist;

LNode*build_list(int S[],int S_len){
    LNode *temp, *p, *head;
    head = (LNode*)malloc(sizeof(LNode));
    head->data = 0;
    for(int i=S_len-1; i>=0; i--){
        p = (LNode*)malloc(sizeof(LNode));
        p->data = S[i];
        if(i==S_len-1){
            p->next = NULL;
        }
        else{
            p->next = temp;
        }
        temp = p;
        }
    head->next = p;
    return head;
}

LNode *find_mid(LNode *head, int len){
    LNode *p = head->next, *q = p;
    while(q->next){
        p = p->next;
        q = q->next;
        if(q->next){
            q = q->next;
        }
    }
    printf("%d\n", p->data);
    q = p->next;
    p->next = NULL;
    return q;
}

LNode *reverse(LNode *p){
    if(p->next != NULL){
        reverse(p->next);
    }
    return p;
}
 void merge(LNode *head, int length){
    Lnode *q = head->next, *r = q->next, *mid, *p;
    mid = find_mid(head, length);
    
    while(p){

    }
}




int L[] = {2, 4, 8, 10, 16, 32, 64, 128, 256, 512, 1024};
void main(){
    LNode *L_head;
    int length = sizeof(L) / sizeof(int);
    L_head = build_list(L, length);
    //reverse(L_head, length);
    while(L_head->next){
        printf("%d ", L_head->next->data);
        L_head = L_head->next;
    }
     
}