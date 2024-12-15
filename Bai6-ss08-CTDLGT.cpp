#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

// Ham kiem tra cay co phai la cay nhi phan tim kiem khong
int isBSTUtil(struct Node* root, int min, int max) {
    if (root == NULL) {
        return 1;
    }
    if (root->data <= min || root->data >= max) {
        return 0;
    }
    return isBSTUtil(root->left, min, root->data) && isBSTUtil(root->right, root->data, max);
}

int isBST(struct Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Ham duyet cay theo thu tu Trung Thu Tu (In-order)
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
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

    printf("\nDuyet cay theo thu tu inorder: \n");
    inOrderTraversal(root);

    printf("\n\nKiem tra cay co phai la BST: \n");
    if (isBST(root)) {
        printf("Cay la cay nhi phan tim kiem (BST).\n");
    } else {
        printf("Cay khong phai la cay nhi phan tim kiem (BST).\n");
    }

    return 0;
}

