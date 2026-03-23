#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* This is the manager that remembers both ends */
typedef struct {
    Node *front;
    Node *rear;
} Queue;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return NULL;
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Queue *q, int val) {
    Node *newNode = createNode(val);
    
    /* If the line is empty, the new person is both the front and the back */
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    /* Direct link: no more walking the whole list! */
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(Queue *q) {
    if (q->front == NULL) return -1;

    Node *temp = q->front;
    int val = temp->data;

    q->front = q->front->next;

    /* If we just removed the last person, the back is now empty too */
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return val;
}

void printQueue(Queue *q) {
    Node *temp = q->front;
    if (!temp) {
        printf("Empty\n");
        return;
    }
    while (temp) {
        printf("[%d] ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    /* Initialize an empty queue manager */
    Queue q = {NULL, NULL};
    int choice, val;

    while (1) {
        printf("\n--- Optimized Queue (O(1) Enqueue) ---\n");
        printf("1. Enqueue\n2. Dequeue\n0. Exit\nSelection: ");
        if (scanf("%d", &choice) != 1 || choice == 0) break;

        if (choice == 1) {
            printf("Value: ");
            scanf("%d", &val);
            enqueue(&q, val);
        } else if (choice == 2) {
            val = dequeue(&q);
            if (val == -1) printf("Nothing to dequeue!\n");
            else printf("Served: %d\n", val);
        }
        
        printf("Current Queue: ");
        printQueue(&q);
    }

    return 0;
}