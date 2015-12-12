#include "apriori.h"


ObjectList aprioriGen(LinkedList<int> data, int k)
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
	LinkedList<int> result = LinkedList<int>();

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < list[i].size(); j++)
		{
			result.insertSorted(list[i][j]);
		}
	}

	return result;
}

ObjectList aprioriAlgorithm(LinkedList<int>* data, int size, int min, bool showDebugInfo)
{
	ObjectList C, lastC;
	LinkedList<int> f1 = getF1(data, size);
	LinkedList<int> F = f1;

	int k = 0;

	while(!F.isEmpty())
	{
		k++;

		// All possible combinations within the entire set
		C = aprioriGen(F, k);

		if (C.isEmpty())
		{
			return lastC;
		}

		cout
			<< space(1) << "K: " << k
			<< "\n"
			<< line(' ', 7, false) << line('*', 20)
			<< "\n\n"
			<< space(2) << "Generating all combinations of size [" << k << "]"
			<< "\n\n";

		TimerSystem timer;
		double time;

		timer.startClock();

		for (int i = 0; i < size; i++)
		{
			float p = (float)(i + 1);
			showProgress(p / size, 35, 2);

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

		time = timer.getTime();

		cout
			<< space(2) << "Number of combinations generated: " << C.size()
			<< "\n\n"
			<< space(2) << "Operation took (" << time << ") seconds to complete."
			<< "\n\n"
			<< line(' ', 7, false) << line('*', 20)
			<< "\n";
		
		lastC = C;	
		
	}

	return lastC; 
}