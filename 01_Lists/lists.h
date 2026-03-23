#ifndef LISTS_H
#define LISTS_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct DNode {
    int data;
    int val;
    struct DNode *next;
    struct DNode *prev;
} DNode;

void insertHead(Node **head, int val);
void printList(Node *head);
void freeSList(Node *head);
int pop(Node **head);

void insertHeadD(DNode **head, int val);
void printListD(DNode *head);
void freeDList(DNode *head);

void clearBuffer();

#endif