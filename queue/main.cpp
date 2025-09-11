#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node *front, *rear;
};

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("%d enqueued to queue\n", data);
}
// 10 20 30
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1; // Or any value indicating an error
    }
    Node* temp = queue->front; //temp is receiving to where top points
    int dequeued = temp->data;
    queue->front = temp->next;
    // If front becomes NULL, then the queue is empty
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp); //losing the popped item
    return dequeued;
}

// Function to get the top element of the stack without popping
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1; // Or any value indicating an error
    }
    return queue->front->data;
}

int main() {
    Queue* queue = createQueue();
    if (queue == NULL) {
        printf("Not possible to create the queue");
        return 1;
    }
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("%d dequeued from queue\n", dequeue(queue));

    printf("Front element is %d\n", peek(queue));

    return 0;
}