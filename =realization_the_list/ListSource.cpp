#include <stdio.h>
#include <stdlib.h>
#include "ListSource.h"


void Listin(List* plist) //Generate a list 
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->num = 0;
}

int insert(List* plist, Data data) //Save value to list
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->number = data;
	newNode->next = plist->head->next; 
	plist->head->next = newNode;
	(plist->num)++;

	return TRUE;
}


int LFirst(List* plist, Data* data) //input the data
{
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*data = plist->cur->number;
	return TRUE;

}
int move(List* plist, Data* data) //Reference the data
{
	if (plist->cur->next == NULL)
		return FALSE;
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*data = plist->cur->number;
	return TRUE;
}
Data LRemove(List* plist)  // Delete the data
{
	Node* rpos = plist->cur;
	Data nu = rpos->number;

	plist->before->next = plist->cur -> next;
	plist->cur = plist->before;

	free(rpos);
	(plist->num)--;

	return nu;
}
int LCount(List* plist) //count the number of data on the list
{
	return plist->num;
}
