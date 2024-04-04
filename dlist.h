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
	DlistNode	*colon;
	int		sizee;
}Dlist;


//==================================================

int mirror (Dlist * pl);
int same(Dlist *pl);


void traverseList(Dlist *pl,void(*pf)(ListEntry));
void traverseReverseList(Dlist *pl,void(*pf)(ListEntry));

//==================================================
void createList(Dlist *pl);
int listEmpty(Dlist *pl);
int listSize(Dlist *pl);
int listFull(Dlist *pl);
void destroyList(Dlist *pl);
void insertList(int pos,ListEntry e,Dlist *pl);
void deleteList(int pos,ListEntry *pe,Dlist *pl);
void retrieveList(int pos,ListEntry *pe,Dlist *pl);
void replaceList(int pos,ListEntry e,Dlist *pl);

char lastInList(Dlist *pl);

#endif // DLIST_H_INCLUDED
