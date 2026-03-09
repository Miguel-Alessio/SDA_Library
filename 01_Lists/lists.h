#ifndef LISTS_H
#define LISTS_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct DNode {
    int data;
    struct DNode *next;
    struct DNode *prev;
} DNode;

Node* createNode(int val);
void insertHead(Node** head, int val);
void printList(Node* head);

DNode* createDNode(int val);
void insertHeadD(DNode** head, int val);
void printListD(DNode* head);

#endif