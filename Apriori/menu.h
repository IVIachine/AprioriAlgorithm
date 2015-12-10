#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

typedef void(*FUNC_PTR)(void);
void execute(FUNC_PTR func);

void	clear();
void	errorMessage(string message);
void	errorMessage(string message, FUNC_PTR fallBack);
int		getInt();
bool	isNumber(string str);
void	pause();
void	print(char* text);
void	printl(char* text);

class Menu
{
private:
	struct Option
	{
		string mText;
		FUNC_PTR mFunc;

		Option(string text, FUNC_PTR func)
		{
			mText = text;
			mFunc = func;
		}
	};

public:
	Menu();
	~Menu();

	void	main();
	void	load();
};