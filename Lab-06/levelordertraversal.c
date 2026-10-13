#include <stdio.h>
#include <stdlib.h>

// Structural Blueprint for a basic Binary Tree Node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Creates and initializes a brand new node
struct Node* newNode(int x) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    if (n == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    n->data = x;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Level-Order Traversal Engine (Breadth-First Search)
void levelOrder(struct Node *root) {
    if (root == NULL)
        return;

    // Fixed-size array acting as our queue line
    struct Node *q[100];
    int front = 0, rear = 0;

    // Step 1: Enqueue the root node to kickstart the line
    q[rear++] = root;

    // Step 2: Keep processing as long as there are nodes waiting in line
    while (front < rear) {
        // Dequeue the node at the front of the line
        struct Node *current = q[front++];
        
        // Print the active node's data
        printf("%d ", current->data);

        // Enqueue left child if it exists (goes to the back of the line)
        if (current->left != NULL)
            q[rear++] = current->left;

        // Enqueue right child if it exists (goes to the back of the line)
        if (current->right != NULL)
            q[rear++] = current->right;
    }
    printf("\n");
}

int main() {
    // Manually constructing the binary tree structure
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    // Run the level order traversal
    printf("Level-Order Traversal Output: ");
    levelOrder(root);

    return 0;
}
