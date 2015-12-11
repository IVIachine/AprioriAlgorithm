#include "helper.h"

void clear()
{
	system("cls");
}

int getInt(string message)
{
	string str;
	
	do
	{
		cout 
			<< endl 
			<< message;

		getline(cin, str);

	} while (!isNumber(str));

	return stoi(str);
}

string getString(string message)
{
	string str = "";
	
	cout
		<< endl
		<< message;

	getline(cin, str);
	
	return str;
}

bool isNumber(string str)
{
	for (auto i = str.begin(); i != str.end(); i++)
	{
		if (!isdigit(*i))
			return false;
	}

	return true;
}

void pause()
{
	cout << "\n\n";
	system("pause");
}

string tab(int num)
{
	string tabs = "";

	for (int i = 0; i < num; i++)
		tabs += "\t";

	return tabs;
}

void showProgress(float progress, int maxWidth)
{
	int percent = progress * 100;
	int width = progress * maxWidth;

	for (int i = 0; i < percent; i++)
	{
		cout
			<< "\r"
			<< percent << "% [" << string(width, '*') << string(maxWidth - width, ' ') << "]"
			<< flush;
	}
}