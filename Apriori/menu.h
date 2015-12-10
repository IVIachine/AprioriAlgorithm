#include "helper.h"

using namespace std;

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