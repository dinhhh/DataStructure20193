#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int data;
    struct _node *next;
} node;


node *init(int value){
    node *temp = (node *)malloc(sizeof(node));
    temp->data = value;
    temp->next = temp;
    return temp;
}

void josephus(int n, int m){
    // khoi tao DSLK tu 1 den n
    node *head= init(1);
    node *temp = head;
    int i;
    for(i = 2; i <= n; i++){
        temp->next = init(i);
        temp = temp->next;   
    }
    temp->next = head;
    // thuc hien thuat toan 
    node *p1 = head, *p2 = head;
    while (p1->next != p1)
    {   
        int count = 1;
        while (count != m)
        {
            p2 = p1;
            p1 = p1->next;
            count++;
        }
        p2->next = p1->next;
        free(p1);
        p1 = p2->next;
    }
    printf("Result: %d\n", p1->data);
}

int main(){
    josephus(10, 5);

    return 0;
}

