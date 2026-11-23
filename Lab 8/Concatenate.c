#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

struct Node* concatenateLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    struct Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int n1, n2, val, i;

    printf("Enter number of elements for List 1: ");
    scanf("%d", &n1);
    for (i = 0; i < n1; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        insertEnd(&list1, val);
    }

    printf("Enter number of elements for List 2: ");
    scanf("%d", &n2);
    for (i = 0; i < n2; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        insertEnd(&list2, val);
    }

    printf("List 1: ");
    display(list1);
    printf("List 2: ");
    display(list2);

    list1 = concatenateLists(list1, list2);

    printf("Concatenated List: ");
    display(list1);

    return 0;
}
