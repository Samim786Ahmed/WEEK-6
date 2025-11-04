#include <stdio.h>
#define MAX 5
struct PQ {
    int data;
    int priority;
};
struct PQ pq[MAX];
int size = 0;
void enqueue(int d, int p) {
    if (size == MAX)
        printf("Overflow! Priority Queue full.\n");
    else {
        pq[size].data = d;
        pq[size].priority = p;
        size++;
    }
}
void dequeue() {
    if (size == 0)
        printf("Underflow! Priority Queue empty.\n");
    else {
        int highest = 0;
        for (int i = 1; i < size; i++) {
            if (pq[i].priority < pq[highest].priority)
                highest = i;
        }
        printf("Deleted %d with priority %d\n", pq[highest].data, pq[highest].priority);
        for (int i = highest; i < size - 1; i++)
            pq[i] = pq[i + 1];
        size--;
    }
}
void display() {
    if (size == 0)
        printf("Priority Queue is empty.\n");
    else {
        printf("Priority Queue elements:\n");
        for (int i = 0; i < size; i++)
            printf("Data: %d Priority: %d\n", pq[i].data, pq[i].priority);
    }
}
int main() {
    enqueue(10, 2);
    enqueue(20, 1);
    enqueue(30, 3);
    display();
    dequeue();
    display();
    return 0;
}