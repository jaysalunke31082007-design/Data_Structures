#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create() {
    struct node *head = NULL, *temp, *newnode;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

void display(struct node *head) {
    struct node *temp = head;

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sort(struct node *head) {
    struct node *p, *q;
    int t;

    for(p = head; p != NULL; p = p->next) {
        for(q = p->next; q != NULL; q = q->next) {
            if(p->data > q->data) {
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
        }
    }
}

struct node* reverse(struct node *head) {
    struct node *prev = NULL, *current = head, *nextnode;

    while(current != NULL) {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }

    return prev;
}

struct node* concatenate(struct node *head1, struct node *head2) {
    struct node *temp;

    if(head1 == NULL)
        return head2;

    temp = head1;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head2;

    return head1;
}

int main() {
    struct node *head1, *head2;

    printf("Create First Linked List\n");
    head1 = create();

    printf("Create Second Linked List\n");
    head2 = create();

    printf("\nFirst Linked List:\n");
    display(head1);

    sort(head1);
    printf("\nAfter Sorting:\n");
    display(head1);

    head1 = reverse(head1);
    printf("\nAfter Reversing:\n");
    display(head1);

    head1 = concatenate(head1, head2);
    printf("\nAfter Concatenation:\n");
    display(head1);

    return 0;
}
