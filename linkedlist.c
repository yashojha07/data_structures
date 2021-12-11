#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *createNode(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->link = NULL;

    return newnode;
}

struct node *prependNode(struct node *head, int val)
{
    struct node *newnode = createNode(val);

    if (NULL == head)
        return NULL;

    newnode->link = head;
    head = newnode;
    return newnode;
}

// insert after a given node
struct node *insertAfter(struct node *head, int data, int val)
{
    struct node *newnode = createNode(val);
    struct node *ptr = head;
    int i = 0;
    while (ptr->data != data)
    {
        ptr = ptr->link;
    }

    newnode->link = ptr->link;
    ptr->link = newnode;
    return head;
}

struct node *inserAtidx(struct node *head, int val, int index)
{
    if (index == 0)
        return NULL;

    struct node *newnode = createNode(val);
    // newnode->data = val;

    int i = 0;
    struct node *ptr = head;
    while (i != index - 1)
    {
        ptr = ptr->link;
        i++;
    }
    newnode->link = ptr->link;
    // ptr->data = 44;
    ptr->link = newnode;
    return head;
}

struct node *appendNode(struct node *head, int val)
{
    struct node *newnode = createNode(val);
    struct node *ptr = head;
    int i = 0;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = newnode;
    return head;
}



// deletion of the first node
struct node *delfirst(struct node *head)
{
    struct node *ptr = head;
    head = head->link;
    free(ptr);
    return head;
}

// deletion at given index
struct node *delatIdx(struct node *head, int index)
{
    struct node *p = head;
    struct node *q;
    int i = 0;
    while (i != index - 1)
    {
        p = p->link;
        i++;
    }
    q = p->link;
    p->link = q->link;
    free(q);
    return head;
}

// deletion for the last element
struct node *delatEnd(struct node *head)
{
    struct node *p = head;
    struct node *q = head->link;
    while (q->link != NULL)
    {
        p = p->link;
        q = q->link;
    }
    p->link = NULL;
    free(q);
    return head;
}

// delete the element with given value

struct node *delEle(struct node *head, int val)
{
    struct node *p = head;
    struct node *q = head->link;
    while (q->data != val)
    {
        p = p->link;
        q = q->link;
    }
    p->link = q->link;
    free(q);
    return head;
}

struct node *reverse(struct node *head, int k)
{
    // base case
    if (!head)
        return NULL;
    struct node *current = head;
    struct node *next = NULL;
    struct node *prev = NULL;
    int count = 0;

    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
        count++;
    }

    
    if (next != NULL)
        head->link = reverse(next, k);

    /* prev is new head of the input list */
    return prev;
}

// to create a cycle in linkedlist

void makecycle(struct node *head, int k)
{
    struct node *temp = head;
    struct node *startnode;
    int counter = 0;
    while (temp->link != NULL)
    {
        if (counter == k)
        {
            startnode = temp;
        }
        temp = temp->link;
        counter++;
    }
    temp->link = startnode;

    return;
}

// to detect cycle in the linkedlist

int detect_cycle(struct node *head)
{
    struct node *high = head;
    struct node *low = head;
    while (high != NULL && high->link != NULL)
    {

        low = low->link;
        high = high->link->link;
        if (high == low)
        {
            return 1;
        }
    }
    return 0;
}

// to remove the linkedlist

void remove_cycle(struct node *head)
{
    struct node *high = head;
    struct node *low = head;

    do
    {
        high = high->link->link;
        low = low->link;
    } while (high != low);

    high = head;

    while (high->link != low->link)
    {
        high = high->link;
        low = low->link;
    }
    low->link = NULL;

    return;
}

// find the starting point of the loop
int find_start(struct node *head)
{

    if (detect_cycle(head) == 1)
    {

        struct node *high = head;
        struct node *low = head;

        do
        {
            high = high->link->link;
            low = low->link;
        } while (high != low);

        high = head;

        while (high->link != low->link)
        {
            high = high->link;
            low = low->link;
        }
        low = low->link;
        return low->data;
    }
    
    return 0;
}

// to print the linkedlist

void printList(struct node *head)
{
    // if (NULL == head)
    //     return;

    struct node *node = head;
    while (node)
    {
        printf("%d --> ", node->data);
        node = node->link;
    }
    printf("EMPTYNODE\n");
}

int main()
{
    struct node *head = NULL;
    struct node *tail = NULL;
    tail = head;
    head = createNode(25);
    printf("%d\n", head);
    printList(head);
    for (int i = 0; i < 6; i++)
    {
        head = prependNode(head, 25 - 2 * i);
    }
    printList(head);
    head = appendNode(head, 99);
    printList(head);
    head = inserAtidx(head, 72, 2);
    printList(head);
    head = insertAfter(head, 21, 3);
    printList(head);
    head = delfirst(head);
    printList(head);
    head = delatIdx(head, 4);
    printList(head);
    head = delatEnd(head);
    printList(head);
    head = delEle(head, 23);
    printList(head);
    head = reverse(head, 3);
    printList(head);
    makecycle(head, 3);
    // printList(head);
    int a = detect_cycle(head);
    printf("%d\n", a);
    int b = find_start(head);
    printf(" %d\n", b);
    // remove_cycle(head);
    // printList(head);

    return 0;
}
