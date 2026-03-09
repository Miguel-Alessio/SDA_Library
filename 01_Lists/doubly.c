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

int popD(DNode** head){
    if(*head==NULL)return -1;

    DNode* temp=*head;

    if(temp->next==NULL){
        int val=temp->data;
        free(temp);
        *head=NULL;
        return val;
    }

    while(temp->next!=NULL){
        temp=temp->next;
    }

    int val=temp->data;

    temp->prev->next=NULL;
    free(temp);
    return val;
}