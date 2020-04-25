#ifndef MY___Node___
#define MY___Node___



typedef struct MY_TreeNode
{
	int element;
	struct MY_TreeNode* left;
	struct MY_TreeNode* right;
}TreeNode;

TreeNode* makeTreeNode(void);
int getElement(TreeNode* input);
void setElement(TreeNode* input, int element);

TreeNode* getLeft(TreeNode* input);
TreeNode* getRight(TreeNode* input);

void MakeLeftSubTree(TreeNode* main, TreeNode* sub);
void MakeRightSubTree(TreeNode* main, TreeNode* sub);

typedef void (*VisitFunc)(int element);

void InorderTraverse(TreeNode* main, VisitFunc action); //중위
void PostorderTraverse(TreeNode* main, VisitFunc action);//후위
void PreorderTraverse(TreeNode* main, VisitFunc action); //전위

#endif // !MY___Node___
