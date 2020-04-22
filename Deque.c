#include <stdio.h>
#include <stdlib.h> //malloc 사용
#include <string.h> //strlen사용
typedef struct Mynode {
	char element;
	struct Mynode* left;
	struct Mynode* right;
}Node;


typedef struct MyDeque {
	Node* front_node;
	Node* rear_node;
	int num;
}Deque;

Deque* makeDeque()
{
	Deque* newDeque;
	newDeque = (Deque*)malloc(sizeof(Deque));
	newDeque->front_node = NULL;
	newDeque->rear_node = NULL;
	newDeque->num = 0;
	return newDeque; 
}

void initDeque(Deque* input , char element) //Deque에 데이터 삽입. 뒤쪽으로 삽입
{
	if (input->front_node == NULL) //공백이였다면
	{
		Node* newnode;
		newnode = (Node*)malloc(sizeof(Node)); //할당
		newnode->element = element;
		newnode->left = NULL;
		newnode->right = NULL;
		input->front_node = newnode;
		input->rear_node = newnode;
		(input->num)++;
	}
	else
	{
		Node* newnode;
		newnode = (Node*)malloc(sizeof(Node)); //할당
		newnode->element = element; //데이터 입력
		newnode->right = NULL; //오른쪽은 NULL
		newnode->left = input->rear_node; //새로운 노드를 기존의 끝에 있던 노드와 이어줌
		input->rear_node->right = newnode; // 기존 마지막 노드의 오른쪽을 새노드와 연결
		input->rear_node = newnode;//마지막을 새노드로 변경
		(input->num)++;
	}
}
int is_Empty(Deque* input)
{
	if (input->front_node == NULL) //비어있음
	{
		return 1;
	}
	else
		return 0;
}
char peek_Rear(Deque* input) //뒤 데이터 참조
{
	if (is_Empty(input))
	{
		printf("덱이 비어있습니다\n");
		return 0;
	}
	return input->rear_node->element;
}

char peek_Front(Deque* input) //앞 데이터 참조
{
	if (is_Empty(input))
	{
		printf("덱이 비어있습니다\n");
		return 0;
	}
	return input->front_node->element;
}

char deleteFront(Deque* input)
{
	if (is_Empty(input)) //비어있음
	{
		printf("덱이 비어있습니다\n");
		return 0;
	}

	Node* newnode;
	char del;
	newnode = input->front_node;
	del = input->front_node->element;
	input->front_node = input->front_node->right; //이동

	free(newnode);
	return del;
	
}

char deleteRear(Deque* input)
{
	if (is_Empty(input)) //비어있음
	{
		printf("덱이 비어있습니다\n");
		return 0;
	}
	Node* newnode;
	newnode = input->rear_node;
	char del;
	del = input->rear_node->element;
	input->rear_node = input->rear_node->left; //왼쪽으로 이동

	free(newnode);
	return del;
}
void Palindrome(char a[])
{

	int length = strlen(a); //문자열 길이 받음
	char element; //하나씩 떼 올 문자
	Deque* myDeque;
	myDeque = makeDeque();
	for (int i = 0; i < length; i++)// 문자열에서 문자를 하나씩 떼서 Deque에 삽입.
	{
		element = a[i];
		if (element !=' ')//공백이 아니면 Deque에 삽입. 빈칸 제거
		{
		initDeque(myDeque, element);
		}
	}
	int count = myDeque->num; //반복문을 돌며 회문(palindrome)체크하기 위해
	char op1, op2; //Deque에서 하나씩 추출
	for(int i = 0; i < count/2; i++) //새로 만든 Deque에 요수 수/2만큼 반복하며 비교
	{
		if(peek_Front(myDeque)==peek_Rear(myDeque)) //앞뒤를 비교해서 같은지 확인
		{
			op1 = deleteFront(myDeque); //앞에서 추출
			op2 = deleteRear(myDeque); //뒤에서 추출
		}
		else
		{
			printf("%s(은)는\n", a);
			printf("회문이 아닙니다\n"); //회문이 아니면 종료
			printf("\n");
			return;
		}
	}
	printf("%s(은)는\n",a);
	printf("회문입니다\n"); //반복문을 다 돌며 무사히 빠져나오면 회문
	printf("\n");
}
int main(){
	
	char str0[] = "madondam"; //회문 x
	char str1[] = "radar"; //회문 o
	char str2[] = "rotavator"; //회문 o
	char str3[] = "madam"; //회문 o
	char str4[] = "was it an cat i saw"; //회문 x
	char str5[] = "a man a plan a canal panama"; //회문 o
	char str6[] = "race car"; //회문 o
	char str7[] = "was it a cat i saw"; //회문 o 
	char str8[] = "nurses run"; //회문 o
	char str9[] = "a man a plan an canal panama"; //회문 x

	// Palindrome checker
	Palindrome(str0);
	Palindrome(str1);
	Palindrome(str2);
	Palindrome(str3);
	Palindrome(str4);
	Palindrome(str5);
	Palindrome(str6);
	Palindrome(str7);
	Palindrome(str8);
	Palindrome(str9);
	return 0;
}


