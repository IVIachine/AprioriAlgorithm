#include "header.h"

ObjectList testAprioriGen(int N, int K, int minNum, int maxNum)
{
	cout
		<< "\n"
		<< "Testing 'aprioriGen'"
		<< "\n"
		<< "|N: " << N << "| K: " << K << "| Items between " << minNum << " and " << maxNum - 1 << "|"
		<< "\n";

	srand(time(NULL));

	LinkedList<int> data = LinkedList<int>();

	for (int i = 0; i < N; i++)
	{
		data.insertSorted((rand() % (maxNum - minNum)) + minNum);
	}

	ObjectList list = aprioriGen(data, K);

	list.display(0);

	return list;
}

LinkedList<int> testReverseFunction(ObjectList input)
{
	cout 
		<< "\n"
		<< "Testing 'reverseFunction'"
		<< "\n";

	LinkedList<int> list = reverseFunction(input);

	list.display();

	return list;
}

int _main()
{
	bool
		isStub = true,
		showDebugInfo = true;

	mainMenu(isStub, showDebugInfo);

	return 0;
}