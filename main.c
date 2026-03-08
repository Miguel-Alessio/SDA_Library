
#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNote(int val){
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        printf("Eroare: Nu s-a putut aloca memorie.\n");
        return NULL;
    }
    newNode -> data = val;
    newNode -> next = NULL;
    return newNode;
}

void insertAtHead(int val,Node** head_ref){
    Node* newNode=createNote(val);
    newNode -> next=*head_ref;
    *head_ref=newNode;
}

void printList(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){

    Node* head=NULL;
    insertAtHead(30,&head);
    insertAtHead(20,&head);
    insertAtHead(10,&head);

    printList(head);
    return 0;
}
