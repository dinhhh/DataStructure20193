#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _StackNode{
    char value;
    struct _StackNode *next;
}node;

typedef struct _Stack{
    node *top;
}stack;

stack *constructor();
stack *push(stack *s, char value);
void pop(stack *s);
void algorithm(char infix[]);

int main(){
    algorithm("as++--fas124213da-++");
}

int isOperand(char input){
    if((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
        return 1;
    return 0;
}

int getPreceOperator(char operator){
    // return precedence of operator
    // + - => return 1
    // * / => return 2
    // ^   => return 3
    switch (operator)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

void algorithm(char infix[]){
    stack *s = constructor();
    int len = strlen(infix);
    int i;
    char output[len];
    for(i = 0; i < len; i++){
        if(isOperand(infix[i])){
            printf("%c", infix[i]);
        }
        else{
            ///////////////////////////////////////////////////////////////////////////////////////////////////
        }
    }
}

stack *constructor(){
    stack *s = (stack *)malloc(sizeof(stack));
    if(s == NULL){
        printf("Out of memory!!!\n");
        return NULL;
    }
    else{
        s->top = NULL;
        return s;
    }
}

stack *push(stack *s, char value){
    node *p = (node *)malloc(sizeof(node));
    if(p == NULL){
        printf("Out of memory!!!\n");
    }
    else{
        p->value = value;
        p->next = s->top;
        s->top = p;
    }
    return s;
}

void popAndPrint(stack *s){
    if(s->top == NULL){
        printf("Stack is empty!!!\n");
    }
    else{
        printf("%c", s->top->value);
        node *temp = s->top;
        s->top = temp->next;    
        free(temp);
    }
}

