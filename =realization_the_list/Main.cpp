#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "ListSource.h"

using namespace std;
int main()
{
	List list1; // Generate a list
	int data; // Value to receive input
	Listin(&list1); // initialization list


	insert(&list1, 11); insert(&list1, 22); // input the data
	insert(&list1, 33); insert(&list1, 44); // input the data
	insert(&list1, 55); insert(&list1, 66); // input the data

	cout << "현재 데이터의 수는 " << LCount(&list1) << "개 입니다" << endl;

	if (LFirst(&list1, &data)) //reference the data
	{
		cout << data<<" ";

		while (move(&list1, &data))
			cout << data << " ";
	}

	if (LFirst(&list1, &data)) //delete the data
	{
		if (data % 22 == 0)// Delete the data value named 22 
			LRemove(&list1);
		while (move(&list1, &data))
			if(data % 22 == 0)
				LRemove(&list1);

	}

	cout << "\n현재 데이터의 수는 " << LCount(&list1) << "개 입니다" << endl;

	if (LFirst(&list1, &data)) //reference the data
	{
		cout << data << " ";

		while (move(&list1, &data))
			cout << data << " ";
	}

	return 0;
}
