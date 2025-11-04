#include <stdio.h>
#include <stdlib.h>
struct Node { int data; struct Node *left, *right; };
struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data; n->left = n->right = NULL; return n;
}
struct Queue {
    int front, rear, size;
    unsigned capacity;
    struct Node** array;
};
struct Queue* createQueue(unsigned capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->array = (struct Node**)malloc(q->capacity * sizeof(struct Node*));
    return q;
}
int isEmpty(struct Queue* q) { return (q->size == 0); }
void enqueue(struct Queue* q, struct Node* item) {
    if (q->size == q->capacity) return;
    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear] = item;
    q->size += 1;
}
struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct Node* item = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size -= 1;
    return item;
}
void levelOrder(struct Node* root) {
    if (!root) return;
    struct Queue* q = createQueue(100);
    enqueue(q, root);
    while (!isEmpty(q)) {
        struct Node* node = dequeue(q);
        printf("%d ", node->data);
        if (node->left) enqueue(q, node->left);
        if (node->right) enqueue(q, node->right);
    }
}
int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    printf("Level order: ");
    levelOrder(root);
    printf("\n");
    return 0;
}