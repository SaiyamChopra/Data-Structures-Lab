#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the BST
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

// Function to insert a new node in the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);  // If root is null, create a new node
    }
    if (data < root->data) {
        root->left = insert(root->left, data);  // Recur to the left subtree
    } else if (data > root->data) {
        root->right = insert(root->right, data);  // Recur to the right subtree
    }
    return root;
}

// Function to perform an in-order traversal of the BST
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);           // Visit left subtree
        printf("%d ", root->data);     // Visit node
        inOrder(root->right);          // Visit right subtree
    }
}

// Function to perform a pre-order traversal of the BST
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);     // Visit node
        preOrder(root->left);          // Visit left subtree
        preOrder(root->right);         // Visit right subtree
    }
}

// Function to perform a post-order traversal of the BST
void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);         // Visit left subtree
        postOrder(root->right);        // Visit right subtree
        printf("%d ", root->data);     // Visit node
    }
}

// Function to find the minimum value node in the BST
struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;  // Go to the leftmost node
    }
    return current;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;  // Base case: tree is empty
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);  // Recur for the left subtree
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);  // Recur for the right subtree
    } else {
        // Node to be deleted is found
        // Case 1: Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Case 2: Node with two children
        struct Node* temp = findMin(root->right);  // Find the inorder successor
        root->data = temp->data;  // Copy the inorder successor's value
        root->right = deleteNode(root->right, temp->data);  // Delete the inorder successor
    }
    return root;
}

// Function to search for a node in the BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;  // Key is found or tree is empty
    }
    if (key < root->data) {
        return search(root->left, key);  // Recur to the left subtree
    }
    return search(root->right, key);  // Recur to the right subtree
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. In-order Traversal\n");
        printf("5. Pre-order Traversal\n");
        printf("6. Post-order Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted successfully.\n", value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("%d deleted successfully (if it exists).\n", value);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* foundNode = search(root, value);
                if (foundNode != NULL) {
                    printf("%d found in the BST.\n", value);
                } else {
                    printf("%d not found in the BST.\n", value);
                }
                break;

            case 4:
                printf("In-order Traversal: ");
                inOrder(root);
                printf("\n");
                break;

            case 5:
                printf("Pre-order Traversal: ");
                preOrder(root);
                printf("\n");
                break;

            case 6:
                printf("Post-order Traversal: ");
                postOrder(root);
                printf("\n");
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
