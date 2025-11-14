
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;

struct node* rear = NULL;
struct node* front = NULL;

node* insertFront(int val){
    node* newNode = malloc(sizeof(node));
    newNode->data = val;
    newNode->next = front;
    newNode->prev = NULL;

    if(front == NULL){
        rear = newNode;
        front = newNode;
    }
    else
    {
        front -> prev = newNode;
        front = newNode;
    }

}
node* insertRear(int val){
    node* newNode = malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = rear;

    if(front == NULL){
        rear = newNode;
        front = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode; 
    }
}

node* deleteFront(){
    if(front == NULL){
        printf("Dequeue is empty!");
    }

    node* temp = front;
    if(front == rear){
        front = NULL;
        rear = NULL;
    }
    else{
        front = front->next;
        front->prev = NULL;
    }
    free(temp);
}

node* deleteRear(){
    if(front == NULL){
        printf("Dequeue is empty!");
    }

    node* temp = rear;
    if(front == rear){
        front = NULL;
        rear = NULL;
    }
    else{
        rear = rear->prev;
        rear->next = NULL;
    }
    free(temp);
}


void display(){
    if(front == NULL){
        printf("Deque is empty!");
    }
    node* temp = front;
    do{
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    while(temp != NULL);
    printf("NULL\n");
}

int main(){
    
    insertFront(5);
    insertFront(2);
    insertRear(9);
    insertRear(8);
    // deleteFront();
    // deleteFront();
    deleteRear();
    display();

    return 0;
}
