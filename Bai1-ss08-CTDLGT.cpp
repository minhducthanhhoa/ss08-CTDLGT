#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Ham chen nut vao cay nhi phan tim kiem 
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Ham duyet cay theo thu tu Tien Thu Tu (Pre-order)
void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Ham duyet cay theo thu tu Trung Thu Tu (In-order)
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Ham duyet cay theo thu tu Hau Thu Tu (Post-order)
void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int n, value;

    printf("Nhap so luong nut trong cay: ");
    scanf("%d", &n);

    printf("Nhap gia tri cac nut: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("\nDuyet Tien Thu Tu: \n");
    preOrderTraversal(root);

    printf("\n\nDuyet Trung Thu Tu: \n");
    inOrderTraversal(root);

    printf("\n\nDuyet Hau Thu Tu: \n");
    postOrderTraversal(root);

    return 0;
}

