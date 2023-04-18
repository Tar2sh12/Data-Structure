#ifndef QLINK_H_INCLUDED
#define QLINK_H_INCLUDED
typedef int QueueEntry;

typedef struct queueNode
{
    QueueEntry entry;
    struct queueNode * next;
} QueueNode;

typedef struct queue
{
    QueueNode * frontt;
    QueueNode * rear;
    int sizee;
}Queue;

void CreateQueue(Queue * pq);
int QueueEmpty(Queue * pq);
int QueueFull(Queue * pq);
void Enqueue(QueueEntry e, Queue * pq);
void Dequeue(QueueEntry * pe, Queue * pq);
void TraverseQueue(Queue *pq, void (*pf)(QueueEntry));
//=============================================
int firstElement(Queue *pq);
int lastElement(Queue *pq);
int sizeOfQueue(Queue *pq);
void printQueue(Queue *pq);
void destroyQueue(Queue *pq);
void copyQueue(Queue *pq,Queue *pq2);
//====================================
void popMax(Queue *pq,int *m);


#endif // QLINK_H_INCLUDED
