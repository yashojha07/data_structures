#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

// to create a node
struct node *createNode(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->data = val;

    return newNode;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* INSERTION OF NODES  */

// prepend node: add in the begining

struct node *prependNode(struct node *head, int val)
{
    struct node *newNode = createNode(val);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return head;
}

// insert after a given node

void afterNode(struct node *prev_node, int val)
{

    if (prev_node == NULL)
        return;

    struct node *newNode = createNode(val);
    newNode->next = prev_node->next;
    newNode->prev = prev_node->next->prev;
    prev_node->next->prev = newNode;
    prev_node->next = newNode;
    return;
}

// append node: add at the end

struct node *appendNode(struct node *tail, int val)
{
    struct node *newNode = createNode(val);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    return tail;
}

// add a node at a given index

struct node *insertatIdx(struct node *head, int val, int index)
{
    struct node *newNode = createNode(val);
    struct node *p = head;
    // struct node* q;
    int i = 0;
    while (i != index - 1)
    {

        p = p->next;
        // q = p->next;
        i++;
    }
    // newNode->next = p->next;
    // newNode->prev = q->prev;
    // p->next = newNode;
    // q->prev = newNode;
    newNode->next = p->next;
    newNode->prev = p->next->prev;
    p->next->prev = newNode;
    p->next = newNode;
    return head;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* DELETION OF NODES */

// deletion of the first node
struct node *delfirst(struct node *head)
{

    if (head == NULL)
        return NULL;

    struct node *ptr = head;
    head = ptr->next;
    ptr->next->prev = NULL;
    free(ptr);
    return head;
}

// deletion of the last node

struct node *delLast(struct node *tail)
{
    struct node *ptr = tail;
    tail = ptr->prev;
    tail->next = NULL;
    free(ptr);
    return tail;
}

// deletion at the given index

struct node *delatIdx(struct node *head, int index)
{
    struct node *p = head;
    struct node *q;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = p->next;
        i++;
    }
    p->next = q->next;
    q->next->prev = q->prev;
    free(q);
    return head;
}

// delete the element with given value
struct node *delVal(struct node *head, int val)
{

    if (head->data == val)
        return NULL;

    struct node *ptr = head;
    struct node *temp;
    while (ptr->data != val)
    {
        ptr = ptr->next;
        temp = ptr->prev;
    }
    temp->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
    return head;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*REVERSE THE DOUBLY LINKED LIST */

//using iterative methord

struct node* reverse(struct node* head){
    struct node* prev = NULL;
    struct  node* current = head;
    struct node* next = head;
    while(next!= NULL){
        next = next->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current= next;
    }
    head = prev;
    return head;
}





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// print list
void printList(struct node *head)
{
    struct node *current = head;
    if (head == NULL)
    {
        printf("LIST IS EMPTY");
        return;
    }
    else
    {
        while (current)
        {
            printf("%d  <--->  ", current->data);
            current = current->next;
        }
        printf("EMPTYNODE\n");
    }
}

int main()
{
    struct node *head = NULL;
    struct node *tail = NULL;

    head = createNode(25);
    tail = head;
    printf("%d\n", head);
    printList(head);
    head = prependNode(head, 20);
    printf("%d\n", head->next->prev);
    head = prependNode(head, 15);
    printList(head);
    for (int i = 1; i < 6; i++)
    {
        tail = appendNode(tail, 25 + 5 * i);
    }
    printList(head);
    head = insertatIdx(head, 75, 3);
    printList(head);
    afterNode(head->next->next, 100);
    printList(head);
    head = delfirst(head);
    printList(head);
    tail = delLast(tail);
    printList(head);
    head = delatIdx(head, 3);
    printList(head);
    head = delVal(head, 100);
    printList(head);
    head = reverse(head);
    printList(head);
    printf("%d %d %d\n", head->prev, tail->data, tail->next);
    return 0;
}
