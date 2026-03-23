#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct TList {
    Node *head;
    int len;
} TList;

void init(TList **list) {
    *list = (TList *)malloc(sizeof(TList));
    if (*list != NULL) {
        (*list)->head = NULL;
        (*list)->len = 0;
    }
}

int insertHead(TList *list, void *data) {
    if (list == NULL) return -1;

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) return -1;
    
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->len++;
    
    return 1;
}

Node *pop(TList *list) {
    if (list == NULL || list->head == NULL) return NULL;

    Node *temp = list->head;
    list->head = list->head->next;
    list->len--;
    
    return temp;
}

void print_int_list(TList *list) {
    if (list == NULL) return;
    
    Node *temp = list->head;
    while (temp != NULL) {
        printf("[%d] -> ", *(int *)(temp->data));
        temp = temp->next;
    }
    printf("NULL\n");
}

<<<<<<< HEAD
int pop(Node** head) {
    if (*head == NULL) return -1;
    Node* temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    free(temp);
    return data;
}

void freeSList(Node *head) {
    while (head) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
=======
void free_list(TList **list) {
    if (!list || !*list) return;
    
    Node *curr = (*list)->head;
    while (curr) {
        Node *aux = curr;
        curr = curr->next;
        free(aux);
    }
    
    free(*list);
    *list = NULL;
}

int main() {
    TList *list;
    init(&list);

    int a = 10, b = 20, c = 30;
    
    insertHead(list, &a);
    insertHead(list, &b);
    insertHead(list, &c);

    print_int_list(list);

    Node *removed = pop(list);
    if (removed != NULL) {
        free(removed);
    }

    print_int_list(list);

    free_list(&list);

    return 0;
>>>>>>> 80e766995f5aab8dc58a5d766687ccdc9a57e6da
}
