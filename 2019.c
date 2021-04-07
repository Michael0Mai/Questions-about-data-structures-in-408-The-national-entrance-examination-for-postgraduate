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

LNode *find_mid(LNode *head){ //找到后半段，并断开前半段和后半段的链接
    LNode *p = head->next, *q = p;
    while(q->next){
        p = p->next;
        q = q->next;
        if(q->next){
            q = q->next;
        }
    }
    printf("%d\n ", p->data);
    q = p->next;
    p->next = NULL;
    return q;
}

LNode *reverse(LNode *pre){
    LNode *p = pre->next, *q = p->next; 
    pre->next = NULL;
    while(q){
        p->next = pre;
        pre = p;
        p = q;
        q = q->next;
        //printf("%d\n ", p->data);
    }
    p->next = pre;
    pre = p;
    while(pre){
        printf("%d\n ", pre->data);
        pre = pre->next;
    }
    return p;
}

void merge(LNode *head){
    LNode *mid, *t, *t1, *p = head->next, *p1 = p->next;
    mid = find_mid(head);
    t = reverse(mid);
    t1 = t->next;
    while(t1){
        p->next = t;
        t->next = p1;
        p = p1;
        t = t1;
        p1 = p1->next;
        t1 = t1->next;
    }
    p->next = t;
    if(p1){
        t->next = p1;
    }

}

int L[] = {2, 4, 8, 10, 16, 32, 64, 128, 256, 512, 1024};
void main(){
    LNode *L_head;
    int length = sizeof(L) / sizeof(int);
    L_head = build_list(L, length);
    merge(L_head);
    while(L_head->next){
        printf("%d ", L_head->next->data);
        L_head = L_head->next;
    }
     
}