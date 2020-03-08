#include <iostream>
#include "ListBaseStack.h"


using namespace std;

int main()
{
	Stack stack2;
	StackInit(&stack2);

	SPush(&stack2, 1);	SPush(&stack2, 2);
	SPush(&stack2, 3); 	SPush(&stack2, 4);
	SPush(&stack2, 5);	SPush(&stack2, 6);

	cout << "현재 저장된 데이터의 갯수는" << SCount(&stack2) << "개 입니다." << endl;
	while (!SIsEmpty(&stack2))
	{
		cout << "제거된 값은" << SPop(&stack2) << "입니다" << endl;
	}
	return 0;
}
