#include "header.h"
#include <fstream>
#include <sstream>

void mainMenu(bool isStub, bool showDebugInfo)
{
	string fName;
	int size;
	int min;
	
	if (isStub)
	{
		fName = "test";
		size = 100;
		min = 10;

		cout
			<< "Running in debug mode."
			<< "\n\n"
			<< space() << "Program will use '" << fileFormat(fName) << "'."
			<< "\n\n"
			<< space() << "The test file has " << size << " transactions. A minumum support of " << min << " will be used."
			<< "\n";
	}
	else
	{
		fName = getString("Please enter the file you would like to load in: ");
		size = getTransNum(fName);
		min = getInt("Please enter the minimum support: ");
	}

	TimerSystem timer;
	double time;

	cout.precision(5);

	cout
		<< "\n"
		<< "Loading data... ";

	timer.startClock();
	LinkedList<int>* data = loadData(fName, size, isStub, showDebugInfo);
	time = timer.getTime();
	
	cout
		<< (showDebugInfo ? "\n" : "Done")
		<< "\n"
		<< "Operation took (" << time << ") seconds to complete."
		<< "\n\n\n";

	cout
		<< "Running Apriori Algorithm"
		<< (showDebugInfo ? "" : "... ");

	timer.startClock();
	ObjectList result = aprioriAlgorithm(data, size, min, showDebugInfo);
	time = timer.getTime();

	cout
		<< (showDebugInfo ? "\n" : "Done")
		<< "\n"
		<< "Operation took (" << time << ") seconds to complete."
		<< "\n\n"
		<< "Results can be found in 'result.txt'";


	writeToFile(result);

	pause();

	delete[] data;
}

LinkedList<int>* loadData(string fName, int size, bool isStub, bool showDebugInfo)
{
	ifstream file(fileFormat(fName));

	if (!file.good())
	{
		if (showDebugInfo)
		cout
			<< space() << "The requested file could not be found.";

		pause();

		mainMenu(isStub, showDebugInfo);
	}
	else
	{
		if (size == -1)
		{
			file.close();
			return NULL;
		}

		LinkedList<int>* transactions = new LinkedList<int>[size](); //Array of linked lists

		if (showDebugInfo)
		{
			// Display that the file was found
			// and how many entries it has
			if (showDebugInfo)
				cout
				<< "\n\n"
				<< space() << "The file, " << fileFormat(fName) << ", was found. (" << size << " transactions)";
		}

		int trans, item;

		// Load data and insert into lists
		while (!file.eof())
		{
			file >> trans;
			file >> item;

			transactions[trans - 1].insertSorted(item);
		}

		file.close();
		
		return transactions;
	}
}

string fileFormat(string fName)
{
	return "dataset/" + fName + ".txt";
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

void writeToFile(ObjectList theResult)
{
	ofstream of;
	of.open("results.txt");
	if (!of.fail())
	{
		for (int i = 0; i < theResult.size(); i++)
		{
			for (int j = 0; j < theResult[i].size; j++)
			{
				of << theResult[i].data[j] << " ";
			}
			of << endl;
		}
	}
	else
	{
		cout << "File not found, exiting..." << endl;
		exit(1);
	}
}