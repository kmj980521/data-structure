#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include"treestack.h"
#include"tree.h"
TreeNode* MakeExpTree(char express[]) //후위 표기법으로 변형 된 문자열을 받아 트리를 만들고 루트 노드 반환
{
	Stack* newStack;
	newStack = makeStackTree();

	TreeNode* result;
	int length = strlen(express);
	char element;
	for (int i = 0; i < length; i++)
	{
		result = makeTreeNode(); //노드를 생성
		element = express[i];
		if (isdigit(element)) //숫자면
		{
			setElement(result, element - '0'); //숫자로 저장
		}
		else {
			MakeRightSubTree(result, popStack(newStack)); //꺼내와서 오른쪽으로
			MakeLeftSubTree(result, popStack(newStack)); //꺼내와서 왼쪽으로
			setElement(result, element);
		}
		pushStack(newStack, result);
	}
	return popStack(newStack);
}
int EvaluateExpTree(TreeNode* main) //루트 노드의 주소를 받아 수식을 계산.
{
	int op1, op2;
	if (getLeft(main) == NULL && getRight(main)==NULL)
	{
		return getElement(main);
	}
	op1 = EvaluateExpTree(getLeft(main)); //왼쪽 순회
	op2 = EvaluateExpTree(getRight(main)); //오른쪽 순회

	switch (getElement(main)) //사칙연산
	{
	case '+':
		return op1 + op2;
	case'-':
		return op1 - op2;
	case'*':
		return op1 * op2;
	case'/':
		return op1 / op2;
	}
	return 0;
}
void showNodeData(int data)
{
	if (0 <= data && data <= 9)
		printf("%d ", data);
	else
		printf("%c ", data);
}
void showInfix(TreeNode* main) //MakeExpTree가 제대로 변환되었는지. 중위 표기 기반 출력
{
	InorderTraverse(main, showNodeData);
}
void showPrefix(TreeNode* main) // 전위 표기 기반 출력
{
	PreorderTraverse(main, showNodeData);
}
void showPostfix(TreeNode* main) // 후위 표기 기반 출력
{
	PostorderTraverse(main, showNodeData);
}

