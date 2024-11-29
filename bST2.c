#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary search tree node
struct node {
    int data;
    struct node *L;
    struct node *R;
} *start = NULL;

// Function to create a new node
struct node* creat(int k) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed. We are sorry we can't continue at this moment.\n");
        return NULL;
    }
    temp->data = k;
    temp->L = temp->R = NULL;
    return temp;  // Return the newly created node
}

// Function to insert a new node into the binary search tree
struct node* insertion(struct node *temp, int k) {
    if (temp == NULL) {
        temp = creat(k);  // Use creat to create a new node
        return temp;
    }
    if (k < temp->data) {
        temp->L = insertion(temp->L, k);  // Insert in the left subtree
    } else if (k > temp->data) {
        temp->R = insertion(temp->R, k);  // Insert in the right subtree
    }
    return temp;
}

// Function to find the minimum value node (used for deletion)
struct node* findMin(struct node *root) {
    while (root != NULL && root->L != NULL) {
        root = root->L;  // Go to the leftmost node
    }
    return root;
}

// Function to delete a node from the binary search tree
struct node* deletion(struct node *root, int key) {
    if (root == NULL) {
        return root;  // Node not found
    }

    // Search for the node to be deleted
    if (key < root->data) {
        root->L = deletion(root->L, key);  // Go to left subtree
    } else if (key > root->data) {
        root->R = deletion(root->R, key);  // Go to right subtree
    } else {
        // Case 1: Node with only one child or no child
        if (root->L == NULL) {
            struct node *temp = root->R;
            free(root);  // Free memory
            return temp;  // Return the non-NULL child (or NULL)
        } else if (root->R == NULL) {
            struct node *temp = root->L;
            free(root);  // Free memory
            return temp;  // Return the non-NULL child (or NULL)
        }

        // Case 2: Node with two children
        struct node *temp = findMin(root->R);  // Find the in-order successor
        root->data = temp->data;  // Replace the data with in-order successor's data
        root->R = deletion(root->R, temp->data);  // Delete the in-order successor
    }
    return root;
}

// Function to print the tree (Inorder Traversal)
void inorder(struct node *temp) {
    if (temp != NULL) {
        inorder(temp->L);  // Visit left subtree
        printf("%d ", temp->data);  // Print the current node
        inorder(temp->R);  // Visit right subtree
    }
}

// Function to print the tree (Preorder Traversal)
void preorder(struct node *temp) {
    if (temp != NULL) {
        printf("%d ", temp->data);  // Print the current node
        preorder(temp->L);  // Visit left subtree
        preorder(temp->R);  // Visit right subtree
    }
}

// Function to print the tree (Postorder Traversal)
void postorder(struct node *temp) {
    if (temp != NULL) {
        postorder(temp->L);  // Visit left subtree
        postorder(temp->R);  // Visit right subtree
        printf("%d ", temp->data);  // Print the current node
    }
}

// Main function to run the program
int main() {
    int choice, value;
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Find Minimum Value\n");
        printf("7. Exit\n");
    while (1) {

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                start = insertion(start, value);
                printf("Node %d inserted successfully.\n", value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                start = deletion(start, value);
                printf("Node %d deleted successfully.\n", value);
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorder(start);
                printf("\n");
                break;

            case 4:
                printf("Preorder Traversal: ");
                preorder(start);
                printf("\n");
                break;

            case 5:
                printf("Postorder Traversal: ");
                postorder(start);
                printf("\n");
                break;

            case 6:
                if (start == NULL) {
                    printf("The tree is empty.\n");
                } else {
                    struct node *minNode = findMin(start);
                    printf("The minimum value in the tree is: %d\n", minNode->data);
                }
                break;

            case 7:
                printf("Exiting the program.\n");
                exit(0);  // Exit the program

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
