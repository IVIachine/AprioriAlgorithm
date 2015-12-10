#include "menu.h"

#pragma region Constructor/Destructor

Menu::Menu()
{

}

Menu::~Menu()
{

}

#pragma endregion

#pragma region Menu

void Menu::main()
{
	//printl("Please select and option from the list below.");

	getInt();

	pause();
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