#include "header.h"

#include "menu.h"

int main()
{
	srand(time(NULL));

	int K = 3;
	LinkedList<int> data = LinkedList<int>();

	int num = 10;
	for (int i = 0; i < num; i++)
	{
		data.insertSorted(1 + rand() % num);
	}

	ObjectList list = genAll(data, K);

	LinkedList<int> list2 = reverseFunction(list);

	//list2.display();

	Menu menu = Menu();
	menu.main();
	
	system("pause");

	return 0;
} 