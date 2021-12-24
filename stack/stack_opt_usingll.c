#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *link;
};

int isEmpty(struct stack* top){
    if (top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    struct stack *n = (struct stack *)malloc(sizeof(struct stack));
    if (n == NULL)
        return 1;
    else
        return 0;
}

struct stack *push(struct stack *top, int val)
{
    if (isFull(top) == 1)
    {
        printf("stack overflow\n");
        return NULL;
    }

    struct stack *n = (struct stack *)malloc(sizeof(struct stack));
    n->link = top;
    n->data = val;
    top = n;
    return top;
}

int pop(struct stack** top){
    if(isEmpty(*top)==1){
        printf("Stack Underflow\n");
    }
    else{
        struct stack* temp = *top;
        *top = (*top)->link;
        int x = temp->data;
        free(temp);
        return x; 
    }
}

void llTraversal(struct stack *ptr)
{   int i =0;
    while (ptr != NULL)
    {
        printf("Element at %d is : %d\n", i, ptr->data);
        ptr = ptr->link;
        i++; 
    }
}

//peek operation Returns the top element present in the stack without modifying the stack

int peek(struct stack* top, int pos){
    struct stack* ptr = top;
    for(int i =0; (i< pos -1 && ptr != NULL); i++){
        ptr=ptr->link;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }

}

int main()
{
    struct stack *top = NULL;
    top = push(top, 20);
    top = push(top, 19);
    top = push(top, 18);
    top = push(top, 17);
    top = push(top, 16);
    top = push(top, 15);
    top = push(top, 14);
    top = push(top, 13);
    top = push(top, 12);
    top = push(top, 11);
    top = push(top, 9);
    top = push(top, 8);
    llTraversal(top);
    printf("%d\n", top->data);
    printf("%d\n",pop(&top));
    llTraversal(top);
    printf("%d\n",pop(&top));
    llTraversal(top);

    printf("%d\n", top->data);

    for(int i = 2 ; i<8 ; i++){
        printf("\nELEMENT at %d is %d ", i , peek(top,i));
        // printf("\n");
    }

    return 0;
}