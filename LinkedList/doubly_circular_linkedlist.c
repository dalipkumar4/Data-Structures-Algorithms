#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;

node* insertAtFront(node* head,int val){
    node* newnode = malloc(sizeof(node));
    newnode->data=val;
    if(head == NULL){
        newnode->next = newnode;
        newnode->prev = newnode;
        return newnode;
    }
    newnode->next = head;
    newnode->prev = head->prev;

    head->prev->next = newnode;
    head->prev = newnode;
    head= newnode;
    return head;
}

node* insertAtBack(node*head,int val){
    node* newnode = malloc(sizeof(node));
    newnode->data=val;
    if(head == NULL){
        newnode->next = newnode;
        newnode->prev = newnode;
        return newnode;
    }
    newnode->next = head;
    newnode->prev = head->prev;
    head->prev->next = newnode;
    head->prev = newnode;
    return head;
}

node* deleteAtFront(node*head){
    if(head == NULL){
        printf("LinkedList is empty");
        return NULL;
    }

    if(head->next == head){
        free(head);
        return NULL;
    }

    node* temp = head;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    head = temp->next;

    free(temp);

    return head;
}
node* deleteAtBack(node*head){
    if(head == NULL){
        printf("LinkedList is empty");
        return NULL;
    }

    if(head->next == head){
        free(head);
        return NULL;
    }
    node* last = head->prev;
    node* secondLast = last->prev;

    secondLast->next = head;
    head->prev = secondLast;

    free(last);
    
    return head;
}

void printList(node *head){

    if(head == NULL){
        printf("List is empty");
        return;
    }
    node *temp = head;
    do{
        printf("%d -> ",temp->data);
        temp = temp->next;
    }while(temp!=head);
    printf("(Back to head)\n");
    
}


int main(){
    node* head = NULL;
    head = insertAtFront(head,5);
    head = insertAtFront(head,9);
    head = insertAtFront(head,4);
    head = insertAtBack(head,4);
    head = deleteAtBack(head);
    head = deleteAtFront(head);
    printList(head);


    return 0;
}
