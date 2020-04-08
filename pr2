#include <stdio.h>
#include <stdlib.h>
#include "List.h"


void MakeList(List* object, int num)
{
	object->array = (int*)malloc(sizeof(int) * num); //num만큼 동적할당.배열의 동적할당.
	object->count = 0; //요소 수는 num;
	object->position = 0; //배열의 참조를 위한 변수 . 배열의 인덱스는 0부터이므로 0대입.
	object->max = num; //num만큼 할당했으니, 배열의 길이는 num.
}
void Init_num(List* object, int num)
{
	if (object->count >= object->max)
	{//요소가 꽉 차서 공간이 부족할 때
		printf("공간이 부족합니다.");
		return; //종료
	}
	object->array[object->count] = num; //요소 입력
	(object->count)++; //요소가 들어갔으니 요소 수 ++
}
void Init_special(List* object, int num, int index)
{
	if (object->count == object->max)
	{//요소가 꽉 차서 공간이 부족할 때
		printf("공간이 부족합니다.");
		return; //종료
	}
	int last = (object->count)-1; //마지막 인덱스번호
	for (int i = 0; i < (object->count) - index; i++) //넣고싶은 자리의 인덱스부터 뒤로 이동
	{
		object->array[last + 1] = object->array[last];
		last--;
	}
	object->array[index] = num;
	(object->count)++;
}
int  delete_num(List* object)
{
	if (object->count == 0) //만약 배열이 비었을경우
	{
		printf("배열이 비어있습니다.");
		return;
	}
	printf("position의 값: %d\n", object->position);
	int position2 = object->position; //백업
	int lastofarray = object->count; //배열의 끝까지 돌면서 삭제할 것임.
	int result = object->array[position2];
	for (int i = position2; i < lastofarray-1; i++)
	{
		object->array[i] = object->array[i + 1]; //한 칸씩 앞으로
	}
	printf("\n");
	(object->count)--; //하나 삭제했으므로 요소의 수 1 감소
	(object->position)--; //삭제한 위치의 전 단계로 가줘야 삭제한 값이 존재했던 인덱스를 다시 참조가 가능
	return result;
}
void free_List(List* object)
{
	free(object->array);
}
int showcount(List* object) {
	return object->count;
}
int first(List* object, int* data) {
	if ((object->count) == 0)
	{
		printf("배열이 비었습니다");
		return false; 
	}
	(object->position) = 0; 
	*data = object->array[0];
	return true;
}

int goNext(List* object, int *data)//30받음
{
	if(  (object->position) >= (object->count)-1 )//참조하려는 위치가 배열의 요소 수 보다 클 경우, 즉 참조할 것이 없는 경우
	{
		return false;
	}
	(object->position)++;
	*data = object->array[object->position];
	return true; 
}
int main()
{
	List array; //구조체 선언
	int num; //입력받기 위한 수
	printf("배열의 크기를 입력하세요");
	scanf_s("%d", &num);
	MakeList(&array,num); //구조체 배열 생성

	Init_num(&array, 120);
	Init_num(&array, 240);
	Init_num(&array, 240);
	Init_num(&array, 600);
	Init_special(&array, 30, 0); //array리스트 배열에, 30이라는 값을, 인덱스 2인 위치에 삽입하기.


	int num2; //삭제하고 싶은 수 입력.
	int data; //first함수와 goNext함수에서 반환받을 값을 저장할 변수.
	printf("삭제하고 싶은 수를 입력하세요");
	scanf_s("%d", &num2);
	
	if (first(&array, &data)) //true이면 배열은 값이 존재, 그 값을 data에 저장.
	{
		if (data == num2) //삭제하고 싶은 숫자가 존재할시.
		{
			delete_num(&array); //삭제 실행.
			printf("첫번째 if문 호출");
		}
		while (goNext(&array, &data)) //만약 다음 값에도 존재할 경우. 만약 실행이 된다면 함수마다 position++로 참조위치가 저장이 됨.
		{
			printf("%d\n", data);
			if (data == num2)
			{
				
				delete_num(&array);
				printf("%d 값을 삭제했습니다 \n", num2);
				for (int i = 0; i < array.count; i++)
				{
					printf("%d ", array.array[i]);
				}
				printf("\n");
			}
		}
	}
	for (int i = 0; i < array.count; i++)
	{
		printf("%d ", array.array[i]);
	}
	printf("\n");
	printf("총 배열의 요소의 수는 %d 입니다.", showcount(&array));
	free_List(&array); //메모리 할당 해제.

}
