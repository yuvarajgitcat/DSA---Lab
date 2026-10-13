#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *insert(struct node *root, int data)
{
    if (root == NULL) {
        root = (struct node *)malloc(sizeof(struct node));
        root->data = data;
        root->left = root->right = NULL;
    } else if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        printf("Duplicate value!\n");
    return root;
}

struct node *minNode(struct node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct node *delete(struct node *root, int key)
{
    if (root == NULL) {
        printf("Node not found!\n");
        return NULL;
    }
    if (key < root->data)
        root->left = delete(root->left, key);
    else if (key > root->data)
        root->right = delete(root->right, key);
    else if (root->left && root->right) {      /* two children */
        root->data = minNode(root->right)->data;
        root->right = delete(root->right, root->data);
    } else {                                   /* 0 or 1 child */
        struct node *child = root->left ? root->left : root->right;
        free(root);
        return child;
    }
    return root;
}

int search(struct node *root, int key)
{
    if (root == NULL) return 0;
    if (key == root->data) return 1;
    return key < root->data ? search(root->left, key) : search(root->right, key);
}

void inorder(struct node *root)
{
    if (root) { inorder(root->left); printf("%d ", root->data); inorder(root->right); }
}

void preorder(struct node *root)
{
    if (root) { printf("%d ", root->data); preorder(root->left); preorder(root->right); }
}

void postorder(struct node *root)
{
    if (root) { postorder(root->left); postorder(root->right); printf("%d ", root->data); }
}

int main(void)
{
    struct node *root = NULL;
    int choice, n;

    while (1) {
        printf("\n1.Insert 2.Delete 3.Search 4.Inorder 5.Preorder 6.Postorder 7.Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
        case 1: printf("Enter value: "); scanf("%d", &n); root = insert(root, n); break;
        case 2: printf("Enter value: "); scanf("%d", &n); root = delete(root, n); break;
        case 3: printf("Enter value: "); scanf("%d", &n);
                printf(search(root, n) ? "Found\n" : "Not found\n"); break;
        case 4: inorder(root);   printf("\n"); break;
        case 5: preorder(root);  printf("\n"); break;
        case 6: postorder(root); printf("\n"); break;
        case 7: return 0;
        default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
