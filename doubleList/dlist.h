#ifndef DLIST_H_INCLUDED
#define DLIST_H_INCLUDED
typedef char ListEntry;
typedef struct dlistnode{
	ListEntry entry;
	struct dlistnode *next;
	struct dlistnode *prev;
}DlistNode;

typedef struct dlistt{
	DlistNode	*head;
	DlistNode	*endd;
	int		sizee;
}Dlist;
//===============================

void createList(Dlist *pl);
int listEmpty(Dlist *pl);
int listFull(Dlist *pl);
int listSize(Dlist *pl);
void destroyList(Dlist *pl);
void traverseList(Dlist *pl,void(*pf)(ListEntry));
void traverseReverseList(Dlist *pl,void(*pf)(ListEntry));
void insertList(int pos,ListEntry e,Dlist *pl);
void deleteList(int pos,ListEntry *pe,Dlist *pl);
void retrieveList(int pos,ListEntry *pe,Dlist *pl);
void replaceList(int pos,ListEntry e,Dlist *pl);
//==================================================
int lastInList(Dlist *pl);
#endif // DLIST_H_INCLUDED
