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