#include <stdio.h>
#include <stdlib.h>
#include "link.h"
void destroy(Stack *s){
    StackEntry e;
    while(!stackEmpty(s)){
        pop(&e,s);
    }
}

int firstlp(Stack *ps)
{
     StackEntry e;
     Stack s2;
     createStack(&s2);
     int first;
     while(!stackEmpty(ps))
     {
         pop(&e,ps);
         push(e,&s2);
         first = e;
     }
     while(!stackEmpty(&s2)){
         pop(&e,&s2);
         push(e,ps);
     }
     return first;


}
int sizee(Stack *ps){
    StackEntry e;
    Stack s2;
    createStack(&s2);
    int c=0;
    while(!stackEmpty(ps)){
        pop(&e,ps);
        push(e,&s2);
        c++;
    }
    while(!stackEmpty(&s2)){
        pop(&e,&s2);
        push(e,ps);
    }
    return c;
}



void lastlp(Stack *ps,StackEntry *pe){
    StackEntry e;
    pop(&e,ps);
    push(e,ps);
    *pe=e;
}









void copylp(Stack s, Stack *ps2){
    StackEntry e;
    Stack s3;
    createStack(&s3);
    while(!stackEmpty(&s)){
        pop(&e,&s);
        push(e,&s3);
    }
    while(!stackEmpty(&s3)){
        pop(&e,&s3);
        push(e,ps2);
        push(e,&s);
    }
}

void removeEvenn(Stack *ps){
    StackEntry e;
    Stack s3;
    createStack(&s3);
    while(!stackEmpty(ps)){
        pop(&e,ps);
        if(e%2!=0){
            push(e,&s3);
        }
    }
    while(!stackEmpty(&s3)){
        pop(&e,&s3);
        push(e,ps);
    }
}

void reversee(Stack *ps){
    StackEntry e;
    Stack s3,s4;
    createStack(&s3);
    createStack(&s4);
    while(!stackEmpty(ps)){
        pop(&e,ps);
        push(e,&s3);
    }
    while(!stackEmpty(&s3)){
        pop(&e,&s3);
        push(e,&s4);
    }
        while(!stackEmpty(&s4)){
        pop(&e,&s4);
        push(e,ps);
    }
}

void print_stack(Stack *ps)
{
     StackEntry e;
     Stack s3;
     createStack(&s3);
     while(!stackEmpty(ps))
     {
     pop(&e,ps);
     push(e,&s3);
     printf("user level print stack %d\n",e);
     }
     while(!stackEmpty(&s3))
     {
     pop(&e,&s3);
     push(e,ps);
     }
}





int main()
{
    Stack s;
    createStack(&s);
    StackEntry e;



    //;
    /*push(7,&s);
    push(9,&s);
    push(11,&s);*/
    push(1,&s);
    push(2,&s);
    push(3,&s);
    push(4,&s);
    push(5,&s);
    /*push(6,&s);
    push(7,&s);
    push(8,&s);
    push(9,&s);
    push(10,&s);
    push(11,&s);
    push(4,&s);
    push(5,&s);
    push(6,&s);
    push(7,&s);
    push(9,&s);
    push(11,&s);*/




    //printf("size of stack = %d\n",stackSize(&s));
    //Reverse(&s);
    //RemoveEven(&s);
    //destroy(&s);

    Stack s2;
    createStack(&s2);

    //printf("size of stack = %d\n",stackSizee(&s));
    //printf("first element in the stack = %d\n",firstEle(&s));
    //printf("last element in the stack = %d\n",lastEle(&s));
    //CopyStack(&s,&s2);
    //PrintStack(&s);

    //StackEntry e2;
    //lastlp(&s,&e2);
    //printf("last element in the stack = %d\n",e2);
    //copylp(s,&s2);
    //print_stack(&s2);
    //printf("size of stack = %d\n",sizee(&s2));
    //printf("first element in the stack = %d\n",firstlp(&s));

    //Reversear(&s);
    //copyArr(&s2,&s);
    //RemoveEven(&s);
    //removeEvenn(&s);
    //reversee(&s);
    //RevStack(&s);
    //RemoveOdd(&s);
    //popMax(&s,&e);
    //printf("last max = %d\n",e);
    //duplicate(&s);
    //int o;


    //oddInTheLast(&s);
    duplicate(&s);
    PrintStack(&s);
    /*while(!stackEmpty(&s)){
        pop(&e,&s);
        printf("stack two = %d\n",e);
    }*/



    return 0;
}
