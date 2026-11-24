#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;
struct node *front = NULL;
struct node *rear = NULL;

void push(int item) {
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = top;
    top = newnode;

    printf("%d pushed into stack\n", item);
}

void pop() {
    struct node *temp;

    if(top == NULL) {
        printf("Stack Underflow\n");
    } else {
        temp = top;
        printf("Popped element: %d\n", temp->data);
        top = top->next;
        free(temp);
    }
}

void stack_display() {
    struct node *temp = top;

    if(top == NULL) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void enqueue(int item) {
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;

    if(front == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("%d inserted into queue\n", item);
}

void dequeue() {
    struct node *temp;

    if(front == NULL) {
        printf("Queue Underflow\n");
    } else {
        temp = front;
        printf("Deleted element: %d\n", temp->data);

        front = front->next;

        if(front == NULL) {
            rear = NULL;
        }

        free(temp);
    }
}

void queue_display() {
    struct node *temp = front;

    if(front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {

    printf("STACK OPERATIONS\n");

    push(10);
    push(20);
    push(30);

    stack_display();

    pop();

    stack_display();

    printf("\nQUEUE OPERATIONS\n");

    enqueue(10);
    enqueue(20);
    enqueue(30);

    queue_display();

    dequeue();

    queue_display();

    return 0;
}
