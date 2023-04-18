#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void PrintQueue(QueueEntry e)
{
    printf("traverse = %d\n",e);
}

int sizeo(Queue q){
    int c=0;
    QueueEntry e;
    while(!QueueEmpty(&q)){
        Dequeue(&e,&q);
        c++;
    }
    return c;
}

void destroy(Queue *q){
    QueueEntry e;
    while(!QueueEmpty(q)){
        Dequeue(&e,q);
    }
}
int first(Queue q){
    int f;
    QueueEntry e;
    Dequeue(&e,&q);
    f=e;
    return f;
}
int larst(Queue q){
    int l;
    QueueEntry e;
    while(!QueueEmpty(&q)){
        Dequeue(&e,&q);
        l=e;
    }
    return l;
}


void printq(Queue q){
    QueueEntry e;
    while(!QueueEmpty(&q)){
        Dequeue(&e,&q);
        printf("queue elements in function = %d\n",e);
    }
}

void copyQ(Queue q,Queue *pq){
    QueueEntry e;
    while(!QueueEmpty(&q)){
        Dequeue(&e,&q);
        Enqueue(e,pq);
    }
}

void copyQp(Queue *q,Queue *pq){
    QueueEntry e;
    Queue q3;
    CreateQueue(&q3);
    while(!QueueEmpty(q)){
        Dequeue(&e,q);
        Enqueue(e,&q3);
    }
    while(!QueueEmpty(&q3)){
        Dequeue(&e,&q3);
        Enqueue(e,q);
        Enqueue(e,pq);
    }
}
int firstep(Queue *q){
    QueueEntry e;
    Queue q3;
    CreateQueue(&q3);
    int c=0;
    int f;
    while(!QueueEmpty(q)){
        if(c==0){
            Dequeue(&e,q);
            f=e;
            Enqueue(e,&q3);
            c=1;
        }
        else if(c==1){
            Dequeue(&e,q);
            Enqueue(e,&q3);
        }

    }
    while(!QueueEmpty(&q3)){
        Dequeue(&e,&q3);
        Enqueue(e,q);
    }
    return f;
}
int main()
{
    QueueEntry e;
    Queue q,q2;
    CreateQueue(&q);
    CreateQueue(&q2);



    Enqueue(1,&q);
    Enqueue(2,&q);
    Enqueue(7,&q);
    Enqueue(3,&q);
    Enqueue(4,&q);

    Enqueue(5,&q);
    Enqueue(6,&q);





    //TraverseQueue(&q,&PrintQueue);
    //TraverseQueueReverse(&q,&PrintQueue);
    //implementation level========================================
    //printf("first element in the queue = %d\n",firstElement(&q));
    //printf("last element in the queue = %d\n",lastElement(&q));
    //printf("size of array in emp level= %d\n",Queuesize(&q));
    //printQueueee(&q);
    //destroyQueue(&q);
    //CopyQueue(&q,&q2);

    //copyQ(q,&q2);
    //reverseQueue(&q);
    //RemoveEven(&q);
    //copyQp(&q,&q2);


    //printf("first element in the queue in user level = %d\n",firstep(&q));
    popMax(&q,&e);
    printf("last max = = %d\n",e);
    while(!QueueEmpty(&q)){
        Dequeue(&e,&q);
        printf("queue elements = %d\n",e);
    }



    //user level===================================================
    //destroy(&q);
    //printq(q);

    //printf("last element in the queue in user level = %d\n",larst(q));
    //printf("size of queue in user level = %d\n",sizeo(q));


    printf("Hello world!\n");
    return 0;
}
