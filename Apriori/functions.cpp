#include "header.h"


void mainMenu()
{
	string fileName = "";
	cout << "Please enter the file you would like to load in: ";
	getline(cin, fileName);

	ifstream fin(fileName);

	if (!fin.good())
	{
		cout << "Please enter a valid file";

		mainMenu();
	}
	else
	{
		cout << "good";
	}
}
