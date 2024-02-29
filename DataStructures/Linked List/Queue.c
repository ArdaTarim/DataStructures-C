#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *head;
    Node *tail;
    int size;
} Queue;


Queue *createQueue();
int size (Queue *q);
bool isEmpty(Queue *q);
int peek(Queue *q, bool *status);
void enqueue(Queue *q, int value);
int dequeue(Queue *q, bool status);
void destroyQueue(Queue *q);

int main()
{
    Queue *q = createQueue();
    bool status;
    int value = 0;

    if(isEmpty(q)) {
        printf("q is empty\n");
    } else 
    {
        printf("q is not empty\n");
    }

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    printf("size of q is %d\n", size(q));

    value = peek(q, &status);

    printf("value is %d \n", value);
    printf("size of q is %d\n", size(q));

    if(isEmpty(q)) {
        printf("q is empty\n");
    } else 
    {
        printf("q is not empty\n");
    }

    return 0;
}

Queue *createQueue()
{
   Queue *q = (Queue *)malloc(sizeof(Queue));
   q->head = NULL;
   q->tail = NULL;
   q->size = 0;

   return q;
}

int size(Queue *q)
{
    return q->size;
}

bool isEmpty(Queue *q)
{
    return (q->size == 0);
}

int peek(Queue *q, bool *status)
{
    if(isEmpty(q))
    {
        *status = false;
    } 

    *status = true;
    return q->head->value;
}

void enqueue(Queue *q, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->value = value;
    newNode->next = NULL;

    if (isEmpty(q))
    {
        q->head = newNode;
        q->tail = newNode;
    } else 
    {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    
    q->size++;

}

int dequeue(Queue *q, bool *status)
{
    if(isEmpty(q))
    {
        *status = false;
        return NULL;
    }

    *status = true;

    int temp = q->head->value;
    Node *oldHead = q->head;

    if(q->size == 1)
    {
        q->head = NULL;
        q->tail = NULL;
    } else 
    {
        q->head = q->head->next;
    }

    free(oldHead);
    q->size--;

    return temp;
}

void destroyQueue(Queue *q)
{
    Node *current = q->head;

    while (current != NULL)
    {
        Node *temp =current;
        current = current->next;
        free(temp);
    }

    free(q);
}
