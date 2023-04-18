#include "queue.h"
void CreateQueue(Queue * pq){
    pq->frontt=0;
    pq->rear=-1;
    pq->sizee=0;
}
void Enqueue(QueueEntry e, Queue * pq){
    pq->rear=(pq->rear+1)%MaxQueue;
    pq->entry[pq->rear]=e;
    pq->sizee++;
}

void Dequeue(QueueEntry *pe, Queue * pq){
    *pe = pq->entry[pq->frontt];
    pq->frontt = (pq->frontt+1)%MaxQueue;
    pq->sizee--;
}




int QueueEmpty(Queue * pq){
    return !pq->sizee;
}



int QueueFull(Queue * pq){
    return (pq->sizee == MaxQueue);
}

void TraverseQueue(Queue *pq, void (*pf)(QueueEntry)){
    int i=pq->frontt  ,s;
    for( s=0 ; s<pq->sizee ;s++){
        (*pf)(pq->entry[i]);
        i=(i+1)%MaxQueue;
    }
}


void TraverseQueueReverse(Queue *pq, void (*pf)(QueueEntry)){
    int i=pq->rear;
    int c=0;
    while(c< pq->sizee){
        (*pf)(pq->entry[i]);
        i=(i-1)%MaxQueue;
        c++;
    }
}


void reverseQueue(Queue *pq){
    int i= pq->frontt;
    int j= pq->rear;
    int c=0;
    QueueEntry temp;
    while(c<pq->sizee/2){
        temp = pq->entry[i];
        pq->entry[i] = pq->entry[j];
        pq->entry[j] = temp;
        i=(i+1)%MaxQueue;
        j=(j-1)%MaxQueue;
        c++;
    }
}
void RemoveEven(Queue * pq)
{
    int i=pq->frontt;
    int c=0;
    int j,even=0,flag=0;
    while(c<pq->sizee){
        if(pq->entry[i]%2==0){
            even++;
            if(flag ==0 ){
                j=i;
                flag=1;
            }
        }
        else if(flag == 1){
            pq->entry[j]=pq->entry[i];
            j=(j+1)%MaxQueue;
        }
        i=(i+1)%MaxQueue;
        c++;
    }
    pq->sizee = pq->sizee - even;
    pq->rear = (pq->rear - even)%MaxQueue;
}



int firstElement(Queue *pq){
    return pq->entry[pq->frontt];
}

int lastElement(Queue *pq){
    return pq->entry[pq->rear];
}

int Queuesize(Queue * pq){
    return pq->sizee;
}

void destroyQueue(Queue * pq){
    pq->frontt=0;
    pq->rear=-1;
    pq->sizee=0;
}


void printQueueee(Queue *pq){
    int i=pq->frontt;
    int c=0;
    while(c<pq->sizee){
        printf("imp level = %d\n",pq->entry[i]);
        i=(i+1)%MaxQueue;
        c++;
    }
}


void CopyQueue(Queue * pq1, Queue * pq2){
    int i=pq1->frontt;
    int c=0;
    while(c<pq1->sizee){
        pq2->entry[i]=pq1->entry[i];
        i=(i+1)%MaxQueue;
        c++;
    }
    pq2->frontt=pq1->frontt;
    pq2->rear=pq1->rear;
    pq2->sizee=pq1->sizee;
}




void popMax(Queue *pq,QueueEntry *pe){
    int i=pq->frontt;
    int c=0;
    int max=pq->entry[pq->frontt];
    int maxi=0;
    while(c<pq->sizee){
        if(max<pq->entry[i]){
            max=pq->entry[i];
            maxi=c;
        }
        c++;
        i=(i+1)%MaxQueue;
    }
    *pe=max;
    c=maxi;
    i=maxi;
    while(c<pq->sizee-1){
        pq->entry[i]=pq->entry[(i+1)%MaxQueue];
        i=(i+1)%MaxQueue;
        c++;
    }
    pq->sizee = pq->sizee - 1;
    pq->rear = (pq->rear - 1)%MaxQueue;
}
