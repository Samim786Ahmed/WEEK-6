#include <stdio.h>
#define MAX 5
int deque[MAX];
int front = -1, rear = -1;
void insertFront(int val) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        printf("Overflow! Deque is full.\n");
    else {
        if (front == -1)
            front = rear = 0;
        else if (front == 0)
            front = MAX - 1;
        else
            front--;
        deque[front] = val;
    }
}
void insertRear(int val) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        printf("Overflow! Deque is full.\n");
    else {
        if (front == -1)
            front = rear = 0;
        else if (rear == MAX - 1)
            rear = 0;
        else
            rear++;
        deque[rear] = val;
    }
}
void deleteFront() {
    if (front == -1)
        printf("Underflow! Deque is empty.\n");
    else {
        printf("Deleted %d\n", deque[front]);
        if (front == rear)
            front = rear = -1;
        else if (front == MAX - 1)
            front = 0;
        else
            front++;
    }
}
void deleteRear() {
    if (front == -1)
        printf("Underflow! Deque is empty.\n");
    else {
        printf("Deleted %d\n", deque[rear]);
        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = MAX - 1;
        else
            rear--;
    }
}
void display() {
    if (front == -1)
        printf("Deque is empty.\n");
    else {
        int i = front;
        printf("Deque elements: ");
        while (1) {
            printf("%d ", deque[i]);
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}
int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    display();
    deleteFront();
    deleteRear();
    display();
    return 0;
}