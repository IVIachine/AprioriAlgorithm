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

LinkedList<int> reverseFunction(ObjectList* list, int k)
{
	LinkedList<int> result;
	
	int x = list->getData(0).myArray[0];

	int i, j;
	for (i = 0; i < list->size(); i++)
	{
		

		for (j = 0; j < k; j++)
		{
			
		}
	}

	return result;
}