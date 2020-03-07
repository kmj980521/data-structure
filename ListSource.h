#ifndef __ListSource_H__
#define __ListSource_H__


#define TRUE 1;
#define FALSE 0;
typedef int Data;

typedef struct _node
{
		Data number; //Data values stored on node
		struct _node* next; //Pointer to point to next node
}Node;


typedef struct list {
		Node* head;
		Node* tail;
		Node* cur; // Data for deletion and reference
		Node* before; // Data for deletion and reference 
		int num; //Number of variables stored in the list  
}List;



void Listin(List* plist); // Generate a list 

int insert(List* plist, Data data); //값 입력 후 노드 추가
int LFirst(List* plist, Data* data);//처음 값 참조
int move(List* plist, Data* data);// 두 번째 이후 노드 참조


Data LRemove(List* plist);// delete the data
int LCount(List* plist);// count the data


#endif#pragma once

