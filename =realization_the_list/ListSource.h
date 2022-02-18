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

int insert(List* plist, Data data);  //input the data
int LFirst(List* plist, Data* data);//reference the first data
int move(List* plist, Data* data); //Reference the data


Data LRemove(List* plist);// delete the data
int LCount(List* plist); //count the number of data on the list


#endif#pragma once

