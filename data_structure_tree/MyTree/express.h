#ifndef Expression

#include"tree.h"
TreeNode* MakeExpTree(char* express); //���� ǥ������� ���� �� ���ڿ��� �޾� Ʈ���� ����� ��Ʈ ��� ��ȯ

int EvaluateExpTree(TreeNode* main); //��Ʈ ����� �ּҸ� �޾� ������ ���.

void showNodeData(int data);

void showInfix(TreeNode* main); //MakeExpTree�� ����� ��ȯ�Ǿ�����. ���� ǥ�� ��� ���
void showPrefix(TreeNode* main); // ���� ǥ�� ��� ���
void showPostfix(TreeNode* main); // ���� ǥ�� ��� ���


#endif // !Expression

