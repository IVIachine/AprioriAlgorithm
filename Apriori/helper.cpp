#include "helper.h"

void clear()
{
	system("cls");
}

void errorMessage(string message)
{
	clear();

	cout << message;

	pause();

	exit(0);
}

void errorMessage(string message, FUNC_PTR fallback)
{
	clear();

	cout << message;

	pause();

	execute(fallback);
}

void execute(FUNC_PTR func)
{
	func();
}

int getInt()
{
	string str;
	getline(cin, str);

	if (isNumber(str))
	{
		return stoi(str);
	}

	errorMessage("Please try again, and, this time, enter a number.");

	return 0;
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
	print("\n\n");
	system("pause");
}

void print(char* text)
{
	printf(text);
}

void printl(char* text)
{
	printf("\n");
	printf(text);
}