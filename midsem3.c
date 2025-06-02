#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node {
    struct Node* nptr; // XOR of previous and next node
    int data;
} Node;

// XOR utility function
Node* XOR(Node* a, Node* b) {
    return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

// Insert at the beginning
void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->nptr = *head; // XOR of NULL and next node

    if (*head != NULL) {
        (*head)->nptr = XOR(newNode, (*head)->nptr);
    }

    *head = newNode;
}

// Print list forward
void printList(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next;

    while (curr != NULL) {
        printf("%d -> ", curr->data);
        next = XOR(prev, curr->nptr);
        prev = curr;
        curr = next;
    }
    printf("NULL\n");
}

// Free memory
void freeList(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next;

    while (curr != NULL) {
        next = XOR(prev, curr->nptr);
        free(curr);
        prev = curr;
        curr = next;
    }
}

int main() {
    Node* head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    
    printList(head);
    freeList(head);
    
    return 0;
}
