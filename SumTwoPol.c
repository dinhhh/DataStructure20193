#include <stdlib.h>
#include <stdio.h>

typedef struct _node{
    int coeff; // co so
    int pow; // so mu
    struct _node *next;
} node;

node *createNode(int coeff, int pow){
    node *first = (node *)malloc(sizeof(node));
    first->coeff = coeff;
    first->pow = pow;
    first->next = NULL;
    return first;
}

node *createPol(){
    int answer;
    node *head = (node *)malloc(sizeof(node));
    printf("Enter first: coeff = ");
    scanf("%d", &head->coeff);
    printf("pow = ");
    scanf("%d", &head->pow);
    head->next = NULL;
    do
    {
        //temp == last node
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        //create new node
        node *newNode = (node *)malloc(sizeof(node));
        printf("Enter another: coeff = ");
        scanf("%d", &newNode->coeff);
        printf("pow = ");
        scanf("%d", &newNode->pow);
        newNode->next = NULL;
        temp->next = newNode;
        // add another?
        printf("continued? (yes = 1 / no = 0)  ");
        scanf("%d", &answer);
    } while (answer == 1);
    printf("Create successful!!!\n");
    return head;
}

void printList(node *head){
    node *temp = head;
    while (temp != NULL)
    {
        printf("Coeff = %d   ", temp->coeff);
        printf("Pow = %d\n", temp->pow);
        temp = temp->next;
    }
}

node *addToLast(node *head, int coeff, int pow){
    node *new = (node *)malloc(sizeof(node));
    new->coeff = coeff;
    new->pow = pow;
    new->next = NULL;
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    return head;
}

node *sumTwoPol(node *p1, node *p2){
    node *res = (node *)malloc(sizeof(node));
    node *t1 = p1;
    node *t2 = p2;
    res->next = NULL;
    // init first node of result
    if(t1->pow > t2->pow){
        //res = createNode(t1->coeff, t1->pow);
        res->coeff = t1->coeff;
        res->pow = t1->pow;
        t1 = t1->next;
    }else if(t1->pow < t2->pow){
        //res = createNode(t2->coeff, t2->pow);
        res->coeff = t2->coeff;
        res->pow = t2->pow;
        t2 = t2->next;
    }else{
        //res = createNode(t1->coeff + t2->coeff, t2->pow);
        res->coeff = t1->coeff + t2->coeff;
        res->pow = t2->pow;
        t1 = t1->next;
        t2 = t2->next;
    }
    // loop
    while (t1 != NULL && t2 != NULL)
    {  
        if(t1->pow == t2->pow){
            res = addToLast(res, t1->coeff + t2->coeff, t1->pow);
            t1 = t1->next;
            t2 = t2->next;
        }else if(t1->pow > t2->pow){
            res = addToLast(res, t1->coeff, t1->pow);
            t1 = t1->next;
        }else{
            res = addToLast(res, t2->coeff, t2->pow);
            t2 = t2->next;
        }
    }
    // 
    if(t1 == NULL){
        while (t2 != NULL)
        {
            res = addToLast(res, t2->coeff, t2->pow);
            t2 = t2->next;
        }
    }
    if(t2 == NULL){
        while (t1 != NULL)
        {
            res = addToLast(res, t1->coeff, t1->pow);
            t1 = t1->next;
        }
    }
    return res;
}

int main(){
    node *p1 = createPol();
    node *p2 = createPol();
    printf("p1:\n");
    printList(p1);
    printf("p2:\n");
    printList(p2);
    printf("result:\n");
    
    node *res = sumTwoPol(p1, p2);
    printList(res);
    /*
    addToLast(p1, 100, 100);
    printf("p1 after add:\n");
    printList(p1);
    */
}
// FUCKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKkkkkkkk