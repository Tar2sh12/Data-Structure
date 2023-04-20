#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
typedef int ListEntry;
typedef struct listnode{
	ListEntry entry;
	struct listnode *next;
}ListNode;

typedef struct listt{
	ListNode	*head;
	int		sizee;
}List;
//==============================
void createList(List *pl);
int listEmpty(List *pl);
int listFull(List *pl);
int listSize(List *pl);
void destroyList(List *pl);
void traverseList(List *pl,void(*pf)(ListEntry));
void insertList(int pos,ListEntry e,List *pl);
void deleteList(int pos,ListEntry *pe,List *pl);
void retrieveList(int pos,ListEntry *pe,List *pl);
void replaceList(int pos,ListEntry e,List *pl);

#endif // LIST_H_INCLUDED
