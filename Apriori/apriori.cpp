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
            myStruct.arraySize = k;
            myStruct.myArray = new int[k];
				for (int i = 0; i < k; i++)
				{
					myStruct.myArray[i] = data.getData(combination[i]);
				}
				myStruct.theFrequency = 0;		
				theData.insertUnsorted(myStruct);	
				myStruct.myArray = NULL;
				delete[] myStruct.myArray;
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