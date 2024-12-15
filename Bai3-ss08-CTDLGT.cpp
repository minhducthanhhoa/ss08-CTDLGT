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

// Ham tim cac dinh o lop 2
void findLevelTwoNodes(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printf("\nCac dinh lop 2: ");

    if (root->left != NULL) {
        if (root->left->left != NULL) {
            printf("%d ", root->left->left->data);
        }
        if (root->left->right != NULL) {
            printf("%d ", root->left->right->data);
        }
    }

    if (root->right != NULL) {
        if (root->right->left != NULL) {
            printf("%d ", root->right->left->data);
        }
        if (root->right->right != NULL) {
            printf("%d ", root->right->right->data);
        }
    }
    printf("\n");
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

    printf("\nDuyet Tien Thu Tu: \n");
    preOrderTraversal(root);

    printf("\n\nDuyet Trung Thu Tu: \n");
    inOrderTraversal(root);

    printf("\n\nDuyet Hau Thu Tu: \n");
    postOrderTraversal(root);

    findLevelTwoNodes(root);

    printf("\nNhap gia tri can tim: ");
    scanf("%d", &searchValue);

    if (searchNode(root, searchValue)) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}

