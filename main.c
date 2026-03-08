
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Eroare: Nu s-a putut aloca memorie.\n");
        return NULL;
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void push(int val, Node **top_ref)
{
    Node *newNode = createNode(val);
    newNode->next = *top_ref;
    *top_ref = newNode;
}

int pop(Node **top_ref)
{
    if (*top_ref == NULL)
    {
        printf("Stack Underflow! Nothing to pop.\n");
        return -1;
    }
    Node *temp = *top_ref;
    int poppedValue = temp->data;
    *top_ref = (*top_ref)->next;
    free(temp);
    return poppedValue;
}

int peek(Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data;
}

void printStack(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("[%d] -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{

    Node *stack = NULL;
    int choice=0, val;

    printf("--- SDA Library: Stack Project ---\n");
    printf("Enter numbers to push (any non-number to stop ---)\n");
    while (scanf("%d", &val) == 1)
    {
        push(val, &stack);
    }
    // This clears the input buffer
while (getchar() != '\n');
    printStack(stack);

    printf("Do you want to pop any number?\nIf yes write how many, if not than just type '0':");
    scanf("%d", &choice);

    
    if(choice<0){
        printf("Only positive numbers: \n");
        scanf("%d",&choice);
    }
    
    if(choice==0){
        return 0;
    }

    if (choice > 0)
    {
        while (choice>0)
        {
            printf("\nPeeking at the top: %d\n", peek(stack));

            printf("Popping the top element: %d\n", pop(&stack));
            choice--;

        }
    }


    printStack(stack);

    return 0;
}
