#include <iostream>
#include "ListBaseStack.h"


using namespace std;

void StackInit(Stack* pstack)
{
	pstack->head = NULL;
	pstack->count = 0;
}
int SIsEmpty(Stack* pstack)
{
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pstack->head;
	pstack->head = newNode;
	(pstack->count)++;
}

Data SPop(Stack* pstack)
{
	Node* rev;
	Data remove;
	if (SIsEmpty(pstack))
	{
		cout << "스택에 저장된 값이 없습니다" << endl;
		exit(-1);
	}
	rev = pstack->head;
	remove = pstack->head->data;
	pstack->head=pstack->head->next;;
	free(rev);
	(pstack->count)--;
	return remove;
}
Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack))
	{
		cout << "스택에 저장된 값이 없습니다" << endl;
		exit(-1);
	}
	return pstack->head->data;
}
int SCount(Stack* pstack)
{
	return pstack->count;
}
