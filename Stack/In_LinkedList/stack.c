#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node* next;
}node;

struct node* top = NULL;

void push(int val){
    node* newNode = malloc(sizeof(node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}


void pop(){
    if(top == NULL){
        printf("Stack is Empty!");
    }
    node* temp = top;
    top = top->next;
    free(temp);
}


int peek(){
    if(top == NULL){
        printf("Stack is Empty!");
        return -1;
    }
    else{
        return top->data;
    }
}

void display(){
    node* temp = top;

    if(top == NULL){
        printf("Stack is Empty!");
    }
    else{
        while(temp != NULL){
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main(){
    push(3);
    push(6);
    push(9);
    display();
    // int t=peek();
    // if(t!=-1){
        //     printf("Top Element: %d",t);
        // }
    pop();
    display();

    return 0;
}
