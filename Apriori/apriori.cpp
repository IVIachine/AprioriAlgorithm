#include "apriori.h"


ObjectList genAll(LinkedList<int> data, int k)
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
				
				myStruct.frequency = 0;		
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