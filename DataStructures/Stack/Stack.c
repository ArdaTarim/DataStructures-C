#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack
{
    int *collection;
    int capacity;
    int size;

} Stack;

Stack *createStack(int capacity);
void destroyStack(Stack *s);
bool isFull(Stack *s);
bool isEmpty(Stack *s);
bool pop(Stack *s, int *item);
bool push(Stack *s, int item);
bool peek(Stack *s, int *item);

int main()
{

    return 0;
}

Stack createStack(int cap)
{
    if (cap <= 0)
    {
        return NULL;
    }

    Stack *s = malloc(sizeof(Stack));

    if (s == NULL)
    {
        return NULL;
    }

    Stack->collection = malloc(sizeof(int) * cap);

    if (Stack->collection == NULL)
    {
        free(s);
        return NULL;
    }

    s->capacity = cap;
    s->size = 0;

    return s;
}

void destroyStack(Stack *s)
{
    free(s->collection);
    free(s);
}

bool isFull(Stack *s)
{
    return s->size == s->capacity;
}

bool isEmpty(Stack *s)
{
    return s->size == 0;
}

bool pop(Stack *s, int *item)
{
    if (isEmpty(s))
    {
        return false;
    }

    *item = s->collection[s->size - 1];
    s->size--;

    return true;
}

bool peek(Stack *s, int *item)
{
    if (isEmpty(s))
    {
        return false;
    }

    *item = s->collection[s->size - 1];
    
    return true;
}
bool push(Stack *s, int item)
{
    if (isFull(s))
    {
        return false;
    }

    s->collection[stack->size] = item;
    s->size++;

    return true;
}