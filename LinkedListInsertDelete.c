#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int roll;
    char name[100];
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int roll, char name[]) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

// Insert at specific position
void insertAtPosition(int roll, char name[], int position) {
    struct Node* newNode = createNode(roll, name);

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete a node by roll number
void deleteByRoll(int roll) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    // If the head node is to be deleted
    if (head->roll == roll) {
        head = head->next;
        free(temp);
        printf("Node with roll %d deleted.\n", roll);
        return;
    }

    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Roll number %d not found in list.\n", roll);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node with roll %d deleted.\n", roll);
}

void printList() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("\nLinked List:\n");
    while (temp != NULL) {
        printf("Roll: %d, Name: %s\n", temp->roll, temp->name);
        temp = temp->next;
    }
}

int main() {
    int choice, roll, position;
    char name[100];

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert node\n");
        printf("2. Delete node by roll\n");
        printf("3. Print list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter roll: ");
                scanf("%d", &roll);
                printf("Enter name: ");
                scanf(" %[^\n]", name); 
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtPosition(roll, name, position);
                break;

            case 2:
                printf("Enter roll number to delete: ");
                scanf("%d", &roll);
                deleteByRoll(roll);
                break;

            case 3:
                printList();
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
