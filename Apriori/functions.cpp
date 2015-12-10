#include "header.h"
#include <fstream>
#include <sstream>

void mainMenu()
{
	string fName = "T5.N0.1K.D1K"; // <- so we don't have to type it in while debugging

	//print("Please enter the file you would like to load in: ");
	//getline(cin, fName);

	ifstream file("dataset/" + fName + ".txt");

	if (!file.good())
	{
		mainMenu();
	}
	else
	{
		int numTrans = getTransNum(fName);

		if (numTrans == -1)
		{
			file.close();
			return;
		}

		LinkedList<int> *transactions = new LinkedList<int>[numTrans](); //Array of linked lists

		cout
			<< "The file, " << fName << ", was found." << "(" << numTrans / 1000 << "K transactions) \n"
			<< "\nLoading data. \n";

		int cur, next, item;

		while (!file.eof())
		{
			file >> cur;
			file >> item;

			transactions[cur - 1].insertSorted(item);
		}

		for (int i = 0; i < numTrans; i++)
		{
			cout << "[" << i + 1 << "] ";
			transactions[i].display();
		}


		pause();
		file.close();
		delete[] transactions;
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
			{
				is_k_found = true;
			}
		}

		istringstream(tmp) >> numTransactions;

		if (is_k_found)
		{
			numTransactions = numTransactions * 1000;
		}

		return numTransactions;

	}
	else
	{
		return -1;
	}
}

bool isDigit(char c)
{
	// return isdigit(c);
	// lol

	return ('0' <= c && c <= '9');
}