#include <stdio.h>
#define SIZE 5

void insertFront(int dequeue[], int value, int *rear, int *front)
{
    if ((*front) == 0 && (*rear) == SIZE - 1 || (*front) == (*rear) + 1)
    {
        printf("Dequeue is full\n");
    }
    else
    {
        if ((*rear) == -1 && (*front) == -1) // dq is empty or not?
        {
            (*front) = 0, (*rear) = 0;
        }
        else
        {
            *front = (*front - 1 + SIZE) % SIZE;
        }
        dequeue[(*front)] = value;
    }
}

void insertRear(int dequeue[], int value, int *rear, int *front)
{
    if ((*front) == 0 && (*rear) == SIZE - 1 || (*front) == ((*rear) + 1) % SIZE) 
    {
        printf("Dequeue is Full!\n");
    }
    else
    {
        if ((*rear) == -1)
        {
            (*front) = 0, (*rear) = 0;
            dequeue[(*rear)] = value;
        }
        else
        {
            (*rear)++;
            dequeue[(*rear)] = value;
        }
    }
}

void deleteRear(int dequeue[], int *rear, int *front)
{
    if ((*rear) == -1 && (*front) == -1) // dq is empty or not?
    {
        printf("dequeue is empty!");
    }
    else if ((*rear == *front)) // when dq has only one element
    {
        (*rear) = -1;
        (*front) = -1;
    }

    else
    {
        (*rear) = (*rear - 1 + SIZE) % SIZE; //circular moving backward
    }
}

void deleteFront(int dequeue[], int *rear, int *front)
{
    if ((*rear) == -1 && (*front) == -1) // dq is empty or not?
    {
        printf("dequeue is empty!");
    }

    else if ((*rear == *front)) // when dq has only one element
    {
        (*rear) = -1; 
        (*front) = -1;
    }

    else
    {
        (*front) = ((*front) + 1) % SIZE; // circular moving forward                                                
    }
}

void display(int dequeue[], int rear, int front)
{

    if (rear == -1 && rear == -1) // dq is empty or not?
    {
        printf("dequeue is empty");
    }
    else
    {
        int i = front;
        while (1)
        {
            printf("%d,", dequeue[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE; // index should not overflow
        }
        printf("\n");

    }
}

int size(int dequeue[], int rear, int front)
{
    int size = 1;
    if (front == -1 && rear == -1)
    {
        printf("dequeue is empty");
    }
    else
    {
        int i = front;
        while (1)
        {
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
            size++;
        }
    }
    return size;
}

int main()
{
    int dequeue[SIZE];
    int front = -1;
    int rear = -1;

    insertRear(dequeue, 2, &rear, &front);
    insertFront(dequeue, 5, &rear, &front);
    insertFront(dequeue, 9, &rear, &front);
    insertRear(dequeue, 8, &rear, &front);
    insertRear(dequeue, 6, &rear, &front);
    insertRear(dequeue, 6, &rear, &front);

    // deleteFront(dequeue, &rear, &front); 
    // deleteRear(dequeue, &rear, &front);

    // dedequeue(dequeue,&rear,&front);
    display(dequeue, rear, front);

    printf("Size of Dequeue: %d",size(dequeue,rear,front));

    return 0;
}
