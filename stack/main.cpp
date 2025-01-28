#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top;
};

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed to stack\n", data);
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1; // Or any value indicating an error
    }
    Node* temp = stack->top; //temp is receiving to where top points
    int popped = temp->data;
    stack->top = temp->next;
    free(temp); //losing the popped item
    return popped;
}

// Function to get the top element of the stack without popping
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1; // Or any value indicating an error
    }
    return stack->top->data;
}

int main() {
    Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("%d popped from stack\n", pop(stack));

    printf("Top element is %d\n", peek(stack));

    return 0;
}