#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define MaxSize 100

/*========================首先搞定树节点的结构=======================*/
typedef struct BiTreeNode{
    int data;
    struct BiTreeNode *left, *right;
} BiTree;

/*========================层级的结构=======================*/
typedef struct level{
    int deep;
    BiTree *addr;
    struct level *next; 
}level;

/*=============================可以搞树的函数了========================*/
/*用来建立树的函数*/
void add(BiTree *node, BiTree *current_node){/*递归地将一个节点加入树中*/
    if(node->data < current_node->data){
        if(current_node->left)
            add(node, current_node->left);
        else{
            current_node->left = node;
        }
            
    }
    else{
        if(current_node->right)
            add(node, current_node->right);
        else{    
            current_node->right = node;
        }
    }
}  

BiTree *build(int n[]){
    //int len = sizeof(n) / sizeof(int);
    int len = 16;
    BiTree *T, *temp;
    T = (BiTree *)malloc(sizeof(BiTree));
    T->data = n[0];
    T->left = NULL;
    T->right = NULL;
    for(int i=1;i<len;i++){
        BiTree *temp = (BiTree *)malloc(sizeof(BiTree));
        temp->data = n[i];
        temp->left = NULL;
        temp->right = NULL;
        add(temp, T);
    }
    return T;
}

int count_leaf_weight(BiTree *root){
    int sum = 0, deep = 1;
    level *h, *t, *temp;
    h = (level*)malloc(sizeof(level));
    t = (level*)malloc(sizeof(level));
    h->addr = root;
    h->deep = deep;
    h->next = t;
    while(h != t){
        if(h->addr->left){
            t->addr = h->addr->left;
            t->deep = h->deep + 1;
            temp = (level*)malloc(sizeof(level));
            t->next = temp;
            t = t->next;
        }
        if(h->addr->right){
            t->addr = h->addr->right;
            t->deep = h->deep + 1;
            temp = (level*)malloc(sizeof(level));
            t->next = temp;
            t = t->next;
        }
        if(h->addr->left==NULL && h->addr->right==NULL){
            sum = sum + h->addr->data * h->deep;
        }
        h = h->next;
    }
    return sum;
}



/*准备好数据*/
int elem[] = {252, 229, 924, 391, 375, 858, 909, 808, 585, 170, 772, 3, 458, 235, 818, 919};

/*===================正式开始============================*/
int main()
{
    int sum;
    BiTree *root = build(elem);
    sum = count_leaf_weight(root);
    printf("%d\n", sum);


}

