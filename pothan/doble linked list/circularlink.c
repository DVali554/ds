#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* tail = NULL;

void insertEnd(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;

    if (tail == NULL) {
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

void deleteFront() {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* head = tail->next;
    if (head == tail) {
        free(tail);
        tail = NULL;
    } else {
        tail->next = head->next;
        free(head);
    }
}

void traverse() {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = tail->next;
    printf("Circular List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("(head)\n");
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    traverse();

    deleteFront();
    traverse();

    return 0;
}
