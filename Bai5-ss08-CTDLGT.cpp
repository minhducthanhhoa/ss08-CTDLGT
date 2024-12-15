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

// Ham tim kiem gia tri trong cay 
int searchNode(struct Node* root, int key) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == key) {
        return 1;
    }
    if (key < root->data) {
        return searchNode(root->left, key);
    }
    return searchNode(root->right, key);
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
    int n, value, searchValue;

    printf("Nhap so luong nut trong cay: ");
    scanf("%d", &n);

    printf("Nhap gia tri cac nut: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("\nDuyet cay theo thu tu inorder: \n");
    inOrderTraversal(root);

    printf("\n\nNhap gia tri can tim: ");
    scanf("%d", &searchValue);

    if (searchNode(root, searchValue)) {
        printf("Giá tri %d ton tai trong cay.\n", searchValue);
    } else {
        printf("Giá tri %d khong ton tai trong cay.\n", searchValue);
    }

    return 0;
}

