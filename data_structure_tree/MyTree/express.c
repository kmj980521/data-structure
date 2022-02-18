#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include"treestack.h"
#include"tree.h"
TreeNode* MakeExpTree(char express[]) //���� ǥ������� ���� �� ���ڿ��� �޾� Ʈ���� ����� ��Ʈ ��� ��ȯ
{
	Stack* newStack;
	newStack = makeStackTree();

	TreeNode* result;
	int length = strlen(express);
	char element;
	for (int i = 0; i < length; i++)
	{
		result = makeTreeNode(); //��带 ����
		element = express[i];
		if (isdigit(element)) //���ڸ�
		{
			setElement(result, element - '0'); //���ڷ� ����
		}
		else {
			MakeRightSubTree(result, popStack(newStack)); //�����ͼ� ����������
			MakeLeftSubTree(result, popStack(newStack)); //�����ͼ� ��������
			setElement(result, element);
		}
		pushStack(newStack, result);
	}
	return popStack(newStack);
}
int EvaluateExpTree(TreeNode* main) //��Ʈ ����� �ּҸ� �޾� ������ ���.
{
	int op1, op2;
	if (getLeft(main) == NULL && getRight(main)==NULL)
	{
		return getElement(main);
	}
	op1 = EvaluateExpTree(getLeft(main)); //���� ��ȸ
	op2 = EvaluateExpTree(getRight(main)); //������ ��ȸ

	switch (getElement(main)) //��Ģ����
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
void showInfix(TreeNode* main) //MakeExpTree�� ����� ��ȯ�Ǿ�����. ���� ǥ�� ��� ���
{
	InorderTraverse(main, showNodeData);
}
void showPrefix(TreeNode* main) // ���� ǥ�� ��� ���
{
	PreorderTraverse(main, showNodeData);
}
void showPostfix(TreeNode* main) // ���� ǥ�� ��� ���
{
	PostorderTraverse(main, showNodeData);
}

