#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return NULL;
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertHead(Node** head, int val) {
    Node* newNode = createNode(val);
    if (newNode == NULL) return;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("[%d] -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}