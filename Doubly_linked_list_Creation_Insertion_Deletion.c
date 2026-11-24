#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void create() {
    struct node *newnode, *temp;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->prev = NULL;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
        } else {
            temp = head;

            while(temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newnode;
            newnode->prev = temp;
        }
    }
}

void insert_left(int key, int item) {
    struct node *temp, *newnode;

    temp = head;

    while(temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Node not found\n");
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;

    newnode->next = temp;
    newnode->prev = temp->prev;

    if(temp->prev == NULL) {
        head = newnode;
    } else {
        temp->prev->next = newnode;
    }

    temp->prev = newnode;

    printf("Node inserted successfully\n");
}

void delete(int key) {
    struct node *temp = head;

    while(temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Node not found\n");
        return;
    }

    if(temp->prev == NULL) {
        head = temp->next;
    } else {
        temp->prev->next = temp->next;
    }

    if(temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);

    printf("Node deleted successfully\n");
}

void display() {
    struct node *temp = head;

    if(head == NULL) {
        printf("List is Empty\n");
        return;
    }

    printf("Doubly Linked List: ");

    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int key, item;

    printf("CREATE DOUBLY LINKED LIST\n");
    create();

    display();

    printf("\nEnter value of node: ");
    scanf("%d", &key);

    printf("Enter new value to insert: ");
    scanf("%d", &item);

    insert_left(key, item);
    display();

    printf("\nEnter value to delete: ");
    scanf("%d", &key);

    delete(key);
    display();

    return 0;
}
