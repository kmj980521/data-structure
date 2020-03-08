#include <iostream>
#include "ArrayBaseStack.h"

using namespace std;

int main()
{
	Stack stack1;

	StackInit(&stack1);

	SPush(&stack1, 1); SPush(&stack1, 2);
	SPush(&stack1, 3); SPush(&stack1, 4);
	SPush(&stack1, 5); SPush(&stack1, 6); // 스택에 1~6저장

	LookStack(&stack1);

	while (!SIsEmpty(&stack1))
	{
		cout << "꺼낸 값은" << SPop(&stack1) << "입니다 " << endl;
	}
	return 0;

}
