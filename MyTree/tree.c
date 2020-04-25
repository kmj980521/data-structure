#include<stdio.h>
#include<stdlib.h>

#include"treestack.h"




TreeNode* makeTreeNode(void)
{
	TreeNode* newTree = (TreeNode*)malloc(sizeof(TreeNode));
	newTree->left = NULL;
	newTree->right = NULL;
	return newTree;
}



int getElement(TreeNode* input)
{
	return input->element;
}
void setElement(TreeNode* input, int element)
{
	input->element = element;
}
TreeNode* getLeft(TreeNode* input)
{
	return input->left;
}
TreeNode* getRight(TreeNode* input)
{
	return input->right;
}
void MakeLeftSubTree(TreeNode* main, TreeNode* sub)
{
	if (main->left != NULL)
	{
		free(main->left);
	}
	main->left = sub;
}
void MakeRightSubTree(TreeNode* main, TreeNode* sub)
{
	if (main->right != NULL)
	{
		free(main->right);
	}
	main->right = sub;
}
typedef void (*VisitFunc)(int element);
void InorderTraverse(TreeNode* main, VisitFunc action) //중위
{
	if (main == NULL)
	{
		return;
	}
	InorderTraverse(main->left, action);
	action(main->element);
	InorderTraverse(main->right, action);
}
void PostorderTraverse(TreeNode* main, VisitFunc action) //후위
{
	if (main == NULL)
	{
		return;
	}
	PostorderTraverse(main->left, action);
	PostorderTraverse(main->right, action);
	action(main->element);
}
void PreorderTraverse(TreeNode* main, VisitFunc action) //전위
{
	if (main == NULL)
	{
		return;
	}
	action(main->element);
	PreorderTraverse(main->left, action);
	PreorderTraverse(main->right, action);
}
