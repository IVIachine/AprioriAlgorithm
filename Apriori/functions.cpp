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

LinkedList<int> reverseFunction(ObjectList list)
{
	for (int i = 0; i < list.size(); i++)
	{
		for (int j = 0; )
	}
}