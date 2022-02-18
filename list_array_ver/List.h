#ifndef __LIST_H__
 #define __LIST_H__

#define true 1
#define false 0
typedef struct __ArrayList {
	int *array; //동적으로 할당을 받을 것임.
	int count; //저장된 요소 수
	int position; //참조를 하기 위한 변수
	int max; //배열에서의 마지막 인덱스 값을 알기 위해서 선언.
}List;  //List 구조체 선언

 void MakeList(List* object, int num); //리스트 생성 및 초기화
void Init_num(List* object, int num); //리스트에 요소 추가
int  delete_num(List* object);//리스트의 입력받은 인덱스의 요소 삭제 ,반환을 위해서.
void free_List(List* object); //리스트 할당해제.

void Init_special(List* object, int num , int index); // 입력하려는 num을 배열의 index값에 삽입

int showcount(List* object); //배열의 요소의 수.

int first(List* object, int *data); //배열의 첫번째 요소 탐색 및 반환

int goNext(List* object, int* data); // 배열의 두번째 요소부터 탐색.
#endif#pragma once
