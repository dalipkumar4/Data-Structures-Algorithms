#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * next;
}node;

node* insertAtFront(node *head,int val){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    
    if(head == NULL){
        newnode->next = newnode;
        return newnode;
    }

    node *temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    
    temp->next = newnode;
    newnode->next = head;
    head = newnode; // update head
    return head;
}
node* insertAtBack(node *head,int val){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    
    if(head == NULL){
        newnode->next = newnode;
        return newnode;
    }
    
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    
    temp->next = newnode;
    newnode->next = head;
    
    return head;
}

 

node *deleteAtFront(node *head){
    if(head == NULL){
        printf("LinkedList is empty");
        return NULL;
    }
    node *temp = head;

    // only one node exist
    if(temp->next == head)
    {
        free(temp);
        return NULL;
    }
    node* last = head;
    while(last->next != head)
        last = last->next;

    last->next = head->next;
    head = head->next;
    free(temp);

    return head;
}



node* deleteAtEnd(node *head){
    node* temp = head;
    if(head == NULL){
        printf("LinkedList is empty");
        return NULL;
    }

    if(head->next == head){
        free(head);
        return NULL;
    }
    
    while(temp->next->next != head){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = head;
    return head ;
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
    node *head = NULL; // start with empty list

    head = insertAtFront(head,10);
    head = insertAtFront(head,23);
    head = insertAtFront(head,43);
    head = insertAtBack(head ,334);

    head = deleteAtEnd(head);
    printList(head);
    

    return 0;
}
