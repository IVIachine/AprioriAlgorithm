#include "header.h"

int main()
{
	int K = 3;
	LinkedList<int> data = LinkedList<int>();

	int num = 100;
	for (int i = 0; i < num; i++)
	{
		data.insertSorted(1 + rand() % num);
	}


	//mainMenu();
	ObjectList list = genAll(data, K);

	cout
		<< "\n"
		<< "Subsets generated."
		<< "\n\n";

	//list.display();
	
	cout
		<< list.getData(32).myArray[2];
	
	system("pause");

	return 0;
} 