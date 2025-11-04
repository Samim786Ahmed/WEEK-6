#include <stdio.h>
#define MAX 5
int cqueue[MAX];
int front = -1, rear = -1;
void enqueue(int val) {
    if ((rear + 1) % MAX == front)
        printf("Overflow! Circular Queue is full.\n");
    else {
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        cqueue[rear] = val;
        printf("Inserted %d\n", val);
    }
}
void dequeue() {
    if (front == -1)
        printf("Underflow! Circular Queue is empty.\n");
    else {
        printf("Deleted %d\n", cqueue[front]);
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
    }
}
void display() {
    if (front == -1)
        printf("Circular Queue is empty.\n");
    else {
        int i = front;
        printf("Circular Queue: ");
        while (1) {
            printf("%d ", cqueue[i]);
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}
int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    display();
    dequeue();
    enqueue(5);
    display();
    return 0;
}