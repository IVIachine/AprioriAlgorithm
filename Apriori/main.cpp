#include "header.h"
#include "LinkedList.h"

int main()
{
	int K = 4;
	LinkedList<int> *data = new LinkedList<int>();

	data->insertSorted(22);
	data->insertSorted(65);
	data->insertSorted(122);
	data->insertSorted(3);
	data->insertSorted(8);
	data->insertSorted(55);

	mainMenu();
	//LinkedList<LinkedList<int>> list = genAll(data, K);

	//list.display();


	system("pause");

	return 0;
} 