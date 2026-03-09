#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

DNode* createDNode(int val) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    if (newNode == NULL) return NULL;
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertHeadD(DNode** head, int val) {
    DNode* newNode = createDNode(val);
    if (newNode == NULL) return;
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void printListD(DNode* head) {
    DNode* temp = head;
    printf("NULL <- ");
    while (temp != NULL) {
        printf("[%d]", temp->data);
        if (temp->next != NULL) printf(" <-> ");
        temp = temp->next;
    }
    printf(" -> NULL\n");
}