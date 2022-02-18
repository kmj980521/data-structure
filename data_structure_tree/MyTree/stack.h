#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#ifndef ___my___Stack


typedef struct NodeData {
	char data;
	struct NodeData* link;
}Node;

typedef struct myStack {
	Node* last_node;
	int numofData; //요소 수
}stack;

stack* makeStack()
{
	stack* newStack = (stack*)malloc(sizeof(stack));

	newStack->numofData = 0;
	newStack->last_node = NULL;

	return newStack;

}
void push_Stack(stack* inputStack, char c)
{
	if (inputStack->last_node == NULL) //리스트가 비어있으면, 
	{
		Node* newnode = (Node*)malloc(sizeof(Node));
		newnode->data = c;
		newnode->link = NULL;
		inputStack->last_node = newnode;
		(inputStack->numofData)++;
	}
	else {
		Node* newnode = (Node*)malloc(sizeof(Node) + 1);
		newnode->data = c;
		newnode->link = inputStack->last_node;
		inputStack->last_node = newnode;
		(inputStack->numofData)++;
	}
}
int is_Empty(stack* inputStack)
{
	if (inputStack->last_node == NULL)//비어있는지.
	{
		return 1;
	}
	return 0;
}
char peek_Stack(stack* inputStack)
{
	if (is_Empty(inputStack) == 1) //스택이 비어있으면
	{
		printf("스택이 비어있습니다.");
		exit(-1);
	}
	return inputStack->last_node->data;
}
char pop_Stack(stack* inputStack) //스택에서 마지막 요소 반환받음.
{
	if (inputStack->last_node == NULL) //리스트가 비어있으면, 
	{
		printf("스택이 비어있습니다.\n");
		return 0;
	}
	else {
		Node* delnode = (Node*)malloc(sizeof(Node)); //삭제에 진행될 노드.
		delnode = inputStack->last_node; //LiFo 제일 늦게 들어온 노드 삭제하기 위함.

		char a = (char)malloc(sizeof(char));
		a = delnode->data;

		inputStack->last_node = inputStack->last_node->link; //그 전에 들어온 노드 참조.

		free(delnode);
		return a; //문자 반환
	}
	return 0;
}

void print_Stack(stack* inputStack)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode = inputStack->last_node;
	while (newnode != NULL)
	{
		printf("%c\n ", newnode->data);
		newnode = newnode->link;
	}
}
int get_Order(char c) //연산자 우선순위 값 찾기.
{
	switch (c)
	{
	case'*':
	case'/':
		return 100;
	case'+':
	case'-':
		return 50;
	case'(':
		return 1;

	}
	return -1; //없음.
}
int who_Big(char a, char b)
{
	int a_Order = get_Order(a); //a 연산자 순위 
	int b_Order = get_Order(b); //b 연산자 순위 

	if (a_Order > b_Order) //a의 우선 순위가 높다면..
	{
		return 1;
	}
	else if (a_Order < b_Order)//b의 우선 순위가 높다면..
	{
		return -1;
	}
	else
		return 0;
}
char* infixToPostfix(char* express) //배열을 받아옴.
{
	stack* newStack; //후위로 할 때 사용할 스택
	newStack = makeStack(); //초기화.


	char element; //express 문자열의 한 글자씩 받아옴.
	char pop; //popStack을 통해서 받아온 문자열을 저장.

	int length = strlen(express); //문자열 길이를 받아 그 횟수만큼 연산 진행할 것임.
	char* exchange = (char*)malloc(length + 1); //express 배열의 크기 동적할당을 받음. 문자열의 길이는 변함이 없음. 배열 생성.
	int index = 0; //복사를 위한 변수.
	memset(exchange, 0, sizeof(char) * length + 1); //0으로 초기화


	for (int i = 0; i < length; i++)
	{
		element = express[i]; //처음부터 요소를 받아옴.

		if (isdigit(element)) //받아온 요소가 숫자인가? 
		{
			exchange[index++] = element; //index위치에 삽입 후 index++ 진행.
		}
		else//숫자가 아니면
		{
			switch (element)
			{
			case'(':
			{
				push_Stack(newStack, element); //스택에 쌓음.
				break;
			}
			case')':
			{
				while (1)
				{
					pop = pop_Stack(newStack); //마지막 요소 반환.
					if (pop == '(') //괄호를 만날때 까지 반환을 해야함.
					{
						break;
					}
					exchange[index++] = pop; //pop을 받아와서 삽입.
				}
				break;

			}
			case'+':
			case'-':
			case'*':
			case'/':
			{
				//넣으려는 연산자보다 스택의 마지막에 있는 연산자가 더 크면 스택에 있는 연산자가 나와야함

				//넣으려는 연산자와 스택의 마지막에 있는 연산자를 비교를 계속해서 넣으려는 연산자가 더 클 때까지 비교를 해야함.
				// &&스택의 마지막 연산자와, 새로 받은 연산자의 우선 순위 비교, whoBig을 통해 peek가 크면 1, 같으면 0을 반환받음.
				//isEmpty()로 스택이 비었는지 확인.
				while (!is_Empty(newStack) && who_Big(peek_Stack(newStack), element) >= 0)
				{
					exchange[index++] = pop_Stack(newStack);
				}
				//넣으려는 연산자가 더 크면 그대로 쌓아도 됨.
				push_Stack(newStack, element);
				break;
			}
			}

		}
	}
	while (!is_Empty(newStack)) //!를 해준 이유는 , 비어있으면 isEmpty 1을 반환. 남아있으면 0을 반환하는데 남아있어야 연산이 진행되기 때문.
	{
		exchange[index++] = pop_Stack(newStack); //스택에 남은 것들을 모두 넣어줌.
	}
	//strcpy(express,exchange); 서로 읽기 전용이라 strcpy사용 불가.
	return exchange;
}


int evalPostfix(char* express)
{
	char element; //요소를 하나씩 가져올 때 사용.
	stack* newStack; //연산에 사용되는 스택.
	newStack = makeStack(); //초기화

	int length = strlen(express);

	char popA, popB; //연산을 할 때 pop을 받아 저장할 문자
	for (int i = 0; i < length; i++)
	{
		element = express[i];
		if (isdigit(element))
		{
			push_Stack(newStack, element - '0'); //숫자 문자열을 숫자로 만들어주기 위해서.

		}
		else {
			popB = pop_Stack(newStack); //숫자 반환.

			popA = pop_Stack(newStack); //숫자 반환.

			switch (element)
			{
			case'+':
			{
				push_Stack(newStack, popA + popB);

				break;
			}
			case'-':
			{
				push_Stack(newStack, popA - popB);

				break;
			}
			case'*':
			{
				push_Stack(newStack, popA * popB);

				break;
			}
			case'/':
			{
				push_Stack(newStack, popA / popB);

				break;
			}
			}
		}

	}
	return pop_Stack(newStack);
}








#endif // !___my___Stack


#pragma once
