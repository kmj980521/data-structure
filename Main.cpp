#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "ListSource.h"

using namespace std;
int main()
{
	List list1;
	int data; // 입력받을 값
	Listin(&list1);


	insert(&list1, 11); insert(&list1, 22);
	insert(&list1, 33); insert(&list1, 44);
	insert(&list1, 55); insert(&list1, 66);

	cout << "현재 데이터의 수는 " << LCount(&list1) << "개 입니다" << endl;

	if (LFirst(&list1, &data))
	{
		cout << data<<" ";

		while (move(&list1, &data))
			cout << data << " ";
	}

	if (LFirst(&list1, &data))
	{
		if (data % 22 == 0)
			LRemove(&list1);
		while (move(&list1, &data))
			if(data % 22 == 0)
				LRemove(&list1);

	}

	cout << "현재 데이터의 수는 " << LCount(&list1) << "개 입니다" << endl;

	if (LFirst(&list1, &data))
	{
		cout << data << " ";

		while (move(&list1, &data))
			cout << data << " ";
	}

	return 0;
}
