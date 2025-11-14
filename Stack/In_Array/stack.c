#include <stdio.h>
#define SIZE 5

int pop(int stack[], int *top)
{
    if ((*top) >= 0)
    {
        int value = stack[*top];
        (*top)--;
        return value;
    }
    else
    {
        printf("Stack empty!\n");
        return -1;
    }
}

int size(int *top)
{
    return (*top) + 1;
}

void push(int stack[], int value, int *top)
{
    if ((*top) < SIZE - 1)
    {
        (*top)++;
        stack[*top] = value;
    }
    else
    {
        printf("Stack overflow!");
    }
}

int isEmpty(int *top)
{
    return (*top) == -1;
}

int peek(int stack[], int *top)
{
    if ((*top) == -1)
    {
        printf("Stack is empty!");
        return -1;
    }
    else
    {
        return stack[*top];
    }
}

void display(int stack[],int* top){
    for(int i = *top;i>=0;i--){
        printf("%d , ",stack[i]);
    }
}

int main()
{

    int stack[SIZE];
    int top = -1;

    push(stack, 7, &top);
    push(stack, 4, &top);
    push(stack, 9, &top);
    push(stack, 8, &top);
    pop(stack,&top);

    size(&top);
    printf("Top: %d\n",peek(stack,&top));
    display(stack,&top);
    return 0;
}
