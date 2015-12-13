/*Author: Tyler Chermely, Adam Gurman
Class : CSI - 281 - 03
Assignment : Final Project Implementation
Date Assigned : Thursday, November 19, 2015 11:00AM
Due Date : Due : Saturday, December 12, 2015 11:59PM
Description :
To implement the Apriori algorithm
Certification of Authenticity :
I certify that this is entirely my own work, except where I have given fullydocumented
references to the work of others.I understand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment :
-Reproduce this assignment and provide a copy to another member of
academic staff; and / or
- Communicate a copy of this assignment to a plagiarism checking service
(which may then retain a copy of this assignment on its database for
the purpose of future plagiarism checking)*/

#ifndef OBJECTLIST
#define OBJECTLIST

#include "helper.h"
#include "PartitionStruct.h"
using namespace std; 

class ObjectList
{
	struct Node
	{
		PartitionStruct       mData;
		Node *mNext;

		/*      Pre:  None
		*     Post:  This object is initialized using default values
		*  Purpose:  To initialize date object
		*************************************************************************/
		Node()
		{
			mData = PartitionStruct();
			mNext = NULL;
		}


		/*      Pre:  None
		*     Post:  This object is initialized using specified data
		*  Purpose:  To intialize date object
		*************************************************************************/
		Node(const PartitionStruct &data)
		{
			 int i;

			mData.size = data.size;
			mData.frequency = data.frequency;

			mData.data = new int[mData.size];

			for (i = 0; i < data.size; i++)
				mData.data[i] = data.data[i];

			mNext = NULL;
		}

      ~Node()
      {
			 Node *tmp;

			 if (mData.size != 0)
					delete[] mData.data;

			 tmp = mNext;
			 while (tmp != NULL)
			 {
					mNext = mNext->mNext;
					mNext->mNext = NULL;
					delete mNext;

					tmp = mNext;
			 }

			 mNext = NULL;
		  }
	};

private:
	Node *mHead, *mTail;
	int     mCount;

public:
	ObjectList();
	~ObjectList();

	int  size();
	PartitionStruct    getData(int index);
	void setData(int index, PartitionStruct data);

	void clear();
	void display(int offset);
	void insertUnsorted(const PartitionStruct &data);

	bool isEmpty();
	bool isExistUnsorted(PartitionStruct searchKey);
	bool removeUnsorted(PartitionStruct data);
	PartitionStruct    removeAt(int index);

	PartitionStruct& operator[](int index);
};
#endif

