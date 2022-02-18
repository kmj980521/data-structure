#include<stdio.h>
#include<stdlib.h>
#include"express.h"
#include"stack.h"
int main()
{
	char* express = "(1+2)*7";
	express= infixToPostfix(express);
	TreeNode* myTree = MakeExpTree(express);

	printf("����ǥ���: ");
	showPrefix(myTree);
	printf("\n");
	printf("����ǥ���: ");
	showInfix(myTree);
	printf("\n");
	printf("����ǥ���: ");
	showPostfix(myTree);
	printf("\n");
	printf("����\n");
	printf("������ ��� : %d \n", EvaluateExpTree(myTree));
	return 0;
}