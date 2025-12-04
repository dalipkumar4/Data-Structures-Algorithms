#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void preOrderTraversal(struct node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);   // root
    preOrderTraversal(root->left);       // left
    preOrderTraversal(root->right);      // right
}
void inOrderTraversal(struct node* root) {
    if (root == NULL)
        return;

    inOrderTraversal(root->left);       // left
    printf("%d ", root->data);   // root
    inOrderTraversal(root->right);      // right
}
void postOrderTraversal(struct node* root) {
    if (root == NULL)
        return;

    postOrderTraversal(root->left);       // left
    postOrderTraversal(root->right);      // right
    printf("%d ", root->data);   // root
}

int main() {
    struct node* root = NULL;
    
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    
    printf("Preorder Traversal: ");
    preOrderTraversal(root);
    printf("\n");
    printf("Inorder Traversal: ");
    inOrderTraversal(root);
    printf("\n");
    printf("Postorder Traversal: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}
