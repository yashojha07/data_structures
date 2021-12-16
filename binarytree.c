#include <stdio.h>
#include <stdlib.h>
#define GLOBALSPACE 5

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// creating a node
struct node *createNode(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// to print the preoder in a binery tree

void printPreorder(struct node *node)
{

    if (node == NULL)
        return;
    printf(" %d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);

    return;
}

// to print the inorder in a binary tree

void printInorder(struct node *node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
    printf(" %d ", node->data);
    printInorder(node->right);
    return;
}

// to print the postorder in the binary tree

void printPostorder(struct node *node)
{
    if (node == NULL)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    printf(" %d ", node->data);
}

// searching in a bst (using recurrsion)

struct node *searching(struct node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        return searching(root->left, key);
    }
    else
    {
        return searching(root->right, key);
    }
}

// searching using iterative way

struct node *search_itr(struct node *root, int key)
{
    while (root != NULL)
    {

        if (key == root->data)
        {
            return root;
        }
        else if (root->data < key)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return NULL;
}

// insertion in bst using iterative methord

void insertNode(struct node *root, int key)
{
    struct node *prev = NULL;

    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            printf("INSERTION IS NOT POSSIBLE\n");
            return;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *newNode = createNode(key);

    if (prev->data > key)
    {
        prev->left = newNode;
    }
    else
    {
        prev->right = newNode;
    }

    return;
}

// insertion using recurrsive methord

struct node *insertion(struct node *root, int key)
{
    struct node *newNode = createNode(key);

    if (root == NULL)
    {
        root = newNode;
        return root;
    }

    if (root->data == key)
    {
        printf("INSERTION IS NOT POSSIBLE\n");
        return NULL;
    }
    else if (root->data > key)
    {
        root->left = insertion(root->left, key);
    }
    else
    {
        root->right = insertion(root->right, key);
    }

    return root;
}


//to find out is given tree a BST

int isBST(struct  node* root){
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

struct node *inOrderPredecessor(struct node* root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}

// deletion of the node

struct node *deleteNode(struct node *root, int value){

    struct node* iPre;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){
        free(root);
        return NULL;
    }

    //searching for the node to be deleted
    if (value < root->data){
        root-> left = deleteNode(root->left,value);
    }
    else if (value > root->data){
        root-> right = deleteNode(root->right,value);
    }
    //deletion strategy when the node is found
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}

// to print the tree

void print2D(struct node *root, int space)
{
    if (root == NULL)
        return;

    space = space + GLOBALSPACE;
    print2D(root->right, space);
    printf("\n");
    for (int i = GLOBALSPACE; i < space; i++)
    {
        printf("  ");
    }
    printf("%d\n", root->data);
    print2D(root->left, space);
}

//to find the maximum depth of binary tree
int depth(struct node *root)
{

    if (root == NULL)
        return -1;
    else
    {
        int lheight = depth(root->left);
        int rheight = depth(root->right);
        if (lheight > rheight)
        {
            return lheight + 1;
        }
        else
        {
            return rheight + 1;
        }
    }
}

/* There is a difference between maximum depth and height of BT 
Max height include no. of edges while depth consists of maximum no. of nodes*/

// height of a  binary tree
int height(struct node * node) {
  if (node == NULL)
    return -1;
  else {
    int lheight = height(node -> left);
    int rheight = height(node -> right);
    if (lheight > rheight)
      return (lheight + 1);
    else return (rheight + 1);
  }
}


//level order traversal without using queue


void CurrentLevel(struct node * root, int level) {
  if (root == NULL)
    return;
  if (level == 1)
    printf("%d ", root -> data);
  else if (level > 1) {
    CurrentLevel(root -> left, level - 1);
    CurrentLevel(root -> right, level - 1);
  }
  return;
}

void LevelOrder(struct node * root) {
  int h = height(root);
  int i;
  for (i = 1; i <= h; i++)
    {
        CurrentLevel(root, i);
    }
   
    return;
}


void mirrorImage(struct node *root)
{  
    if(root==NULL)return;
    struct node *ptr;

    mirrorImage(root->left);
    mirrorImage(root->right);
    ptr = root->left;
    root->left = root->right;
    root->right = ptr;
    return;
}

int main()
{
    struct node *root = NULL;

    /*        50
            /    \
           30     60
          /  \    / \
         20   40 55  65

                             */

    root = createNode(50);
    printf("%d\n", root);
    root->left = createNode(30);
    root->right = createNode(60);

    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(55);
    root->right->right = createNode(65);
    printf("%d\n", height(root));
    // print2D(root,3);
    printf("\n");
    printf("\n");

    printPreorder(root);
    printf("\n");
    printInorder(root);
    printf("\n");
    printPostorder(root);
    printf("\n");
    struct node *ptr = searching(root, 95);
    if (ptr != NULL)
    {
        printf("FOUND: %d\n", ptr->data);
    }
    else
    {
        printf("KEY IS NOT FOUND\n");
    }

    struct node *n = search_itr(root, 65);
    if (n != NULL)
    {
        printf("FOUND: %d\n", n->data);
    }
    else
    {
        printf("KEY IS NOT FOUND\n");
    }
    insertNode(root, 10);
    printf("%d\n", root->left->left->left->data);
    struct node *p = insertion(root, 25);
    // print2D(root,3);
    printf("\n");
    printf("\n");
    printf("%d\n", root->left->left->right->data);
    struct node* current = deleteNode(root,50);
    print2D(root, 3);
    printf("%d\n", root->left->left->data);
    printf("%d\n", root->left->left->left->data);
    LevelOrder(root);
    mirrorImage(root);
    print2D(root, 3);


    return 0;
}
