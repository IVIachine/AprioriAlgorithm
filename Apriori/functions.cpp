#include "header.h"
#include <fstream>
#include <sstream>

void mainMenu()
{
	//string fName = "T5.N0.1K.D1K"; // <- so we don't have to type it in while debugging
	string fName = "test";
	//fName = getString("Please enter the file you would like to load in: ");

	LinkedList<int>* data = loadData(fName, false, false);	

	TimerSystem timer;

	timer.startClock();
	ObjectList result = aprioriAlgorithm(data, 500, 10);
	double time = timer.getTime();

	result.display();

	cout 
		<< "Done. Operation took " << time << "s to complete.";

	pause();

	delete[] data;
}

LinkedList<int>* loadData(string fName, bool showMessages, bool showResults)
{
	ifstream file("dataset/" + fName + ".txt");

	if (!file.good())
	{
		cout
			<< "The requested file could not be found. Redirecting to main menu.";

		pause();

		mainMenu();
	}
	else
	{
		int numTrans = 500;

		if (numTrans == -1)
		{
			file.close();
			return NULL;
		}

		LinkedList<int>* transactions = new LinkedList<int>[numTrans](); //Array of linked lists

		if (showMessages)
		{
			// Display that the file was found
			// and how many entries it has
			cout
				<< "The file, " << fName << ", was found." << "(" << numTrans / 1000 << "K transactions) \n"
				<< "\nLoading data. \n\n";
		}

		int trans, item;

		// Load data and insert into lists
		while (!file.eof())
		{
			file >> trans;
			file >> item;

			transactions[trans - 1].insertSorted(item);
		}

		if (showMessages)
		{
			cout << "Loading complete. " << (showResults ? " Displaying results... \n\n" : "");

			// Print everything when it's complete
			if (showResults)
			{
				for (int i = 0; i < numTrans; i++)
				{
					cout << "[" << i + 1 << "] ";
					transactions[i].display();
				}
			}
		}

		file.close();
		
		return transactions;
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