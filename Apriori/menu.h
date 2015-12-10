#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

class Menu
{
private:
	typedef void(*Function) (void);

	struct Option
	{
		string mText;
		Function mFunc;

		Option(string text, Function func)
		{
			mText = text;
			mFunc = func;
		}
	};

	void	clear();
	void	errorMessage(string message);
	int		getSelection(string str);
	bool	isNumber(string str);
	void	pause();
	void	print(char* text);
	void	printl(char* text);

public:
	Menu();
	~Menu();

	void	main();
	void	load();

};