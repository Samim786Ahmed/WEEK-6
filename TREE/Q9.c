#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node { int data; struct Node *left, *right; };

struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data; n->left = n->right = NULL; return n;
}

int height(struct Node* root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + (lh > rh ? lh : rh);
}

bool isBalanced(struct Node* root) {
    if (!root) return true;
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);

    printf("Is balanced? %s\n", isBalanced(root) ? "Yes" : "No");
    return 0;
}