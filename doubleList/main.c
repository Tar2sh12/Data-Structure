#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"
void func(char x){
    printf("tra = %c\n",x);
}
int main()
{
    Dlist d;
    ListEntry e;
    createList(&d);
    insertList(0,'a',&d);
    insertList(1,'b',&d);
    insertList(2,'c',&d);
    insertList(3,'d',&d);
    insertList(4,'e',&d);
    insertList(5,'f',&d);


    printf("size of list = %d\n",listSize(&d));
    printf("\n");
    /*replaceList(0,'h',&d);
    retrieveList(1,&e,&d);
    printf("retr list = %c \n",e);*/

    deleteList(5,&e,&d);
    printf("last in list = %c \n",e);
    printf("last in the list = %c\n",lastInList(&d));

    printf("\n");
    traverseList(&d,&func);
    printf("\n");
    traverseReverseList(&d,&func);
    printf("\n");

    while(!listEmpty(&d)){
        deleteList(0,&e,&d);
        printf("double list = %c \n",e);

    }


    printf("Hello world!\n");
    return 0;
}
