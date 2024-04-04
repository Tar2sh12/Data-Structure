#include "dlist.h"
#include <stdlib.h>

void createList(Dlist *pl){
    pl->head=NULL;
    pl->sizee=0;
    pl->endd=NULL;
    pl->colon=NULL;

}
int listEmpty(Dlist *pl){
    return (pl->head==NULL);
}
int listFull(Dlist *pl){
    return 0;
}
int listSize(Dlist *pl){
    return pl->sizee;
}
char lastInList(Dlist *pl){
    return pl->endd->entry;
}
void destroyList(Dlist *pl){
    DlistNode *q;
    while(pl->head){
        q=pl->head->next;
        free(pl->head);
        pl->head=q;
    }
    pl->sizee=0;
}
void traverseList(Dlist *pl,void(*pf)(ListEntry)){
    DlistNode *q=pl->head;
    while(q!=NULL){
        (*pf)(q->entry);
        q=q->next;
    }
}
void traverseReverseList(Dlist *pl,void(*pf)(ListEntry)){
    DlistNode *q=pl->endd;
    while(q!=NULL){
        (*pf)(q->entry);
        q=q->prev;
    }
}
void insertList(int pos,ListEntry e,Dlist *pl){
    DlistNode *q,*p;
    int i;
    p=(DlistNode*)malloc(sizeof(DlistNode));
    p->entry=e;
    p->next=NULL;
    p->prev=NULL;
    if(e==':'){
        pl->colon=p;
    }
    if(pos==pl->sizee){
        pl->endd=p;
    }
    if(pos==0){
        p->next=pl->head;
        pl->head=p;
        pl->head->prev=p;
        p->prev=NULL;
    }
    else{
        for(q=pl->head,i=0;i<pos-1;i++)
            q=q->next;
        p->next=q->next;
        q->next=p;
        q->next->prev=p;
        p->prev=q;

    }
    pl->sizee++;
}

void deleteList(int pos,ListEntry *pe,Dlist *pl){
    DlistNode *q,*tmp;
    int i;
    if(pos==0){
        *pe=pl->head->entry;
        tmp=pl->head;
        pl->head=pl->head->next;
        free(tmp);
        tmp->prev=NULL;
    }
    else{
        if(pos==pl->sizee-1){
            *pe=pl->endd->entry;
            q=pl->endd->prev;
            free(pl->endd);
            q->next=NULL;
            pl->endd=q;
        }
        else{
            for(q=pl->head,i=0;i<pos-1;i++){
                q=q->next;
            }
            if(q->next->entry==':'){
                pl->colon=NULL;
            }
            *pe=q->next->entry;
            tmp=q->next->next;
            tmp->prev=q;
            free(q->next);
            q->next=tmp;
        }
    }
    pl->sizee--;
}
void retrieveList(int pos,ListEntry *pe,Dlist *pl){
    DlistNode *q;
    int i;
    for(q=pl->head,i=0;i<pos;i++)
            q=q->next;
    *pe=q->entry;
}
void replaceList(int pos,ListEntry e,Dlist *pl){
    DlistNode *q;
    int i;
    for(q=pl->head,i=0;i<pos;i++)
            q=q->next;
    q->entry=e;
}

int mirror (Dlist * pl)
{
    DlistNode *pleft=pl->head;
    while(pleft&&pleft->entry!=':')
    {
        pleft=pleft->next;
    }
     if(!pleft)
    return 0;

    DlistNode *pright = pleft->next;


    while(pright!=NULL)
    {
       if (pleft->prev->entry != pright->entry)
             return 0;
        pleft=pleft->prev;
        pright=pright->next;
    }
   return 1;
}

int same(Dlist *pl)
{

    DlistNode* pleft = pl->head,*pf= pl->head;
    while (pleft&&pleft->entry != ':') {
        pleft = pleft->next;
    }
  if(!pleft)
    return 0;


    DlistNode *pright = pleft->next;


    while ( pright != NULL) {
        if ( pf->entry != pright->entry) {
            // Not the same string, return 0
            return 0;
        }
        pf= pf->next;
        pright = pright->next;
    }


    return 1;
}
