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

#include "helper.h"

//Purpose: To clear the screen
//Pre: None
//Pose: The screen is cleared
void clear()
{
	system("cls");
}

//Purpose: To validate user integer input
//Pre: None
//Post: Validates the input and returns the int
int getInt(string message)
{
	string str;
	
	do
	{
		cout << message;

		getline(cin, str);

	} while (!isNumber(str));

	return stoi(str);
}

//Purpose: To validate user string input
//Pre: None
//Post: Validates the input and returns the string
string getString(string message)
{
	string str = "";
	
	cout << message;

	getline(cin, str);
	
	return str;
}

//Purpose: To check whether or not a string is completely a number
//Pre: Function called with string passed in
//Post: Returns whether or not the string is a number
bool isNumber(string str)
{
	for (auto i = str.begin(); i != str.end(); i++)
	{
		if (!isdigit(*i))
			return false;
	}

	return true;
}

//Purpose: To display a line of a certain length for the bar
//Pre: All necessary arguments passed in
//Post: The line is displayed
string line(char c, int length, bool newLine)
{
	string txt = "";

	if (newLine)
		cout << endl;

	for (int i = 0; i < length; i++)
		txt += c;

	if (newLine)
		cout << endl;

	return txt;
}

//Purpose: To pause the program
//Pre: None
//Post: The program is paused
void pause()
{
	cout << "\n\n";
	system("pause");
}

//Purpose: To display the progress bar
//Pre: None
//Post: The progress bar is displayed
//Cite: http://stackoverflow.com/questions/16635787/making-a-console-progress-bar-windows
void showProgress(float progress, int maxWidth, int hSpacing)
{
	int percent = progress * 100;
	int width = progress * maxWidth;

	cout
		<< "\r"
		<< space(hSpacing)
		<< percent << "% " << string(width, '|') << string(maxWidth - width, '-');

	cout.flush();
}

//Purpose: To tab a certain amount of time
//Pre: Function called with int passed in
//Post: The console has that int number of tabs added
string space(int numTabs)
{
	string spacing = "";

	for (int i = 0; i < numTabs; i++)
		spacing += "\t";

	return spacing;
}