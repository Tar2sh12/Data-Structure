#ifndef STACKF_H_INCLUDED
#define STACKF_H_INCLUDED
#define Max 9


typedef int StackEntry;

typedef struct
{
    int top;
    StackEntry entry[Max];
}Stack;
void createStack(Stack * ps);
void push(StackEntry  e , Stack * ps);
void pop(StackEntry * pe , Stack * ps);
int stackEmpty(Stack * ps);
int stackFull(Stack * ps);

int sizest(Stack * ps);
void first(StackEntry *e ,Stack * ps);
void last(StackEntry *e ,Stack * ps);
void copystack(Stack * ps,Stack * ps2);
void destroy(Stack * ps);
void printstack(Stack *ps);
void TraverseStack(Stack *ps,void(*pf)(StackEntry));
void reverseStack(Stack *ps);
void popMax(Stack *ps,StackEntry *pe);
#endif // STACKF_H_INCLUDED
