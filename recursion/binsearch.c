#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

void insert(struct node **root, int data);
void preOrder(struct node *root);
void inOrder(struct node *root);
void postOrder(struct node *root);
int size(struct node *root);
int height(struct node *root);
int sumOfWeight(struct node *root);
int maxPathWeight(struct node *root);
void mirror(struct node **root);
void destruct(struct node **root);

int main(void) {
    int t;
    scanf("%d", &t);

    while (t--) {
        int num;
        struct node *root = NULL;
        scanf("%d", &num);
        for(int i = 0; i < num; i++) {
            int data;

            scanf("%d", &data);
            insert(&root, data);
        }
        printf("%d\n", size(root));
        printf("%d\n", height(root));
        printf("%d\n", sumOfWeight(root));
        printf("%d\n", maxPathWeight(root));
        mirror(&root);
        preOrder(root);
        printf("\n");
        inOrder(root);
        printf("\n");
        postOrder(root);
        printf("\n");
        destruct(&root);
        if (root == NULL)
            printf("0\n");
        else
            printf("1\n");
    }

    return 0;
}

void insert(struct node **root, int data) {
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->left = new->right = NULL;
    new->data = data;
    
    if (*root == NULL) {
        *root = new;
        return;
    } else {
        if (data < (*root)->data)
            insert(&((*root)->left), data);
        else
            insert(&((*root)->right), data);
    }
}

void preOrder(struct node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct node *root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(struct node *root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int size(struct node *root) {
    if (root == NULL) return 0;
    else if (root->left == NULL && root->right == NULL) return 1;
    else return 1 + size(root->left) + size(root->right);
}

int height(struct node *root) {
    if (root == NULL) return 0;
    else if (root->left == NULL && root->right == NULL) return 0;

    int a = height(root->left);
    int b = height(root->right);
    return (a > b ? a : b) + 1;
}

int sumOfWeight(struct node *root) {
    if (root == NULL) return 0;
    else if (root->left == NULL && root->right == NULL) return root->data;
    else return root->data + sumOfWeight(root->left) + sumOfWeight(root->right);
}

int maxPathWeight(struct node *root) {
    if (root == NULL) return 0;
    else if (root->left == NULL && root->right == NULL) return root->data;
    
    int a = maxPathWeight(root->left);
    int b = maxPathWeight(root->right);
    return root->data + (a > b ? a : b);
}

void mirror(struct node **root) {
    if (*root == NULL) return;
    else if ((*root)->left == NULL && (*root)->right == NULL) return;

    struct node *temp;
    temp = (*root)->left;
    (*root)->left = (*root)->right;
    (*root)->right = temp;

    mirror(&((*root)->left));
    mirror(&((*root)->right));

    return;
}

void destruct(struct node **root) {
    if (*root == NULL) return;
    
    destruct(&((*root)->left));
    destruct(&((*root)->right));
    free(*root);
    *root = NULL;
    
    return;
}
