#include <stdio.h>
#include <stdlib.h>

// <--- DOUBLY LINKED LIST --->

typedef struct Node {
    int data;
    struct Node *next, *previous;
} node;

node *insertionAtFront(node *head, int val) {
    node *newNode = (node*)malloc(sizeof(node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }

    newNode->data = val;
    newNode->previous = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->previous = newNode;
    }

    head = newNode;
    return head;
}

node *insertionAtEnd(node *head, int val) {
    node *newNode = (node*)malloc(sizeof(node));

    if (newNode == NULL) {
        printf("Memory Allocation failed!\n");
        return head;
    }

    newNode->data = val;
    newNode->next = NULL;
    newNode->previous = NULL;

    if (head == NULL) {
        return newNode;
    }

    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->previous = temp;

    return head;
}

node *insertionAtPosition(node *head, int val, int loc) {
    node *newNode = malloc(sizeof(node));

    if (newNode == NULL) {
        printf("Memory Allocation failed!");
        return head;
    }

    newNode->data = val;
    newNode->next = NULL;
    newNode->previous = NULL;

    if (head == NULL) {
        if (loc != 1) {
            printf("Invalid position! Node not inserted.\n");
            free(newNode);
            return head;
        }
        return newNode;
    }

    if (loc == 1) {
        newNode->next = head;
        head->previous = newNode;
        return newNode;
    }

    node *temp = head;
    for (int i = 1; i < loc - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid location! Node not inserted!\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    newNode->previous = temp;

    if (temp->next != NULL)
        temp->next->previous = newNode;

    temp->next = newNode;

    return head;
}

node *deleteAtFront(node *head) {
    if (head == NULL) {
        printf("LinkedList is empty\n");
        return NULL;
    }

    node *temp = head;

    if (head->next == NULL) {
        free(temp);
        return NULL;
    }

    head = head->next;
    head->previous = NULL;

    free(temp);
    return head;
}

node *deleteAtEnd(node *head) {
    if (head == NULL) {
        printf("LinkedList is empty\n");
        return NULL;
    }

    node *temp = head;

    if (temp->next == NULL) {
        free(temp);
        return NULL;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->previous->next = NULL;
    free(temp);

    return head;
}

node *deleteAtPosition(node *head, int loc) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    node *temp = head;

    if (loc == 1) {
        head = head->next;
        if (head != NULL)
            head->previous = NULL;
        free(temp);
        return head;
    }

    for (int i = 1; i < loc && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position! Node not deleted.\n");
        return head;
    }

    if (temp->previous != NULL)
        temp->previous->next = temp->next;

    if (temp->next != NULL)
        temp->next->previous = temp->previous;

    free(temp);
    return head;
}

int main() {
    node *head = NULL;

    head = insertionAtFront(head, 24);
    head = insertionAtFront(head, 44);
    head = insertionAtEnd(head, 93);
    head = insertionAtPosition(head, 54, 3);

    head = insertionAtPosition(head, 43, 3);
    // head = deleteAtFront(head);
    // head = deleteAtEnd(head);
    head = deleteAtPosition(head, 3);

    node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

