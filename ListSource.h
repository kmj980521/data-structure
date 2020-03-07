#ifndef __ListSource_H__
#define __ListSource_H__


#define TRUE 1;
#define FALSE 0;
typedef int Data;

typedef struct _node
{
		Data number; //노드에 저장된 데이터 값
		struct _node* next; // 다음 노드를 가리켜줄 포인터 변수
}Node;


typedef struct list {
		Node* head;
		Node* tail;
		Node* cur; // 삭제 및 조회를 참조하기 위한 변수
		Node* before; // 삭제 및 조회를 참조하기 위한 변수 
		int num; //리스트에 저장된 갯수  
}List;



void Listin(List* plist);// 처음 리스트 만들기 

int insert(List* plist, Data data); //값 입력 후 노드 추가
int LFirst(List* plist, Data* data);//처음 값 참조
int move(List* plist, Data* data);// 두 번째 이후 노드 참조


Data LRemove(List* plist);//노드 값 삭제
int LCount(List* plist);//노드의 수 확인


#endif#pragma once

