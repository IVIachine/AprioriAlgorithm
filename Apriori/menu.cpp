#include "menu.h"

#pragma region Constructor/Destructor

Menu::Menu()
{

}

Menu::~Menu()
{

}

#pragma endregion

#pragma region Private Functions

void Menu::clear()
{
	system("cls");
}

void Menu::errorMessage(string message)
{
	clear();

	cout << message;

	pause();

	exit(0);
}

int Menu::getSelection(string str)
{

}

bool Menu::isNumber(string str)
{
	for (auto i = str.begin(); i != str.end(); i++)
	{
		if (!isdigit(*i))
			return false;
	}

	return true;
}

void Menu::pause()
{
	system("pause");
}

void Menu::print(char* text)
{
	printf(text);
}

void Menu::printl(char* text)
{
	printf("\n");
	printf(text);
}

#pragma endregion

#pragma region Public Functions

void Menu::main()
{
	printl("Please select and option from the list below.");
}

void Menu::load()
{
	string fileName = "";
	printf("Please enter the file you would like to load in: ");
	getline(cin, fileName);

	ifstream fin("dataset/" + fileName);

	if (!fin.good())
	{
		main();
	}
	else
	{

	}
}

#pragma endregion