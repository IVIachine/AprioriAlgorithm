#ifndef OBJECTLIST
#define OBJECTLIST
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

			mData.arraySize = data.arraySize;
			mData.theFrequency = data.theFrequency;

			mData.myArray = new int[mData.arraySize];

			for (i = 0; i < data.arraySize; i++)
				mData.myArray[i] = data.myArray[i];

			mNext = NULL;
		}

      ~Node()
      {
			 Node *tmp;

			 if (mData.arraySize != 0)
					delete[] mData.myArray;

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
	void display();
	void insertUnsorted(const PartitionStruct &data);

	bool isEmpty();
	bool isExistUnsorted(PartitionStruct searchKey);
	bool removeUnsorted(PartitionStruct data);
	PartitionStruct    removeAt(int index);

	PartitionStruct operator[](int index);


};
#endif // !OBJECTLIST

