#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
	char element;
	struct TreeNode* left;
	struct TreeNode* right;
}Node;


Node* makeNode(Node* Left,Node* Right, char element)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->left = Left;
	newnode->right = Right;
	newnode->element=element;

	return newnode;
}
Node* getLeft(Node* main) //왼쪽 노드 얻기.
{
	return main->left;
}
Node* getRight(Node* main) //오른쪽 노드 얻기.
{
	return main->right;
}
char getData(Node* main)
{
	return main->element;
}
void TraverInfix(Node* main) //중위
{
	if (main == NULL)
	{
		return;
	}
	TraverInfix(main->left);
	printf("%c ", main->element);
	TraverInfix(main->right);
}
void TraverPostfix(Node* main) //후위
{
	if (main == NULL)
	{
		return;
	}
	TraverPostfix(main->left);
	TraverPostfix(main->right);
	printf("%c ", main->element);
}
void TraverPrefix(Node* main) //전위
{
	if (main == NULL)
	{
		return;
	}

	printf("%c ", main->element);
	TraverPrefix(main->left);
	TraverPrefix(main->right);
}

int getNodeCount(Node* main)
{
	int count = 0;
	
	if (main != NULL)
	{
		count = 1 + getNodeCount(main->left) + getNodeCount(main->right); //NULL이 아니면 자기 자신 1 + 왼쪽 트리, 오른쪽 트리 참조하여 계산.
	}
	return count;
}

int getLeafNode(Node* main) //단말 노드의 수 
{
	int leaf_count = 0;

	if (main != NULL)
	{
		if (main->left == NULL && main->right == NULL) //왼쪽, 오른쪽 트리가 비어있으면 단말 노드.
		{
			return 1;
		}
		else
		{
			leaf_count = getLeafNode(main->left) + getLeafNode(main->right); //왼쪽, 오른쪽 트리참조 및 단말 노드 확인
		}
	}

	return leaf_count;
}
int getTreeHeight(Node* main)
{
	int tree_height = 0;
	if (main != NULL)
	{
		int a = getTreeHeight(main->left);
		int b = getTreeHeight(main->right);

		if (a > b)
		{
			tree_height = 1 + a;
		}
		else
		{
			tree_height = 1 + b;
		}
		
	}
	return tree_height;
}
int main()
{  //제일 밑 레벨의 노드
	Node* Node_K = makeNode(NULL,NULL,'K'); //왼쪽노드, 오른쪽노드, 데이터필드의 값
	Node* Node_J = makeNode(NULL, NULL, 'J');
	Node* Node_I = makeNode(NULL, NULL, 'I');
	Node* Node_H = makeNode(NULL, NULL, 'H');

	//중간 레벨 노드
	Node* Node_D = makeNode(Node_H,NULL,'D');
	Node* Node_E = makeNode(Node_I,Node_J,'E');
	Node* Node_F = makeNode(NULL,NULL,'F');
	Node* Node_G = makeNode(NULL,Node_K,'G');
	
	Node* Node_B = makeNode(Node_D,Node_E,'B');
	Node* Node_C = makeNode(Node_F,Node_G,'C');

	//루트노드
	Node* Node_A = makeNode(Node_B,Node_C,'A');
	
	printf("preorder : ");
	TraverPrefix(Node_A); //전위
	printf("\n");

	printf("indorder : ");
	TraverInfix(Node_A); //중위
	printf("\n");

	printf("postorder : ");
	TraverPostfix(Node_A);
	printf("\n");

	printf("이진 트리 노드 개수는 %d개 입니다.\n", getNodeCount(Node_A));
	printf("이진 트리 단말 노드 개수는 %d개 입니다. \n", getLeafNode(Node_A));

	printf("이진 트리의 높이는 %d입니다.\n", getTreeHeight(Node_A));
	
	
	return 0;
}
