#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    int count = 0;
    while (current->next != NULL && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current->next == NULL) {
        current->next = newNode;
    } else {
        newNode->next = current->next;
        current->next = newNode;
    }
}


void deleteAtPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position == 0) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node* current = *head;
    int count = 0;
    while (current->next != NULL && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current->next == NULL) {
        printf("Position out of range\n");
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}


int countNodes(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}


void traverse(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int choice, data, position;
    printf("the traversed linked list");
    traverse(head);
    printf("number of nodes");
    printf("%d\n", countNodes(head));

    // while (1) {
    //     printf("1. Insert at position\n");
    //     printf("2. Delete at position\n");
    //     printf("3. Count nodes\n");
    //     printf("4. Traverse\n");
    //     printf("5. Exit\n");
    //     printf("Enter your choice: ");
    //     scanf("%d", &choice);

    //     switch (choice) {
    //         case 1:
    //             printf("Enter data: ");
    //             scanf("%d", &data);
    //             printf("Enter position: ");
    //             scanf("%d", &position);
    //             insertAtPosition(&head, data, position);
    //             break;
    //         case 2:
    //             printf("Enter position: ");
    //             scanf("%d", &position);
    //             deleteAtPosition(&head, position);
    //             break;
    //         case 3:
    //             printf("Number of nodes: %d\n", countNodes(head));
    //             break;
    //         case 4:
    //             traverse(head);
    //             break;
    //         case 5:
    //             exit(0);
    //         default:
    //             printf("Invalid choice\n");
    //     }
    // }

    return 0;
}