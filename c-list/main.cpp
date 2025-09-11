#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    Node *next;
    Node *prev;
};

struct List {
    Node *head;
    Node *tail;
};

List* createList() {
    List* list = (List*) malloc(sizeof(List));
    if (list == NULL) {
        printf("Not possible to create a list");
    }
    return list;
}

int isEmpty(List* list) {
    return list->head == NULL;
}

Node* createNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    if (node == NULL) {
        printf("Not possible to create a node");
    }
    node->data = data;
    return node;
}

Node* lastNode(List* list) {
    if (list->head == NULL) {
        return list->head;
    }
    return list->tail;
}

void append(List* list, int data) {
    Node* node = createNode(data);
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        Node* last = lastNode(list);
        last->next = node;
        list->tail = node;
    }
}

void insert(List* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        if (list->tail->data <= data) {
            list->tail->next = newNode;
        } else {
            Node* currentNode = list->head;
            Node* previousNode;
            while (currentNode != NULL) {
                if (currentNode->data >= data) {
                    break;
                }
                previousNode = currentNode;
                currentNode = currentNode->next;
            }
            newNode->next = currentNode;
            previousNode->next = newNode;
        }
    }
}

void removeFirst(List* list) {
    if (list->head != NULL) {
        Node* toBeRemoved = list->head;
        list->head = list->head->next;
        free(toBeRemoved);
    }
}

void printForward(List* list) {
    Node* node = list->head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    List* list = createList();
    append(list, 10);
    append(list, 20);
    append(list, 30);
    printForward(list);
    removeFirst(list);
    printForward(list);
    insert(list, 25);
    printForward(list);
    insert(list, 29);
    printForward(list);
    insert(list, 40);
    printForward(list);
    return 0;
}
