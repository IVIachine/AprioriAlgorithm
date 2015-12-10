#include "apriori.h"


ObjectList aprioriGen(LinkedList<int> data, int k)
{
	int n = data.size();
	int *combination = new int[k]();
	int *tmp = new int[k];
	PartitionStruct myStruct = PartitionStruct();
	ObjectList theData = ObjectList();

	if (k > n)
		return theData;


	int r = 0;
	int index = 0;

	while (r >= 0)
	{
		if (index <= (n + (r - k)))
		{
			combination[r] = index;
			if (r == k - 1)
			{
				myStruct.size = k;
				myStruct.data = new int[k];

				for (int i = 0; i < k; i++)
				{
					myStruct.data[i] = data.getData(combination[i]);
				}
				
				//myStruct.frequency = 0;
				theData.insertUnsorted(myStruct);	
				myStruct.data = NULL;
				delete[] myStruct.data;
				index++;
			}
			else
			{
				index = combination[r] + 1;
				r++;
			}
		}
		else
		{
			r--;
			if (r > 0)
				index = combination[r] + 1;
			else
			{
				index = combination[0] + 1;
			}
		}
	}
	return theData;
}

LinkedList<int> reverseFunction(ObjectList& list)
{
	LinkedList<int> result;

	for (int i = 0; i < list.size(); i++)
	{
		for (int j = 0; j < list[i].size; j++)
		{
			int tmp = list[i].data[j];
			result.insertSorted(tmp);
		}
	}

	return result;
}

LinkedList<int> getF1(LinkedList<int>* list, int size)
{
	LinkedList<int> tmp = LinkedList<int>();

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < list[i].size(); j++)
		{
			tmp.insertSorted(list[i][j]);
		}
	}

	return tmp;
}

ObjectList aprioriAlgorithm(LinkedList<int>* data, int size, int min)
{
	ObjectList C;
	LinkedList<int> f1 = getF1(data, size);
	LinkedList<int> F = f1;

	cout << "Begin... \n\n";

	int k = 0;
	while(!F.isEmpty())
	{
		k++;

		if (F.isEmpty())
			break;

		// All possible combinations within the entire set
		C = aprioriGen(F, k);

		cout << "Iteration [" << k << "] begin\n";


		for (int i = 0; i < size; i++)
		{
			// All possible combinations within a transaction
			ObjectList c = aprioriGen(data[i], k);

			// Iterate through all subsets in c
			for (int j = 0; j < c.size(); j++)
			{
				// Iterate through all subsets in C
				for (int p = 0; p < C.size(); p++)
				{
					if (C[p] == c[j])
					{
						C[p].frequency++;
					}
				}
			}
		}

		ObjectList fk = ObjectList();

		for (int i = 0; i < C.size(); i++)
		{
			if (C[i].frequency >= min)
			{
				fk.insertUnsorted(C[i]);
			}
		}
		
		F.clear();
		F = reverseFunction(fk);
		
		cout << "\n" << C.size() << "\n\n";

		cout << "Iteration [" << k << "] complete\n\n";

		if (fk.isEmpty())
		{
			return C;
		}
	}

	return C; 
}