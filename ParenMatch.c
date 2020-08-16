// paratheses matching
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _StackNode{
    char value;
    struct _StackNode *next;
}node;

typedef struct _Stack{
    node *top;
}stack;

int isMatchingPair(char x, char y);
void areParenthesesIsBalance(char input[]);
stack *constructor();
stack *push(stack *s, char value);
void pop(stack *s);
void printStack(stack *s);

int main(){
    char input[] = "[()]{}{[()()]()}";
    areParenthesesIsBalance(input);
    
}

int isMatchingPair(char x, char y){
    // return 1 if x == y
    if(x == '{' && y == '}')
        return 1;
    else if(x == '[' && y == ']')
        return 1;
    else if(x == '(' && y == ')')
        return 1;
    else
        return 0;
}
void areParenthesesIsBalance(char input[]){
    stack *s = constructor();
    int i = 0;
    while (input[i]){
        if(input[i] == '(' || input[i] == '[' || input[i] == '{')
            s = push(s, input[i]);
        else if(input[i] == ')' || input[i] == ']' || input[i] == '}'){
            if(s->top == NULL)
                printf("Not balance!!!\n");
            else if(isMatchingPair(s->top->value, input[i]))
                pop(s);
        }
        i++;
    }
    if(s->top == NULL)
        printf("Balance!!!\n");
    else
        printf("Not balance!!!\n");
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

void pop(stack *s){
    if(s->top == NULL){
        printf("Stack is empty!!!\n");
    }
    else{
        char value = s->top->value;
        node *temp = s->top;
        s->top = temp->next;
        free(temp);
    }
}

void printStack(stack *s){
    if(s->top == NULL){
        printf("Stack is empty!!!\n");
    }
    else{
        node *temp = s->top;        
        while(temp != NULL){
            printf("%c\t", temp->value);
            temp = temp->next;
        }
        printf("End here!!!\n");
    }
}