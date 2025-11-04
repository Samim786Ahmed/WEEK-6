#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;
void display() {
    if (front == -1 || front > rear)
        printf("Queue is empty.\n");
    else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}
void enqueue(int val) {
    if (rear == MAX - 1)
        printf("Overflow! Cannot enqueue.\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = val;
        printf("Enqueued %d\n", val);
    }
    display();
}
void dequeue() {
    if (front == -1 || front > rear)
        printf("Underflow! Cannot dequeue.\n");
    else
        printf("Dequeued %d\n", queue[front++]);
    display();
}
int main() {
    enqueue(5);
    enqueue(10);
    dequeue();
    enqueue(15);
    display();
    return 0;
}