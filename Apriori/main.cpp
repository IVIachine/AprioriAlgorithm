#include "header.h"

int main()
{
	int K = 2;
	LinkedList<int> data = LinkedList<int>();

	data.insertSorted(22);
	data.insertSorted(65);
	data.insertSorted(122);
	data.insertSorted(3);
	data.insertSorted(4);
	data.insertSorted(55);


	//mainMenu();
	ObjectList list = genAll(data, K);

	cout
		<< "\n"
		<< "Subsets generated."
		<< "\n\n";

	list.display();
	
	system("pause");

	return 0;
} 