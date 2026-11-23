#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) { printf("Memory allocation failed!\n"); exit(1); }
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void appendNode(int data) {
    struct Node* newNode = createNode(data);
    if (!head) { head = newNode; return; }
    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertLeft(int targetValue, int newData) {
    if (!head) { printf("List is empty.\n"); return; }
    struct Node* temp = head;
    while (temp && temp->data != targetValue) temp = temp->next;
    if (!temp) { printf("Target %d not found.\n", targetValue); return; }

    struct Node* newNode = createNode(newData);
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (!temp->prev) head = newNode;
    else temp->prev->next = newNode;
    temp->prev = newNode;
}

void deleteByValue(int value) {
    if (!head) { printf("List is empty.\n"); return; }
    struct Node* temp = head;
    while (temp && temp->data != value) temp = temp->next;
    if (!temp) { printf("Value %d not found.\n", value); return; }

    if (temp == head) head = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    if (temp->prev) temp->prev->next = temp->next;
    free(temp);
}

void displayList() {
    struct Node* temp = head;
    printf("NULL <-> ");
    while (temp) { printf("%d <-> ", temp->data); temp = temp->next; }
    printf("NULL\n");
}

int main() {
    int choice, n, data, target;
    while (1) {
        printf("\n1. Create\n2. Insert Left\n3. Delete\n4. Display\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Count: "); scanf("%d", &n);
                for (int i = 0; i < n; i++) { scanf("%d", &data); appendNode(data); }
                break;
            case 2:
                printf("Target & New Data: "); scanf("%d %d", &target, &data);
                insertLeft(target, data);
                break;
            case 3:
                printf("Delete Value: "); scanf("%d", &data);
                deleteByValue(data);
                break;
            case 4: displayList(); break;
            case 5: exit(0);
        }
    }
}
