#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

void clearBuffer() {
    while (getchar() != '\n');
}

int main() {
    Node *sList = NULL;
    DNode *dList = NULL;
    int val;

    printf("--- Part 1: Singly Linked List ---\n");
    printf("Enter numbers (any letter to stop):\n");
    while (scanf("%d", &val) == 1) {
        insertHead(&sList, val);
    }
    clearBuffer();

    printf("Singly Linked List: ");
    printList(sList);

    printf("\n--- Part 2: Doubly Linked List ---\n");
    printf("Enter numbers (any letter to stop):\n");
    while (scanf("%d", &val) == 1) {
        insertHeadD(&dList, val);
    }
    clearBuffer();

    printf("Doubly Linked List: ");
    printListD(dList);

    if (dList != NULL && dList->next != NULL) {
        printf("\nVerifying Double Links:\n");
        printf("Head: %d\n", dList->data);
        printf("Second Node: %d\n", dList->next->data);
        printf("Back to Head from Second: %d\n", dList->next->prev->data);
    }

    return 0;
}