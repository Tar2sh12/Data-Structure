#include <stdio.h>
#include <stdlib.h>
#include "qlink.h"
void printq(QueueEntry e){
    printf("tra = %d\n",e);
}
int sizeo(Queue *q){
    int c=0;
    QueueEntry e;
    Queue q3;
    CreateQueue(&q3);
    while(!QueueEmpty(q)){
        Dequeue(&e,q);
        c++;
        Enqueue(e,&q3);
    }
    while(!QueueEmpty(&q3)){
        Dequeue(&e,&q3);
        Enqueue(e,q);
    }
    return c;
}

void destroy(Queue *q){
    QueueEntry e;
    while(!QueueEmpty(q)){
        Dequeue(&e,q);
    }
}

int larst(Queue *q){
    int l;
    QueueEntry e;
    Queue q3;
    CreateQueue(&q3);
    while(!QueueEmpty(q)){
        Dequeue(&e,q);
        l=e;
        Enqueue(e,&q3);
    }
    while(!QueueEmpty(&q3)){
        Dequeue(&e,&q3);
        Enqueue(e,q);
    }
    return l;
}


void printqq(Queue *q){
    QueueEntry e;
    Queue q3;
    CreateQueue(&q3);
    while(!QueueEmpty(q)){
        Dequeue(&e,q);
        Enqueue(e,&q3);
        printf("queue elements in function = %d\n",e);
    }
    while(!QueueEmpty(&q3)){
        Dequeue(&e,&q3);
        Enqueue(e,q);
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




    Enqueue(7,&q);
    Enqueue(1,&q);
    Enqueue(2,&q);
    Enqueue(3,&q);
    Enqueue(4,&q);
    Enqueue(5,&q);
    Enqueue(6,&q);

    copyQp(&q,&q2);


    int x;
    popMax(&q,&x);
    printf("first element in the queue = %d\n",firstElement(&q));
    printf("last element in the queue = %d\n",lastElement(&q));
    printf("size of queue = %d\n",sizeOfQueue(&q));
    printQueue(&q);
    printf("max no. in the stack = %d\n",x);




    //destroyQueue(&q);

    //printqq(&q);
    //TraverseQueue(&q,&printq);

    return 0;
}
