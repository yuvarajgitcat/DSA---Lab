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

// Helper function to calculate the balance factor of any node
int getBalance(struct Node *n) {
    return (n == NULL) ? 0 : height(n->left) - height(n->right);
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
    else {
        printf("Duplicate value!\n");
        return root; 
    }

    // 2. Update the height of the current ancestor node
    root->height = 1 + maxx(height(root->left), height(root->right));

    // 3. Calculate the Balance Factor to check for instability
    int bf = getBalance(root);

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

    return root;
}

// Minimum node tracker style requested by the user
struct Node *minNode(struct Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Integrated Deletion engine utilizing the user's specific conditional layout style
struct Node *deleteNode(struct Node *root, int key)
{
    // PHASE 1: Standard Deletion Branching Logic
    if (root == NULL) {
        printf("Node not found!\n");
        return NULL;
    }
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else if (root->left && root->right) {      /* Scenario: Two children */
        root->data = minNode(root->right)->data;
        root->right = deleteNode(root->right, root->data);
    } else {                                   /* Scenario: 0 or 1 child */
        struct Node *child = root->left ? root->left : root->right;
        free(root);
        return child; // Early return for deleted items
    }

    // PHASE 2: Mandatory AVL Balancing Layers
    // Update height of the current node
    root->height = 1 + maxx(height(root->left), height(root->right));

    // Calculate balance factor to verify structural equilibrium
    int bf = getBalance(root);

    // Left Heavy Cases
    if (bf > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (bf > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Heavy Cases
    if (bf < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (bf < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Search utility
int search(struct Node *root, int key) {
    if (root == NULL) return 0;
    if (key == root->data) return 1;
    return key < root->data ? search(root->left, key) : search(root->right, key);
}

// Tree Traversals
void inorder(struct Node *root) {
    if (root) { inorder(root->left); printf("%d ", root->data); inorder(root->right); }
}

void preorder(struct Node *root) {
    if (root) { printf("%d ", root->data); preorder(root->left); preorder(root->right); }
}

void postorder(struct Node *root) {
    if (root) { postorder(root->left); postorder(root->right); printf("%d ", root->data); }
}

// Sideways layout generator 
void printTree(struct Node *root, int space) {
    int COUNT = 5;
    if (root == NULL) return;
    space += COUNT;
    printTree(root->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++) printf(" ");
    printf("%d\n", root->data);
    printTree(root->left, space);
}

int main(void) {
    struct Node *root = NULL;
    int choice, n;

    while (1) {
        printf("\n1.Insert 2.Delete 3.Search 4.Inorder 5.Preorder 6.Postorder 7.Visualise 8.Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1: 
                printf("Enter value to insert: "); scanf("%d", &n); 
                root = insert(root, n); break;
            case 2: 
                printf("Enter value to delete: "); scanf("%d", &n); 
                root = deleteNode(root, n); break;
            case 3: 
                printf("Enter value to search: "); scanf("%d", &n);
                printf(search(root, n) ? "Found\n" : "Not found\n"); break;
            case 4: 
                printf("Inorder Traversal: "); inorder(root); printf("\n"); break;
            case 5: 
                printf("Preorder Traversal: "); preorder(root); printf("\n"); break;
            case 6: 
                printf("Postorder Traversal: "); postorder(root); printf("\n"); break;
            case 7: 
                printf("--- Visual AVL Tree Layout (Sideways) ---\n");
                printTree(root, 0);
                printf("-----------------------------------------\n");
                break;
            case 8: 
                return 0;
            default: 
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
