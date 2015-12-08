#include "header.h"
#include "LinkedList.h"

int main()
{
	const int N = 8;
	int K = 4;
	LinkedList<int> *data = new LinkedList<int>();

	for (int i = 0; i < N; i++)
		data->insertSorted(i + 1);

	LinkedList<LinkedList<int>> list = genAll(data, K);

	//list.display();


	system("pause");

	return 0;
} 