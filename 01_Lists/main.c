#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

void option_choose1(int opt1) {
    if (opt1 != 0 && opt1 != 1) {
        printf("You need to choose between 0 and 1, if you type any other character we will consider that you dont want to proceed and the program will terminate\n");
        option_choose1(opt1);
        
    }

    int val;
    if (opt1 == 0) {
        Node *sList = NULL;
        printf("--- Singly Linked List ---\n");
        printf("Enter numbers (any letter to stop):\n");
        while (scanf("%d", &val) == 1) {
            insertHead(&sList, val);
        }
        clearBuffer();
        printf("Singly Linked List: ");
        printList(sList);
        freeSList(sList);
    } else {
        DNode *dList = NULL;
        printf("\n--- Doubly Linked List ---\n");
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
        freeDList(dList);
    }
}

int main() {
    int opt1 = -1;
    printf("Choose between Singly List or Doubly List ( 0 for Singly and 1 for Doubly): ");
    if (scanf("%d", &opt1) != 1) {
        return 0;
    }
    option_choose1(opt1);
    return 0;
}