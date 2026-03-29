#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return NULL;
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void push(Node **top, int val) {
    Node* newNode = createNode(val);
    if (newNode == NULL) return;
    newNode->next = *top;
    *top = newNode;
}

int pop(Node **top) {
    if (*top == NULL) return -1;
    Node *temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

void enqueue(Node **front, int val) {
    Node *newNode = createNode(val);
    if (*front == NULL) {
        *front = newNode;
        return;
    }
    Node *temp = *front;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int dequeue(Node **front) {
    if (*front == NULL) return -1;
    Node *temp = *front;
    int val = temp->data;
    *front = (*front)->next;
    free(temp);
    return val;
}

void printList(Node *head) {
    if (!head) {
        printf("Empty\n");
        return;
    }
    while (head) {
        printf("[%d] -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node *stack = NULL;
    Node *queue = NULL;
    int choice, val;

    while (1) {
        printf("\n--- SDA Library: Module 02 ---\n");
        printf("1. Stack: Push\n");
        printf("2. Stack: Pop\n");
        printf("3. Queue: Enqueue\n");
        printf("4. Queue: Dequeue\n");
        printf("0. Exit\n");
        printf("Selection: ");
        
        if (scanf("%d", &choice) != 1) break;
        if (choice == 0) break;

        switch (choice) {
            case 1:
                printf("Value to push: ");
                scanf("%d", &val);
                push(&stack, val);
                printf("Stack: ");
                printList(stack);
                break;
            case 2:
                val = pop(&stack);
                if (val == -1) printf("Stack Underflow\n");
                else printf("Popped: %d\n", val);
                printf("Stack: ");
                printList(stack);
                break;
            case 3:
                printf("Value to enqueue: ");
                scanf("%d", &val);
                enqueue(&queue, val);
                printf("Queue: ");
                printList(queue);
                break;
            case 4:
                val = dequeue(&queue);
                if (val == -1) printf("Queue Empty\n");
                else printf("Dequeued: %d\n", val);
                printf("Queue: ");
                printList(queue);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}