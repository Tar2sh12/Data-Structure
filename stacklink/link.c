#include "link.h"
#include <stdlib.h>
void createStack(Stack * ps){
    ps->top=NULL;
    ps->sizee=0;
}

void push(StackEntry  e , Stack * ps){
    StackNode *pn=(StackNode*)malloc(sizeof(StackNode));
    pn ->entry=e;
    pn->next=ps->top;
    ps->top=pn;
    ps->sizee++;
}



void pop(StackEntry * pe , Stack * ps){
    StackNode *pn=ps->top;
    * pe=pn->entry;
    ps->top=ps->top->next;
    free(pn);
    ps->sizee--;
}

void destroyStack(Stack * ps){
    StackNode *pn;
    while(ps->top != NULL){
        pn =ps->top;
        ps->top=ps->top->next;
        free(pn);
    }
    ps->sizee=0;
}

int stackEmpty(Stack * ps ){
    return ps->top ==0;
}

int stackFull(Stack * ps){
    return 0;
}


int stackSize(Stack *ps){
    int c=0;
    StackNode *pn=ps->top;
    while(pn != NULL){
        c++;
        pn=pn->next;
    }
    return c;
}
int stackSizee(Stack *ps){
    return ps->sizee;
}




void Reverse(Stack * ps){

    if(ps->top == NULL || ps->top->next==NULL){
        return ;
    }
    StackNode *t1=ps->top->next;
    StackNode *t2;
    if(t1){
        t2=t1->next;
    }
    else{
        t2=NULL;
    }

    ps->top->next=NULL;
    while(t2 != NULL){
            t1->next = ps->top;
            ps->top = t1;
            t1 = t2;
            t2 = t2->next;
        }

        t1 ->next = ps->top;
        ps->top = t1;


}

void RevStack(Stack * ps)
{
    StackNode * p1 = ps->top;
    while(p1->next != NULL)
        p1 = p1->next;
    StackNode * p2 = p1;
    while(ps->top != p2)
    {
        p1 = p2->next;
        p2->next = ps->top;
        ps->top = ps->top->next;
        p2->next->next = p1;
    }
}



void RemoveEven(Stack *ps){

    if(ps->top == NULL){        //stack is empty
        return;
    }


    StackNode *prev = ps->top;
    StackNode *temp = prev->next;
    StackNode *successor;
    if(temp == NULL){
        successor = NULL;
    }else{
        successor = temp->next;
    }


    while(successor != NULL){
        if(temp->entry %2 ==0){
            prev->next = successor;
            free(temp);
            temp = successor;
            successor = successor->next;
        }else{
            prev = temp;
            temp = successor;
            successor = successor->next;
        }
    }

    if(temp != NULL){
        if(temp->entry %2 ==0){
            temp = NULL;        //this is the end of stack, so we are not freeing it
            prev->next = temp;
        }
    }


    //here is the check for the first element in the stack
    prev = ps->top;
    if(prev ->entry %2 ==0){
        ps->top = ps->top->next;
        free(prev);
    }


}

void RemoveOdd(Stack *ps){

    if(ps->top == NULL){        //stack is empty
        return;
    }


    StackNode *prev = ps->top;
    StackNode *temp = prev->next;
    StackNode *successor;
    if(temp == NULL){
        successor = NULL;
    }else{
        successor = temp->next;
    }


    while(successor != NULL){
        if(temp->entry %2 !=0){
            prev->next = successor;
            free(temp);
            temp = successor;
            successor = successor->next;
        }else{
            prev = temp;
            temp = successor;
            successor = successor->next;
        }
    }

    if(temp != NULL){
        if(temp->entry %2 !=0){
            temp = NULL;        //this is the end of stack, so we are not freeing it
            prev->next = temp;
        }
    }


    //here is the check for the first element in the stack
    prev = ps->top;
    if(prev ->entry %2 !=0){
        ps->top = ps->top->next;
        free(prev);
    }


}


void popMax(Stack *ps,StackEntry * pe){
    StackNode *pn=ps->top;
    int max=pn->entry;
    while(pn !=NULL){

        if(max<pn->entry){
            max=pn->entry;
        }
        pn=pn->next;
    }

    *pe=max;
    pn=ps->top;
    if(ps->top->entry==max){
        ps->top=ps->top->next;
        free(pn);
    }
    else{
        StackNode *pn1;
        while(pn !=NULL){
            if(pn->next->entry==max){
                pn1=pn->next;
                pn->next=pn1->next;
                free(pn1);
                return;
            }
            pn=pn->next;
        }
    }
}


void CopyStack(Stack *ps, Stack *ps2)
{
     StackNode *pn = ps->top;
     StackNode * pn1 = (StackNode *)malloc(sizeof(StackNode));
     pn1->entry = pn->entry;
     pn1->next = NULL;
     ps2->top = pn1;
     pn = pn->next;
     while(pn != NULL)
     {
     StackNode * pn2 = (StackNode *)malloc(sizeof(StackNode));
     pn2->entry = pn->entry;
     pn2->next=NULL;
     pn1->next = pn2;
     pn1=pn2;
     pn = pn->next;
     }
}


void copyArr(Stack *ps2,Stack *ps){
    int c=ps->sizee;
    StackNode *pn=ps->top;
    int arr[c];
    int cc=0;
    while(pn!=NULL){
        int e;
        e=pn->entry;
        arr[cc]=e;
        cc++;
        pn=pn->next;
    }
    pn=ps->top;
    int c2=ps->sizee-1;
    while(pn!=NULL){
        StackNode *pn4=(StackNode*)malloc(sizeof(StackNode));
        pn4 ->entry=arr[c2];
        pn4->next=ps2->top;
        ps2->top=pn4;
        ps2->sizee++;
        c2--;
        pn=pn->next;
    }
}


void PrintStack(Stack *ps)
{
     StackNode * pn = ps->top;
     while(pn != NULL){
         printf("stack %d\n",pn->entry);
         pn=pn->next;
     }
}






int firstEle(Stack *ps){
    StackNode *pn=ps->top;
    int f;
    while(pn!=NULL){
        f=pn->entry;
        pn=pn->next;
    }
    return f;

}
int lastEle(Stack *ps){
    int l;
    StackNode *pn=ps->top;
    l=pn->entry;
    return l;
}



void Reversear(Stack *ps){
    int c;
    c=ps->sizee;
    StackNode *pn=ps->top;
    int arr[c];
    int cc=0;
    while(pn!=NULL){
        int e;
        e=pn->entry;
        arr[cc]=e;
        cc++;
        pn=pn->next;
    }
    pn=ps->top;
    int c2=c-1;
    while(pn!=NULL){
        pn->entry=arr[c2];
        c2--;
        pn=pn->next;
    }
}

void duplicate(Stack *ps){
    StackNode *pn=ps->top;
    while(pn!=NULL){
        StackNode *pn1=(StackNode*)malloc(sizeof(StackNode));
        pn1->entry=pn->entry;
        pn1->next=pn->next;
        pn->next=pn1;
        pn=pn->next->next;
    }
}


void swapp(int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}



void oddInTheLast(Stack *ps){
    StackNode *pn3=ps->top;
    int o=0,c=1;
    while(pn3->next!=NULL){
        if(pn3->entry%2!=0)
            o++;
        c++;
        pn3=pn3->next;
    }
    if(c>2){
        StackNode * p1 = ps->top, *p2;
        while(ps->top->entry % 2 != 0)
        {
            ps->top = ps->top->next;
            p1->next=pn3->next;
            pn3->next=p1;
            pn3=pn3->next;
            p1 = ps->top;
        }
        p1=ps->top;
        p2=p1->next;
        while(p2!=pn3){
            if(p2->entry%2!=0){
                p1->next=p1->next->next;
                p2->next=pn3->next;
                pn3->next=p2;
                p2=p1->next;
                o--;
            }
            else{
                p1=p1->next;
                p2=p1->next;
            }
        }
    }
}


void RemEven(Stack * ps)
{
    StackNode * p1 = ps->top, *p2;
    while(ps->top->entry % 2 == 0)
    {
        ps->top = ps->top->next;
        free(p1);
        p1 = ps->top;
    }
    p2 = p1->next;
    while(p2 != NULL)
    {
        if(p2->entry % 2 == 0)
        {
            p1->next = p2->next;
            free(p2);
            p2 = p1->next;
        }
        else
        {
            p1 = p2;
            p2 = p1->next;
        }
    }

}
