#include <stdio.h>
#include <stdlib.h>
#include "ListSource.h"


void Listin(List* plist) //Generate a list 
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->num = 0;
}

int insert(List* plist, Data data) //리스트 처음 값 입력
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->number = data;
	newNode->next = plist->head->next; //NULL값이 저장됨
	plist->head->next = newNode;
	(plist->num)++;

	return TRUE;
}


int LFirst(List* plist, Data* data)
{
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*data = plist->cur->number;
	return TRUE;

}
int move(List* plist, Data* data)
{
	if (plist->cur->next == NULL)
		return FALSE;
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*data = plist->cur->number;
	return TRUE;
}
Data LRemove(List* plist) 
{
	Node* rpos = plist->cur;
	Data nu = rpos->number;

	plist->before->next = plist->cur -> next;
	plist->cur = plist->before;

	free(rpos);
	(plist->num)--;

	return nu;
}
int LCount(List* plist)
{
	return plist->num;
}
