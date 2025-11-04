#include <stdio.h>
#include <stdlib.h>
struct Node { int data; struct Node *left, *right; };
struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data; n->left = n->right = NULL; return n;
}
struct Node* insert(struct Node* root, int key) {
    if (!root) return createNode(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}
int findMin(struct Node* root) {
    struct Node* cur = root;
    while (cur->left) cur = cur->left;
    return cur->data;
}
int findMax(struct Node* root) {
    struct Node* cur = root;
    while (cur->right) cur = cur->right;
    return cur->data;
}
int main() {
    struct Node* root = NULL;
    int keys[] = {50,30,20,40,70,60,80};
    for(int i=0;i<7;i++) root = insert(root, keys[i]);
    printf("Min = %d\n", findMin(root));
    printf("Max = %d\n", findMax(root));
    return 0;
}