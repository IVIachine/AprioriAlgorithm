#include "header.h"
#include <fstream>

void mainMenu()
{
	string fileName = "";
	cout << "Please enter the file you would like to load in: ";
	getline(cin, fileName);

	ifstream fin("dataset/" + fileName);

	if (!fin.good())
	{
		mainMenu();
	}
	else
	{
		
	}
}

LinkedList<int> reverseFunction(ObjectList* list)
{
	LinkedList<int> result;
	
	int lSize = list->size();
	
	cout
		<< "\n"
		<< "List size: " << lSize
		<< "\n";

	for (int i = 0; i < list->size(); i++)
	{
		int aSize = list->getData(i).arraySize;

		cout
			<< "\n"
			<< "Array " << i << " size: " << aSize
			<< "\n";
	}

	return result;
}