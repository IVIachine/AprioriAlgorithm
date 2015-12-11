#include "apriori.h"


ObjectList aprioriGen(LinkedList<int> data, int k, bool showDebugInfo)
{
	int n = data.size();
	int *combination = new int[k]();
	int *tmp = new int[k];
	PartitionStruct myStruct = PartitionStruct();
	ObjectList result = ObjectList();

	if (k > n)
		return result;


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
				result.insertUnsorted(myStruct);	
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

	return result;
}

LinkedList<int> reverseFunction(ObjectList& list, bool showDebugInfo)
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

	if (showDebugInfo)
	{
		cout
			<< "\n"
			<< tab() << "Reverse: "
			<< "\n";

		//result.display();
	}

	return result;
}

LinkedList<int> getF1(LinkedList<int>* list, int size, bool showDebugInfo)
{
	LinkedList<int> result = LinkedList<int>();

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < list[i].size(); j++)
		{
			result.insertSorted(list[i][j]);
		}
	}

	if (showDebugInfo)
	{
		cout
			<< "\n"
			<< tab() << "F1: "
			<< "\n";

		//result.display();
	}

	return result;
}

ObjectList aprioriAlgorithm(LinkedList<int>* data, int size, int min, bool showDebugInfo)
{
	ObjectList C, lastC;
	LinkedList<int> f1 = getF1(data, size, showDebugInfo);
	LinkedList<int> F = f1;

	int k = 0;

	while(!F.isEmpty())
	{
		k++;

		// All possible combinations within the entire set
		C = aprioriGen(F, k, showDebugInfo);

		if (showDebugInfo)
		{
			cout
				<< "\n"
				<< tab() << "Combinations generated for C."
				<< "\n";

			C.display();
		}

		if (C.isEmpty())
		{
			return lastC;
		}

		if (showDebugInfo)
		cout 
			<< "Iteration [" << k << "] begin\n";


		for (int i = 0; i < size; i++)
		{
			// All possible combinations within a transaction
			ObjectList c = aprioriGen(data[i], k, showDebugInfo);

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
		F = reverseFunction(fk, showDebugInfo);
		
		if(showDebugInfo)
		cout 
			<< "\n" 
			<< tab() << "Size of C: " << C.size() 
			<< "\n\n"
			<< "Iteration [" << k << "] complete\n\n";
		
		lastC = C;	
		
	}

	return lastC; 
}