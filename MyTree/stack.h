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
	int numofData; //��� ��
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
	if (inputStack->last_node == NULL) //����Ʈ�� ���������, 
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
	if (inputStack->last_node == NULL)//����ִ���.
	{
		return 1;
	}
	return 0;
}
char peek_Stack(stack* inputStack)
{
	if (is_Empty(inputStack) == 1) //������ ���������
	{
		printf("������ ����ֽ��ϴ�.");
		exit(-1);
	}
	return inputStack->last_node->data;
}
char pop_Stack(stack* inputStack) //���ÿ��� ������ ��� ��ȯ����.
{
	if (inputStack->last_node == NULL) //����Ʈ�� ���������, 
	{
		printf("������ ����ֽ��ϴ�.\n");
		return 0;
	}
	else {
		Node* delnode = (Node*)malloc(sizeof(Node)); //������ ����� ���.
		delnode = inputStack->last_node; //LiFo ���� �ʰ� ���� ��� �����ϱ� ����.

		char a = (char)malloc(sizeof(char));
		a = delnode->data;

		inputStack->last_node = inputStack->last_node->link; //�� ���� ���� ��� ����.

		free(delnode);
		return a; //���� ��ȯ
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
int get_Order(char c) //������ �켱���� �� ã��.
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
	return -1; //����.
}
int who_Big(char a, char b)
{
	int a_Order = get_Order(a); //a ������ ���� 
	int b_Order = get_Order(b); //b ������ ���� 

	if (a_Order > b_Order) //a�� �켱 ������ ���ٸ�..
	{
		return 1;
	}
	else if (a_Order < b_Order)//b�� �켱 ������ ���ٸ�..
	{
		return -1;
	}
	else
		return 0;
}
char* infixToPostfix(char* express) //�迭�� �޾ƿ�.
{
	stack* newStack; //������ �� �� ����� ����
	newStack = makeStack(); //�ʱ�ȭ.


	char element; //express ���ڿ��� �� ���ھ� �޾ƿ�.
	char pop; //popStack�� ���ؼ� �޾ƿ� ���ڿ��� ����.

	int length = strlen(express); //���ڿ� ���̸� �޾� �� Ƚ����ŭ ���� ������ ����.
	char* exchange = (char*)malloc(length + 1); //express �迭�� ũ�� �����Ҵ��� ����. ���ڿ��� ���̴� ������ ����. �迭 ����.
	int index = 0; //���縦 ���� ����.
	memset(exchange, 0, sizeof(char) * length + 1); //0���� �ʱ�ȭ


	for (int i = 0; i < length; i++)
	{
		element = express[i]; //ó������ ��Ҹ� �޾ƿ�.

		if (isdigit(element)) //�޾ƿ� ��Ұ� �����ΰ�? 
		{
			exchange[index++] = element; //index��ġ�� ���� �� index++ ����.
		}
		else//���ڰ� �ƴϸ�
		{
			switch (element)
			{
			case'(':
			{
				push_Stack(newStack, element); //���ÿ� ����.
				break;
			}
			case')':
			{
				while (1)
				{
					pop = pop_Stack(newStack); //������ ��� ��ȯ.
					if (pop == '(') //��ȣ�� ������ ���� ��ȯ�� �ؾ���.
					{
						break;
					}
					exchange[index++] = pop; //pop�� �޾ƿͼ� ����.
				}
				break;

			}
			case'+':
			case'-':
			case'*':
			case'/':
			{
				//�������� �����ں��� ������ �������� �ִ� �����ڰ� �� ũ�� ���ÿ� �ִ� �����ڰ� ���;���

				//�������� �����ڿ� ������ �������� �ִ� �����ڸ� �񱳸� ����ؼ� �������� �����ڰ� �� Ŭ ������ �񱳸� �ؾ���.
				// &&������ ������ �����ڿ�, ���� ���� �������� �켱 ���� ��, whoBig�� ���� peek�� ũ�� 1, ������ 0�� ��ȯ����.
				//isEmpty()�� ������ ������� Ȯ��.
				while (!is_Empty(newStack) && who_Big(peek_Stack(newStack), element) >= 0)
				{
					exchange[index++] = pop_Stack(newStack);
				}
				//�������� �����ڰ� �� ũ�� �״�� �׾Ƶ� ��.
				push_Stack(newStack, element);
				break;
			}
			}

		}
	}
	while (!is_Empty(newStack)) //!�� ���� ������ , ��������� isEmpty 1�� ��ȯ. ���������� 0�� ��ȯ�ϴµ� �����־�� ������ ����Ǳ� ����.
	{
		exchange[index++] = pop_Stack(newStack); //���ÿ� ���� �͵��� ��� �־���.
	}
	//strcpy(express,exchange); ���� �б� �����̶� strcpy��� �Ұ�.
	return exchange;
}


int evalPostfix(char* express)
{
	char element; //��Ҹ� �ϳ��� ������ �� ���.
	stack* newStack; //���꿡 ���Ǵ� ����.
	newStack = makeStack(); //�ʱ�ȭ

	int length = strlen(express);

	char popA, popB; //������ �� �� pop�� �޾� ������ ����
	for (int i = 0; i < length; i++)
	{
		element = express[i];
		if (isdigit(element))
		{
			push_Stack(newStack, element - '0'); //���� ���ڿ��� ���ڷ� ������ֱ� ���ؼ�.

		}
		else {
			popB = pop_Stack(newStack); //���� ��ȯ.

			popA = pop_Stack(newStack); //���� ��ȯ.

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
