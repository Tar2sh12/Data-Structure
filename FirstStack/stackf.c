#include "stackf.h"

void createStack(Stack *ps){
    ps->top=-1;
}
void push(StackEntry e,Stack *ps){
    ps->top++;
    ps->entry[ps->top]=e;


}

void pop(StackEntry *pe,Stack *ps){
    *pe=ps->entry[ps->top];
    ps->top--;
}

int stackEmpty(Stack *ps){
    return ps->top==-1;
}
int stackFull(Stack *ps){
    return ps->top==(Max-1);
}

int sizest(Stack * ps){
    return ps->top+1;
}


void first(StackEntry *e ,Stack * ps){
    *e=ps->entry[0];
}

void last(StackEntry *e ,Stack * ps){
    *e=ps->entry[ps->top];
}


void copystack(Stack * ps , Stack * ps2){
    for(int i=0;i<=ps->top;i++){
        ps2->entry[i]=ps->entry[i];
    }
    ps2->top=ps->top;
}

void destroy(Stack * ps){
    ps->top=-1;
}



void printstack(Stack *ps){
    for(int i=ps->top;i>=0;i--){
        printf("\nstack  =%d",ps->entry[i]);
    }
}




void TraverseStack(Stack *ps,void(*pf)(StackEntry)){
    for(int i=ps->top;i>=0;i--){
        (*pf)(ps->entry[i]);
    }
}

void popMax(Stack *ps,StackEntry *pe){
    int maxx=ps->entry[0];
    int maxi;
    for(int i=0;i<=ps->top;i++){
        if(maxx<ps->entry[i]){
            maxx=ps->entry[i];
            maxi=i;
        }
    }
    for(int j=maxi;j<=ps->top;j++){
        ps->entry[j]=ps->entry[j+1];
    }
    ps->entry[ps->top]=maxx;
    ps->top--;
    *pe = maxx;
}


//============================
void swapp(int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void reverseStack(Stack *ps){
    for(int i=0;i<(ps->top+1)/2;i++){
        swapp(&ps->entry[i],&ps->entry[(ps->top+1)-i-1]);
    }
}
