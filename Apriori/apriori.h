#ifndef _APRIORI_H_
#define _APRIORI_H_

#include <string>
#include <iostream>
#include <algorithm>
#include "LinkedList.h"

#include <vector>

using namespace std;

static LinkedList<LinkedList<int>> genAll(LinkedList<int> *data, int k)
{
	int n = data->getCount();
	int *combination = new int[k]();
	LinkedList<int> tmp = LinkedList<int>();
	LinkedList <LinkedList<int>> theData = LinkedList<LinkedList<int>>();


	if (k > n)
		return theData;


	int r = 0;
	int index = 0;

	while (r >= 0)
	{
		if (index <= (n + (r - k)))
		{
			combination[r] = index + 1;
			if (r == k - 1)
			{

				//do something with the combination e.g. add to list or print
				tmp.clear();
				for (int i = 0; i < k; i++)
				{
					tmp.insertUnsorted(combination[i]);
				}
				tmp.display();
				theData.insertUnsorted(tmp);
				index++;
			}
			else
			{
				// select index for next position
				index = combination[r];
				r++;
			}
		}
		else
		{
			r--;
			if (r > 0)
				index = combination[r];
			else
			{
				index = combination[0];
			}
		}
	}
	return theData;
}


#endif