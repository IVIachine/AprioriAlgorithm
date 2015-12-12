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
		cout << message;

		getline(cin, str);

	} while (!isNumber(str));

	return stoi(str);
}

string getString(string message)
{
	string str = "";
	
	cout << message;

	getline(cin, str);
	
	return str;
}

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

string space(int numTabs)
{
	string spacing = "";

	for (int i = 0; i < numTabs; i++)
		spacing += "\t";

	return spacing;
}

string space(int numTabs, char c)
{
	string spacing = "";

	for (int i = 0; i < numTabs * 8; i++)
		spacing += c;

	return spacing;
}

void showProgress(float progress, int maxWidth, int hSpacing)
{
	int percent = progress * 100;
	int width = progress * maxWidth;

	cout
		<< "\r"
		<< space(hSpacing)
		<< percent << "% " << string(width, '|') << string(maxWidth - width, '-') << "";

	cout.flush();

	// Tester
	/*
	float p = 0;
	while(p <= 1)
	{
		p += 0.05;
		showProgress(p, 50);
		Sleep(60);
	}

	pause();
	*/
}