#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define MaxQueue 10

typedef int QueueEntry;

typedef struct
{
    QueueEntry entry[MaxQueue];
    int frontt;
    int rear;
    int sizee;
}Queue;

void CreateQueue(Queue * pq);
void Enqueue(QueueEntry e, Queue * pq);
void Dequeue(QueueEntry *pe, Queue * pq);
int QueueEmpty(Queue * pq);
int QueueFull(Queue * pq);
void TraverseQueue(Queue *pq, void (*pf)(QueueEntry));



//==========================================================

void TraverseQueueReverse(Queue *pq, void (*pf)(QueueEntry));
void reverseQueue(Queue *pq);
void RemoveEven(Queue * pq);
void popMax(Queue *pq,QueueEntry *pe);

//sheet=====================================================
void CopyQueue(Queue * pq1, Queue * pq2);
int firstElement(Queue *pq);
int lastElement(Queue *pq);
int Queuesize(Queue * pq);
void destroyQueue(Queue * pq);
void printQueueee(Queue *pq);

#endif // QUEUE_H_INCLUDED
