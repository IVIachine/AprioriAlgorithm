/*Author: Tyler Chermely, Adam Gurman
Class : CSI - 281 - 03
Assignment : Final Project Implementation
Date Assigned : Thursday, November 19, 2015 11:00AM
Due Date : Due : Saturday, December 12, 2015 11:59PM
Description :
To implement the Apriori algorithm
Certification of Authenticity :
I certify that this is entirely my own work, except where I have given fullydocumented
references to the work of others.I understand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment :
-Reproduce this assignment and provide a copy to another member of
academic staff; and / or
- Communicate a copy of this assignment to a plagiarism checking service
(which may then retain a copy of this assignment on its database for
the purpose of future plagiarism checking)*/

#include "header.h"
#include <fstream>
#include <sstream>

//Purpose: Preforms the necessary loop to gather data before preforming the algorithm
//Pre: Called from main
//Post: Gathers data/runs the algorithm
void mainMenu(bool isStub, bool showDebugInfo)
{
	string fileIn;
	int
		size,
		min;
	
	/*	Initilization
	* * * * * * * * * * * * * * * * * * */
	if (isStub)
	{
		fileIn = "test";
		size = 100;
		min = 10;

		cout
			<< "Running in debug mode."
			<< "\n\n"
			<< space() << "Program will use '" << fileFormat(fileIn) << "'."
			<< "\n\n"
			<< space() << "The test file has " << size << " transactions. A minumum support of " << min << " will be used."
			<< "\n";
	}
	else
	{
		fileIn = getString("Please enter the file you would like to load in: ");
		size = getTransNum(fileIn);
		min = getInt("Please enter the minimum support: ");
	}

	TimerSystem timer;
	double time;

	cout.precision(3);

	/*	Load Data
	* * * * * * * * * * * * * * * * * * */
	cout
		<< "\n"
		<< "Loading data... ";

	timer.startClock();
	LinkedList<int>* data = loadData(fileIn, size, isStub, showDebugInfo);
	time = timer.getTime();
	
	cout
		<< (showDebugInfo ? "\n" : "Done")
		<< "\n"
		<< "Operation took (" << time << ") seconds to complete."
		<< "\n\n\n";


	/*	Apriori Algorithm
	* * * * * * * * * * * * * * * * * * */
	cout << "Running Apriori Algorithm...";

	timer.startClock();
	ObjectList result = aprioriAlgorithm(data, size, min, showDebugInfo);
	time = timer.getTime();

	cout
		<< (showDebugInfo ? "\n" : "Done")
		<< "\n"
		<< "Operation took (" << time << ") seconds to complete."
		<< "\n\n"
		<< "Total number of combinations generated: " << result.size() << " "
		<< "\n\n"
		<< "Results can be found in 'result.txt'";

	pause();

	delete[] data;
}

//Purpose: Load the data from the file into a hash table
//Pre: Filename passed in
//Returns a hash table with all the values or calls the main menu function
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
				<< space() << "The file, '" << fileFormat(fName) << "', was found. (" << size << " transactions)";
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

//Purpose: To change the filename to desired file format
//Pre: None
//Post: Returns the correct file format string
string fileFormat(string fName)
{
	return "dataset/" + fName + ".txt";
}

//Purpose: To get the number of transactions in a file based on its name
//Pre: filename passed in
//Post: The number of transactions is returned
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

//Purpose: Check if a character is an int
//Pre: Character passed in
//Post: Returns if it is an int or not
bool isDigit(char c)
{
	return ('0' <= c && c <= '9');
}

//Purpose: To write the results to a text file
//Pre: The results list has data
//Post: Writes the results to results.txt
void writeToFile(string fName, ObjectList theResult)
{
	ofstream of;
	of.open("results_" + fName + ".txt");
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