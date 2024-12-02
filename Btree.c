#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    // Return the unchanged node pointer
    return root;
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int key) {
    // Base case: root is null or key is present at root
    if (root == NULL || root->data == key) {
        return root;
    }

    // Key is greater than root's data
    if (key > root->data) {
        return search(root->right, key);
    }

    // Key is smaller than root's data
    return search(root->left, key);
}

// Function to perform inorder traversal of the BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to free the allocated memory for the BST
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to demonstrate BST operations
int main() {
    struct Node* root = NULL;
    int n, data;

    // Accept number of elements from the user
    printf("Enter the number of elements to insert into the BST: ");
    scanf("%d", &n);

    // Accept dynamic input for the BST
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        root = insert(root, data);
    }

    // Display the elements in inorder (sorted order)
    printf("Inorder traversal of the BST: ");
    inorder(root);
    printf("\n");

    // Searching for a value in the BST
    printf("Enter a value to search in the BST: ");
    scanf("%d", &data);
    struct Node* searchResult = search(root, data);
    if (searchResult != NULL) {
        printf("Element %d found in the BST.\n", data);
    } else {
        printf("Element %d not found in the BST.\n", data);
    }

    // Free the allocated memory for the BST
    freeTree(root);

    return 0;
}
