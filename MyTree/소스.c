#include<stdio.h>
#include<stdlib.h>
#include"express.h"
#include"stack.h"
int main()
{
	char* express = "(1+2)*7";
	express= infixToPostfix(express);
	TreeNode* myTree = MakeExpTree(express);

	printf("전위표기법: ");
	showPrefix(myTree);
	printf("\n");
	printf("중위표기법: ");
	showInfix(myTree);
	printf("\n");
	printf("후위표기법: ");
	showPostfix(myTree);
	printf("\n");
	printf("접근\n");
	printf("연산의 결과 : %d \n", EvaluateExpTree(myTree));
	return 0;
}