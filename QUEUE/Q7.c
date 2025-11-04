#include <stdio.h>
#define MAX 3
int queue[MAX];
int front = -1, rear = -1;
void enqueue(int val) {
    if (rear == MAX - 1)
        printf("Overflow condition! Queue is full.\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = val;
        printf("Inserted %d\n", val);
    }
}
void dequeue() {
    if (front == -1 || front > rear)
        printf("Underflow condition! Queue is empty.\n");
    else
        printf("Deleted %d\n", queue[front++]);
}
int main() {
    dequeue();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4); // Overflow
    dequeue();
    dequeue();
    dequeue();
    dequeue();  // Underflow
    return 0;
}