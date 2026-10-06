#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int queue_array[MAX];
int rear = -1;
int front = -1;

void insert()
{
    int add_item;

    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    printf("Insert the element in queue: ");
    scanf("%d", &add_item);

    rear = rear + 1;
    queue_array[rear] = add_item;
}

void delete()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Element deleted from queue is: %d\n", queue_array[front]);
    front = front + 1;
}

void display()
{
    int i;

    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue is:\n");

    for (i = front; i <= rear; i++)
        printf("%d ", queue_array[i]);

    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Wrong choice\n");
        }
    }

    return 0;
}
