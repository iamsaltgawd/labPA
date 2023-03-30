#include "stive.h"

typedef struct {
    Node *front, *rear;
} Queue;

Queue* createQueue();

void enQueue(Queue*q, Data v);
 
Data deQueue(Queue*q);

int isEmptyQ(Queue*q);

void deleteQueue(Queue*q);

void reverse();