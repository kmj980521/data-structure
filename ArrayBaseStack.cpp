[200~#include <iostream>
#include "ArrayBaseStack.h"

using namespace std;

void StackInit(Stack* pstack) //리스트 초기화
{
		pstack->topIndex = -1;
}
int SIsEmpty(Stack* pstack) 
{
		if (pstack->topIndex == -1)//비었을 때 -1 반환 
				{
							return TRUE;
								}
			else
						return FALSE;
}

void SPush(Stack* pstack, Data data)
{
		(pstack->topIndex)++;
			pstack->stackArr[pstack->topIndex] = data;
}
Data SPop(Stack* pstack)
{
		Data remove;
			
			if (SIsEmpty(pstack))
					{
								cout << "현재 스택은 비어있습니다" << endl;
										exit(-1); //프로그램 종료 
											}
				remove = pstack->topIndex;
					pstack->topIndex -= 1;

						return pstack->stackArr[remove];
}
Data SPeek(Stack* pstack)
{
		if (SIsEmpty(pstack))
				{
							cout << "현재 스택은 비어있습니다" << endl;
									exit(-1); //프로그램 종료 
										}
			return pstack->stackArr[pstack->topIndex];
}
void LookStack(Stack* pstack)
{
		if (SIsEmpty(pstack))
				{
							cout << "현재 스택은 비어있습니다" << endl;
									exit(-1); //프로그램 종료 
										}
			for (int i = 0; i <= pstack->topIndex; i++)
					{
								cout << "현재 스택에는" << pstack->stackArr[i] << "이(가) 있습니다" << endl;
									}
}
