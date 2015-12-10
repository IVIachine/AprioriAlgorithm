#include "header.h"
#include <fstream>
#include <sstream>

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
		fin.close();



		int transNum = getTransNum(fileName);
		if (transNum == -1)
			return;

		LinkedList<int> *theArray = new LinkedList<int>[transNum](); //Array of linked lists

		fin.open("dataset/" + fileName);

		int currentTransaction, currentItem, nextTransaction;
		bool isSameTransaction = true;
		fin >> currentTransaction;
		while (!fin.eof())
		{
			while (isSameTransaction)
			{
				cout << "HERE" << endl;
				fin >> currentItem;
				fin >> nextTransaction;
				if (nextTransaction != currentTransaction)
				{
					isSameTransaction = false;
					break;
				}
				theArray[currentTransaction].insertSorted(currentItem);
			}
			fin >> currentTransaction;
			isSameTransaction = true;
		}


	}
}

int getTransNum(string fileName)
{
	string tmp = "";
	int numTransactions = 0;
	bool found = false;
	bool is_k_found = false;
	int i;
	for (i = 0; i < fileName.length(); i++)
	{
		if (fileName[i] == 'D')
		{
			found = true;
			break;
		}
	}
	if (found)
	{
		for (int j = i + 1; j < fileName.length(); j++)
		{
			if (isDigit(fileName[j]))
			{
				tmp.push_back(fileName[j]);
			}
			else if (fileName[j] == 'K')
				is_k_found = true;
		}
		istringstream(tmp) >> numTransactions;

		if (is_k_found)
			numTransactions = numTransactions * 1000;

		return numTransactions;

	}
	else
		return -1;
}

bool isDigit(char c)
{
	return ('0' <= c && c <= '9');
}