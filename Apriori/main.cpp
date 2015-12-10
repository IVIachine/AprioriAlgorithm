#include "header.h"

int main()
{
	int K = 3;
	LinkedList<int> data = LinkedList<int>();

	int num = 5;
	for (int i = 0; i < num; i++)
	{
		data.insertSorted(1 + rand() % num);
	}


	//mainMenu();
	ObjectList list = genAll(data, K);

	reverseFunction(&list);

	//list2.display();
	
	system("pause");

	return 0;
} 