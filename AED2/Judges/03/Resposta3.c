#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 15

typedef struct Node {
    char name[MAX_NAME_LEN + 1];
    int *projects;
    int projectCount;
    int height;
    struct Node *left, *right;
} Node;

Node *createNode(const char *name, int project) {
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->projects = (int *)malloc(sizeof(int));
    node->projects[0] = project;
    node->projectCount = 1;
    node->height = 1;
    node->left = node->right = NULL;
    return node;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node *node) {
    return node ? node->height : 0;
}

int getBalance(Node *node) {
    return node ? height(node->left) - height(node->right) : 0;
}

Node *rotateRight(Node *y) {
    Node *x = y->left;
    Node *T = x->right;

    x->right = y;
    y->left = T;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *rotateLeft(Node *x) {
    Node *y = x->right;
    Node *T = y->left;

    y->left = x;
    x->right = T;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node *insert(Node *node, const char *name, int project) {
    if (!node) return createNode(name, project);

    if (strcmp(name, node->name) < 0)
        node->left = insert(node->left, name, project);
    else if (strcmp(name, node->name) > 0)
        node->right = insert(node->right, name, project);
    else {
        node->projects = realloc(node->projects, (node->projectCount + 1) * sizeof(int));
        node->projects[node->projectCount++] = project;
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && strcmp(name, node->left->name) < 0)
        return rotateRight(node);

    if (balance < -1 && strcmp(name, node->right->name) > 0)
        return rotateLeft(node);

    if (balance > 1 && strcmp(name, node->left->name) > 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && strcmp(name, node->right->name) < 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

Node *search(Node *node, const char *name) {
    if (!node || strcmp(name, node->name) == 0)
        return node;

    if (strcmp(name, node->name) < 0)
        return search(node->left, name);

    return search(node->right, name);
}

void printProjects(Node *node) {
    if (node) {
        printf("%d", node->height);
        for (int i = 0; i < node->projectCount; i++)
            printf(" %d", node->projects[i]);
        printf("\n");
    } else {
        printf("0\n");
    }
}

void freeTree(Node *node) {
    if (node) {
        freeTree(node->left);
        freeTree(node->right);
        free(node->projects);
        free(node);
    }
}

int main() {
    Node *root = NULL;
    int operation;

    while (scanf("%d", &operation) && operation != 0) {
        if (operation == 1) {
            char name[MAX_NAME_LEN + 1];
            int project;
            scanf("%s %d", name, &project);
            root = insert(root, name, project);
        } else if (operation == 2) {
            char name[MAX_NAME_LEN + 1];
            scanf("%s", name);
            Node *node = search(root, name);
            printProjects(node);
        }
    }

    freeTree(root);
    return 0;
}
