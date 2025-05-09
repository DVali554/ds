#include <stdio.h>
#define SIZE 5

int cqueue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((rear + 1) % SIZE == front)
        printf("Circular Queue is Full\n");
    else {
        if (front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % SIZE;
        cqueue[rear] = value;
    }
}

void dequeue() {
    if (front == -1)
        printf("Circular Queue is Empty\n");
    else {
        printf("Dequeued: %d\n", cqueue[front]);
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) {
        printf("Circular Queue is Empty\n");
        return;
    }
    printf("Circular Queue: ");
    int i = front;
    while (1) {
        printf("%d ", cqueue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    dequeue();
    display();
    return 0;
}
