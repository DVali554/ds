#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    struct Node* temp = front;
    printf("Dequeued: %d\n", front->data);
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}

void display() {
    struct Node* temp = front;
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(5);
    enqueue(15);
    display();
    dequeue();
    display();
    return 0;
}
