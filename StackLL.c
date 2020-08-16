#include <stdio.h>
#include <stdlib.h>

typedef struct _StackNode 
{
    int data;
    struct _StackNode *next;
} node;

typedef struct _Stack
{
    node *top;
} stack;

stack *constructor()
{
    stack *p = (stack *)malloc(sizeof(stack));
    if(p == NULL)
    {
        printf("Out of memory!!!\n");
        return NULL;
    }
    else
    {
        p->top = NULL;
        return p;
    }
}

stack *push(stack *s, int value){
    node *temp = (node *)malloc(sizeof(node));
    temp->data = value;
    temp->next = s->top;
    s->top = temp;
    return s;
}

int pop(stack *s){
    int value = s->top->data;
    node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    return value;
}

void printStack(stack *s){
    if (s->top == NULL)
    {
        printf("Stack is empty!!!\n");
    }
    else
    {
        printf("My stack: ");
        node *temp = s->top;
        do
        {
            printf("%5d", temp->data);
            temp = temp->next;
        } while (temp != NULL);
        printf("\tEnd here!!!\n");
    }
}

int main(){
    stack *s = constructor();
    s = push(s, 5);
    s = push(s, 10);
    s = push(s, 15);
    printStack(s);
    int x = pop(s);
    printf("\nFirst pop: %d\n", x);
    printStack(s);
    int y = pop(s);
    printf("\nSecond pop: %d\n", y);
    printStack(s);
    return 0;
}

