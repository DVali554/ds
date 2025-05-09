#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
};

struct Deque* createDeque() {
    struct Deque* dq = (struct Deque*) malloc(sizeof(struct Deque));
    dq->front = dq->rear = NULL;
    return dq;
}

void insertFront(struct Deque* dq, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (dq->front == NULL)
        dq->rear = newNode;
    else
        dq->front->prev = newNode;

    dq->front = newNode;
}

void insertRear(struct Deque* dq, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (dq->rear == NULL)
        dq->front = newNode;
    else
        dq->rear->next = newNode;

    dq->rear = newNode;
}

void deleteFront(struct Deque* dq) {
    if (dq->front == NULL) {
        printf("Deque is empty\n");
        return;
    }

    struct Node* temp = dq->front;
    dq->front = dq->front->next;

    if (dq->front)
        dq->front->prev = NULL;
    else
        dq->rear = NULL;

    free(temp);
}

void deleteRear(struct Deque* dq) {
    if (dq->rear == NULL) {
        printf("Deque is empty\n");
        return;
    }

    struct Node* temp = dq->rear;
    dq->rear = dq->rear->prev;

    if (dq->rear)
        dq->rear->next = NULL;
    else
        dq->front = NULL;

    free(temp);
}

void display(struct Deque* dq) {
    struct Node* temp = dq->front;
    printf("Deque: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Deque* dq = createDeque();

    insertRear(dq, 10);
    insertRear(dq, 20);
    insertFront(dq, 5);
    display(dq);

    deleteRear(dq);
    display(dq);

    deleteFront(dq);
    display(dq);

    return 0;
}
