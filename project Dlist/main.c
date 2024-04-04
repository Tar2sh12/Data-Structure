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

    char c[100];
    fgets(c, 500, stdin);
    for(int i=0;i<strlen(c)-1;i++){
        insertList(i,c[i],&d);
    }


   /* while(!listEmpty(&d)){
        deleteList(0,&e,&d);
        printf("double list = %c \n",e);

    }
*/

     int x =same(&d);
     x?printf("same\n"):printf("not same\n");
      int y =mirror(&d);
      y?printf("mirror\n"):printf("not mirror\n");
    return 0;
}
