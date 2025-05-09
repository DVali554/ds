#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Iterative reverse
struct Node* reverseIterative(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Recursive reverse
struct Node* reverseRecursive(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;
    struct Node* rest = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

// Utility functions
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    printf("Original List: ");
    printList(head);

    head = reverseIterative(head);
    printf("Reversed Iteratively: ");
    printList(head);

    head = reverseRecursive(head);
    printf("Reversed Recursively: ");
    printList(head);

    return 0;
}
