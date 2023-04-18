#include <stdio.h>
#include <stdlib.h>
#include "stackf.h"
int firstl(Stack s){
    StackEntry e;
    while(!stackEmpty(&s)){
        pop(&e,&s);
    }
    int f=e;
    return f;
}

int sizel(Stack s){
    StackEntry e;
    int c=0;
    while(!stackEmpty(&s)){
        pop(&e,&s);
        c++;
    }
    return c;
}
int lastl(Stack s){
    StackEntry e;
    pop(&e,&s);
    int l=e;
    return l;
}



void copyl(Stack s, Stack *ps2){
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
    }
}

void destroyl(Stack *ps){
    StackEntry e;
    while(!stackEmpty(ps)){
        pop(&e,ps);
    }
}

void printl(Stack ps){
    StackEntry e;
    while(!stackEmpty(&ps)){
        pop(&e,&ps);
        printf("stack 3 = %d\n",e);
    }
}

void Display(StackEntry e){
    printf("e = %d \n ",e);
}

int main()
{
    StackEntry e;
    Stack s;
    Stack s2;
    createStack(&s);
    createStack(&s2);

    push(1,&s);
    push(2,&s);
    push(3,&s);
    push(2,&s);

    push(1,&s);
    push(3,&s);
    push(2,&s);
    push(6,&s);

    //printf("first element in user level = %d \n",firstl(s));
    //printf("size of stack in user level = %d \n",sizel(s));
    //printf("last element in user level = %d \n",lastl(s));

    //copystack(&s,&s2);
    //popMax(&s,&e);
    //printf("last = %d \n",e);
    //push(10,&s);

    //destroyl(&s2);
    //printl(s2);

    //TraverseStack(&s,&Display);
    popMax(&s,&e);
    printf("\n last max = %d\n",e);
    //reverseStack(&s);
    while(!stackEmpty(&s)){
        pop(&e,&s);
        printf("\n stack 2= %d",e);
    }




    return 0;
}
