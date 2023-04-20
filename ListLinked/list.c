#include <stdlib.h>
#include "list.h"
void createList(List *pl){
    pl->head=NULL;
    pl->sizee=0;
}
int listEmpty(List *pl){
    return (pl->sizee==0);
}
int listFull(List *pl){
    return 0;
}
int listSize(List *pl){
    return pl->sizee;
}
void destroyList(List *pl){
    ListNode *q;
    while(pl->head){
        q=pl->head->next;
        free(pl->head);
        pl->head=q;
    }
    pl->sizee=0;
}
void traverseList(List *pl,void(*pf)(ListEntry)){
    ListNode *q=pl->head;
    while(q!=NULL){
        (*pf)(q->entry);
        q=q->next;
    }
}
void insertList(int pos,ListEntry e,List *pl){
    ListNode *q,*p;
    int i;
    p=(ListNode*)malloc(sizeof(ListNode));
    p->entry=e;
    p->next=NULL;
    if(pos==0){
        p->next=pl->head;
        pl->head=p;
    }
    else{
        for(q=pl->head,i=0;i<pos-1;i++)
            q=q->next;
        p->next=q->next;
        q->next=p;
    }
    pl->sizee++;
}
void deleteList(int pos,ListEntry *pe,List *pl){
    ListNode *q,*tmp;
    int i;
    if(pos==0){
        *pe=pl->head->entry;
        tmp=pl->head->next;
        free(pl->head);
        pl->head=tmp;
    }
    else{
        for(q=pl->head,i=0;i<pos-1;i++)
            q=q->next;
        tmp=q->next->next;
        free(q->next);
        q->next=tmp;
    }
    pl->sizee--;
}
void retrieveList(int pos,ListEntry *pe,List *pl){
    ListNode *q;
    int i;
    for(q=pl->head,i=0;i<pos;i++)
            q=q->next;
    *pe=q->entry;
}
void replaceList(int pos,ListEntry e,List *pl){
    ListNode *q;
    int i;
    for(q=pl->head,i=0;i<pos;i++)
            q=q->next;
    q->entry=e;
}
