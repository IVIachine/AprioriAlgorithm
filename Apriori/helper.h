#ifndef _HELPER_H_
#define _HELPER_H_

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

typedef void(*FUNC_PTR)(void);

static void clear()
{
	system("cls");
}

static void errorMessage(string message)
{
	clear();

	cout << message;

	pause();

	exit(0);
}

static void errorMessage(string message, FUNC_PTR fallback)
{
	clear();

	cout << message;

	pause();

	execute(fallback);
}

static void execute(FUNC_PTR func)
{
	func();
}

static int getInt()
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

static bool isNumber(string str)
{
	for (auto i = str.begin(); i != str.end(); i++)
	{
		if (!isdigit(*i))
			return false;
	}

	return true;
}

static void pause()
{
	print("\n\n");
	system("pause");
}

static void print(char* text)
{
	printf(text);
}

static void printl(char* text)
{
	printf("\n");
	printf(text);
}

#endif // !_HELPER_H_
