#include<stdio.h>
#include<stdlib.h>
#include "treestack.h"



Stack* makeStackTree(void)
{
	Stack* newStack = (Stack*)malloc(sizeof(Stack));
	newStack->last_node = NULL;
	
	return newStack;
}

void pushStack(Stack* input, TreeNode* element)
{
	if (input->last_node == NULL) //비어있으면
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->element = element;
		input->last_node = newNode;
		newNode->next_link = NULL;
	}
	else
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->element = element;
		newNode->next_link = input->last_node;
		input->last_node = newNode;
	}
}
TreeNode* popStack(Stack* input)
{
	if (input->last_node == NULL)
	{
		printf("스택이 비었습니다.\n");
		exit(-1);
	}
	else
	{
		TreeNode* del;
		Node* delnode = (Node*)malloc(sizeof(Node));
		delnode = input->last_node;
		del = input->last_node->element;


		input->last_node = input->last_node->next_link; //그 전 링크로 이동
		free(delnode);
		return del;
	}
}
int isEmpty_stack(Stack* input)
{
	if (input->last_node == NULL)
	{
		return 1;
	}
	return 0;
}
TreeNode* peekStack(Stack* input)
{
	if (isEmpty_stack(input) == 1)
	{
		printf("스택이 비어있습니다\n");
		exit(-1);
	}
	return input->last_node->element;
}

