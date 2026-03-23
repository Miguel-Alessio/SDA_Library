#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

void insertHeadD(DNode **head, int val) {
    DNode *newNode = malloc(sizeof(DNode));
    if (!newNode) return;
    newNode->data = val;
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void printListD(DNode *head) {
    DNode *temp = head;
    while (temp) {
        printf("[%d] <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeDList(DNode *head) {
    while (head) {
        DNode *temp = head;
        head = head->next;
        free(temp);
    }
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}