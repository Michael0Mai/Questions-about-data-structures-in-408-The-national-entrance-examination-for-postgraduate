typedef struct node{
    char data;
    struct node *left, *right;
}BiTree;

void out_tree(BiTree *root){
    BiTree *p = root;
    if(p!=root && p->left!=NULL && p->right!=NULL){
        printf("(");
        if(p->left){
            out_tree(P->left);
        }
        printf("%c", p->data);
        if(p->right){
            out_tree(p->right);
        }
        printf(")");
    }
    if(p==root || (p->left==NULL && p->right==NULL)){
        printf("%c", p->data);
    }
}