#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
void insertHeadD(DNode **head, int val) {
    DNode *newNode = malloc(sizeof(DNode));
    if (!newNode) return;
    newNode->data = val;
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head != NULL) {
        (*head)->prev = newNode;
=======
typedef struct DNode {
    void *data;
    struct DNode *next;
    struct DNode *prev;
} DNode;

typedef struct TDList {
    DNode *head;
    int len;
} TDList;

void init(TDList **list) {
    *list = (TDList *)malloc(sizeof(TDList));
    if (*list != NULL) {
        (*list)->head = NULL;
        (*list)->len = 0;
    }
}

int add(TDList *list, int n, void *data) {
    if (list == NULL || n < 0 || n > list->len)
        return -1;

    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    if (!newNode)
        return -1;
    
    newNode->data = data;

    if (n == 0) {
        newNode->next = list->head;
        newNode->prev = NULL;
        if (list->head != NULL) {
            list->head->prev = newNode;
        }
        list->head = newNode;
    } else {
        DNode *curr = list->head;
        for (int i = 0; i < n - 1; i++) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        newNode->prev = curr;
        
        if (curr->next != NULL) {
            curr->next->prev = newNode;
        }
        curr->next = newNode;
>>>>>>> 80e766995f5aab8dc58a5d766687ccdc9a57e6da
    }
    
    list->len++;
    return 1;
}

<<<<<<< HEAD
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
=======
DNode *delete(TDList *list, int n) {
    if (list == NULL || list->head == NULL || n < 0 || n >= list->len)
        return NULL;

    DNode *removed = NULL;
    
    if (n == 0) {
        removed = list->head;
        list->head = list->head->next;
        if (list->head != NULL) {
            list->head->prev = NULL;
        }
    } else {
        DNode *curr = list->head;
        for (int i = 0; i < n - 1; i++) {
            curr = curr->next;
        }
        removed = curr->next;
        curr->next = removed->next;
        
        if (removed->next != NULL) {
            removed->next->prev = curr;
        }
    }
    
    list->len--;
    return removed;
}

int length(TDList *list) {
    if (list)
        return list->len;
    else
        return 0;
}

void print_int_list(TDList *list) {
    DNode *curr = list->head;
    while (curr) {
        printf("%d <-> ", *(int *)(curr->data));
        curr = curr->next;
    }
    printf("NULL\n");
}

void print_string_list(TDList *list) {
    DNode *curr = list->head;
    while (curr) {
        printf("%s <-> ", (char *)(curr->data));
        curr = curr->next;
    }
    printf("NULL\n");
}

void free_list(TDList **list) {
    if (!list || !*list)
        return;
    DNode *curr = (*list)->head;
    while (curr) {
        DNode *aux = curr;
        curr = curr->next;
        free(aux);
    }
    free(*list);
    *list = NULL;
}

int main() {
    TDList *list;
    init(&list);

    int a = 10, b = 20, c = 30;
    add(list, 0, &a);
    add(list, 1, &c);
    add(list, 1, &b);

    print_int_list(list);

    DNode *removed = delete(list, 1);
    if (removed != NULL) {
        free(removed);
>>>>>>> 80e766995f5aab8dc58a5d766687ccdc9a57e6da
    }
}

<<<<<<< HEAD
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
=======
    print_int_list(list);
    free_list(&list);

    init(&list);

    add(list, 0, "Laborator");
    add(list, 1, "SDA");

    print_string_list(list);
    
    free_list(&list);

    return 0;
}
>>>>>>> 80e766995f5aab8dc58a5d766687ccdc9a57e6da
