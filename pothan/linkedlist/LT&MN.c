#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void traverseAndManipulate(struct Node* head) {
    int count = 0, sum = 0;
    while (head != NULL) {
        count++;
        sum += head->data;
        head = head->next;
    }
    printf("Node Count: %d, Sum: %d\n", count, sum);
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 5);
    insertEnd(&head, 15);
    insertEnd(&head, 25);
    insertEnd(&head, 35);

    traverseAndManipulate(head);
    return 0;
}
