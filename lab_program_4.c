#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int items[SIZE];
int front = -1;
int rear = -1;

int isFull()
{
    return (front == rear + 1) || (front == 0 && rear == SIZE - 1);
}

int isEmpty()
{
    return front == -1;
}

void enQueue(int element)
{
    if (isFull())
    {
        printf("Queue is full\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % SIZE;
    items[rear] = element;
}

void deQueue()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Deleted element: %d\n", items[front]);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

void display()
{
    int i;

    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }

    i = front;

    while (i != rear)
    {
        printf("%d ", items[i]);
        i = (i + 1) % SIZE;
    }

    printf("%d\n", items[rear]);
}

int main()
{
    int choice, element;

    while (1)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter element: ");
            scanf("%d", &element);
            enQueue(element);
        }
        else if (choice == 2)
        {
            deQueue();
        }
        else if (choice == 3)
        {
            display();
        }
        else if (choice == 4)
        {
            exit(0);
        }
        else
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
