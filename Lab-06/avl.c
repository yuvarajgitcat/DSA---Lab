#include <stdio.h>
#include <stdlib.h>

// Structural Blueprint for an AVL Tree Node
struct Node {
    int data;
    int height;
    struct Node *left;
    struct Node *right;
};

// Helper function to find the maximum of two integers
int maxx(int a, int b) {
    return (a > b) ? a : b;
}

// Helper function to safely get the height of a node (handles NULL pointers)
int height(struct Node *n) {
    return (n == NULL) ? 0 : n->height;
}

// Creates and initializes a brand new leaf node
struct Node* newNode(int x) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    if (n == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    n->data = x;
    n->left = NULL;
    n->right = NULL;
    n->height = 1; // New node is initially added at leaf level (height = 1)
    return n;
}

// Right rotation utility to fix Left-Heavy (LL) imbalances
struct Node* rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *t = x->right;

    // Perform the pointer swap
    x->right = y;
    y->left = t;

    // Update heights (order matters: update the lower node 'y' first)
    y->height = 1 + maxx(height(y->left), height(y->right));
    x->height = 1 + maxx(height(x->left), height(x->right));

    // Return the new local root
    return x;
}

// Left rotation utility to fix Right-Heavy (RR) imbalances
struct Node* leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *t = y->left;

    // Perform the pointer swap
    y->left = x;
    x->right = t;

    // Update heights (order matters: update the lower node 'x' first)
    x->height = 1 + maxx(height(x->left), height(x->right));
    y->height = 1 + maxx(height(y->left), height(y->right));

    // Return the new local root
    return y;
}

// Recursive insertion engine that auto-balances the tree on its way up
struct Node* insert(struct Node *root, int x) {
    // 1. Perform standard BST Insertion
    if (root == NULL)
        return newNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    else
        return root; // Duplicate values are not allowed in this tree

    // 2. Update the height of the current ancestor node
    root->height = 1 + maxx(height(root->left), height(root->right));

    // 3. Calculate the Balance Factor to check for instability
    int bf = height(root->left) - height(root->right);

    // 4. If unbalanced, execute one of the 4 corrective structural maneuvers
    
    // Left-Left (LL) Case
    if (bf > 1 && x < root->left->data)
        return rightRotate(root);

    // Right-Right (RR) Case
    if (bf < -1 && x > root->right->data)
        return leftRotate(root);

    // Left-Right (LR) Case
    if (bf > 1 && x > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right-Left (RL) Case
    if (bf < -1 && x < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // Return the unchanged node pointer if it's perfectly balanced
    return root;
}

// Prints the tree using Inorder Traversal (Left -> Root -> Right)
void inorder(struct Node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Utility function to visually print the tree structure sideways in console
void printTree(struct Node *root, int space) {
    int COUNT = 5; // Distance between levels
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first (printed on top)
    printTree(root->right, space);

    // Print current node after space
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Process left child (printed on bottom)
    printTree(root->left, space);
}

int main() {
    struct Node *root = NULL;

    // Insert elements that will force the tree to perform rotations
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 28);

    printf("--- Visual Balanced AVL Tree Structure (Sideways) ---\n");
    printTree(root, 0);
    printf("-----------------------------------------------------\n\n");

    printf("Inorder traversal of the balanced AVL tree: ");
    inorder(root);
    printf("\n");

    return 0;
}
