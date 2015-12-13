#include "header.h"

int main()
{
	bool
		isStub = false,
		showDebugInfo = true;	

	//T5.N0.1K.D1K
	//T5.N0.1K.D10K
	//T5.N0.1K.D100K
	
	while (true)
	{
		clear();

		mainMenu(isStub, showDebugInfo);
	}

	return 0;
}