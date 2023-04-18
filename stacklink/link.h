#ifndef LINK_H_INCLUDED
#define LINK_H_INCLUDED



typedef int StackEntry;

typedef struct stacknode{
    StackEntry entry;
    struct stacknode *next;

}StackNode;
typedef struct {
    StackNode *top;
    int sizee;
}Stack;

void createStack(Stack * ps);
void push(StackEntry  e , Stack * ps);
void pop(StackEntry * pe , Stack * ps);
int stackEmpty(Stack * ps );
int stackFull(Stack * ps);




//======================================



void Reverse(Stack * ps);
void RemoveEven(Stack *ps);
void RevStack(Stack * ps);
void RemoveOdd(Stack *ps);
void popMax(Stack *ps,StackEntry * pe);
void duplicate(Stack *ps);
void oddInTheLast(Stack *ps);


//======================================


void Reversear(Stack *ps);
void copyArr(Stack *ps2,Stack *ps);


//======================================


void CopyStack(Stack *ps, Stack *ps2);
void PrintStack(Stack *ps);
int stackSizee(Stack *ps);
int stackSize(Stack * ps);
void destroyStack(Stack * ps);
int firstEle(Stack *ps);
int lastEle(Stack *ps);


#endif // LINK_H_INCLUDED
