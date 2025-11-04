#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node *front = NULL, *rear = NULL;
void enqueue(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (rear == NULL)
        front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Inserted %d\n", val);
}
void dequeue() {
    if (front == NULL)
        printf("Underflow! Queue is empty.\n");
    else {
        struct Node* temp = front;
        printf("Deleted %d\n", front->data);
        front = front->next;
        free(temp);
        if (front == NULL) rear = NULL;
    }
}
void display() {
    if (front == NULL)
        printf("Queue is empty.\n");
    else {
        struct Node* temp = front;
        printf("Queue elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main() {
    enqueue(5);
    enqueue(15);
    enqueue(25);
    display();
    dequeue();
    display();
    return 0;
}