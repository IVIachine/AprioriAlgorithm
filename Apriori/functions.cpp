#include "header.h"

void mainMenu()
{
	string fileName = "";
	cout << "Please enter the file you would like to load in: ";
	cin >> fileName;
	ifstream fin(fileName);
	do
	{
	cout << "Please enter valid file name: ";
	cin >> fileName;
	fin.open(fileName);
	} while (fin.fail());
}