#include <stdio.h>
#include <stdlib.h>
#include "list.h"
void func(int x){
    printf("tra = %d\n",x);
}
int main()
{
    List l;
    ListEntry e;
    createList(&l);
    insertList(0,21,&l);
    insertList(1,22,&l);
    insertList(2,23,&l);
    insertList(3,24,&l);
    insertList(4,25,&l);

    int  z=0;
    /*deleteList(0,&e,&l);
    printf("list of = %d \n",e);

    deleteList(0,&e,&l);
    printf("list of = %d \n",e);

    deleteList(0,&e,&l);
    printf("list of = %d \n",e);

    deleteList(0,&e,&l);
    printf("list of = %d \n",e);

    deleteList(0,&e,&l);
    printf("list of = %d \n",e);*/
    printf("size of list = %d\n",listSize(&l));
    insertList(2,1222,&l);
    printf("size of list = %d\n",listSize(&l));
    //destroyList(&l);
    //traverseList(&l,&func);
    replaceList(0,11,&l);
    retrieveList(1,&e,&l);
    printf("retr list = %d \n",e);

    deleteList(5,&e,&l);
    printf("last in list = %d \n",e);

    while(!listEmpty(&l)){
        deleteList(z,&e,&l);
        printf("list = %d \n",e);

    }
    printf("Hello world!\n");
    return 0;
}
