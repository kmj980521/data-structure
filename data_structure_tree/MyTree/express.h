#ifndef Expression

#include"tree.h"
TreeNode* MakeExpTree(char* express); //후위 표기법으로 변형 된 문자열을 받아 트리를 만들고 루트 노드 반환

int EvaluateExpTree(TreeNode* main); //루트 노드의 주소를 받아 수식을 계산.

void showNodeData(int data);

void showInfix(TreeNode* main); //MakeExpTree가 제대로 변환되었는지. 중위 표기 기반 출력
void showPrefix(TreeNode* main); // 전위 표기 기반 출력
void showPostfix(TreeNode* main); // 후위 표기 기반 출력


#endif // !Expression

