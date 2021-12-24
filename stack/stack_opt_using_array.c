#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int size;
    int *arr;
};

// check is whether stack empty of not
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

// check is whether stack full or not
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}

// push operation in stack
void push(struct stack *ptr, int key)
{
    if (isFull(ptr) == 1)
    {
        printf("OVERFLOW CONDITION\n");
        return;
    }

    ptr->top++;
    ptr->arr[ptr->top] = key;
    return;
}

// pop operation in stack
int pop(struct stack *ptr)
{
    if (isEmpty(ptr) == 1)
    {
        printf("UNDERFLOW CONDITION\n");
        return -1;
    }

    int val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
}

int main()
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 8;
    s->arr = (int *)malloc(s->size * (sizeof(int)));
    printf("%d\n", isEmpty(s));
    printf("%d\n", isFull(s));
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 10);
    printf("%d\n", isEmpty(s));
    printf("%d\n", isFull(s));
    printf("%d\n",pop(s));
    printf("%d\n", isEmpty(s));
    printf("%d\n", isFull(s));

    return 0;
}
