#ifndef Header___sa
#include"tree.h"

typedef struct StackNode {
	TreeNode* element;
	struct StackNode* next_link;
}Node;

typedef struct MyStack
{
	Node* last_node;
}Stack;

Stack* makeStackTree();
int isEmpty_stack(Stack* input);

void pushStack(Stack* input, TreeNode* element);
TreeNode* popStack(Stack* input);
TreeNode* peekStack(Stack* input);





#endif // !Header___sa

#pragma once
