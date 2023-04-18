#include "qlink.h"
#include <stdlib.h>

void CreateQueue(Queue * pq){
    pq->frontt=NULL;
    pq->rear=NULL;
    pq->sizee=0;
}
void Enqueue(QueueEntry e, Queue * pq){
    QueueNode *pn=(QueueNode *)malloc(sizeof(QueueNode));
    pn->entry=e;
    pn->next=NULL;
    if(!pq->rear){
        pq->frontt=pn;
    }
    else{
        pq->rear->next=pn;
    }
    pq->rear=pn;
    pq->sizee++;
}
void Dequeue(QueueEntry * pe, Queue * pq){
    QueueNode *pn=pq->frontt;
    *pe=pn->entry;
    pq->frontt=pq->frontt->next;
    free(pn);
    if(!pq->frontt){
        pq->rear=NULL;
    }
    pq->sizee--;
}
int QueueEmpty(Queue * pq){
    return !(pq->sizee);
}
int QueueFull(Queue * pq){
    return 0;
}


void TraverseQueue(Queue *pq, void (*pf)(QueueEntry)){
    QueueNode *pn=pq->frontt;
    while(pn){
        (*pf)(pn->entry);
        pn=pn->next;
    }
}

int firstElement(Queue *pq){
    return pq->frontt->entry;
}

int lastElement(Queue *pq){
    return pq->rear->entry;
}
int sizeOfQueue(Queue *pq){
    return pq->sizee;
}

void printQueue(Queue *pq){
    QueueNode *pn=pq->frontt;
    while(pn){
        printf("printing queue = %d\n",pn->entry);
        pn=pn->next;
    }
}
void destroyQueue(Queue *pq){
    QueueNode *pn;
    while(pq->frontt!=NULL){
        pn=pq->frontt;
        pq->frontt=pq->frontt->next;
        free(pn);
        if(!pq->frontt){
            pq->rear=NULL;
        }
    }
    pq->sizee=0;
}

void copyQueue(Queue *pq,Queue *pq2){
    QueueNode *pn = pq->frontt;
    QueueNode *pn1 = (QueueNode *)malloc(sizeof(QueueNode));
    pn1->entry=pn->entry;
    pn1->next=NULL;
    pq2->rear=pn1;
    pq2->frontt=pn1;
    pn = pn->next;
    while(pn){
        QueueNode * pn2 = (QueueNode *)malloc(sizeof(QueueNode));
        pn2->entry = pn->entry;
        pn2->next=NULL;
        pn1->next = pn2;
        pq2->rear=pn2;
        pn1=pn2;
        pn = pn->next;
    }
    pq2->sizee=pq->sizee;
}


void popMax(Queue *pq,int *m){
    QueueNode *pn = pq->frontt;
    int maxx=pn->entry;
    while(pn){
        if(pn->entry>maxx)
            maxx=pn->entry;
        pn=pn->next;
    }
    *m=maxx;
    QueueNode *pn1=pq->frontt;
    if(pq->frontt->entry==maxx){
        pq->frontt=pq->frontt->next;
        free(pn1);
    }
    else{
        pn=pn1->next;
        int c=0;
        while(pn1){
            if(pn->entry==maxx){
                if(pn==pq->rear){
                    pq->rear=pn1;
                    pq->rear->next=NULL;
                    free(pn);
                }
                else{
                    pn1->next=pn->next;
                    free(pn);
                    pn=pn1->next;
                    return;
                }
            }
            else{
                pn1=pn1->next;
                pn=pn->next;
            }

        }

    }
    pq->sizee--;
}
