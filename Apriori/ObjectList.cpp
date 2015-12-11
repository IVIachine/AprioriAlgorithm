#include "ObjectList.h"

ObjectList::ObjectList()
{
	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}


/*      Pre:  None
*     Post:  All the nodes in the list is deleted
*  Purpose:  To remove all the nodes in the list
Cite: Function by Wei
*****************************************************************************/
ObjectList::~ObjectList()
{
	// remove all nodes
	//if (mHead != NULL)
	//{
	// reinitialize the pointers
	mHead = NULL;
	mTail = NULL;

	// reinitialize count
	mCount = 0;
	//}
	clear();

}

#pragma endregion

#pragma region Helper Functions

/*      Pre:  The object is instantiated
*     Post:  The number of nodes in the linked list is returned to the caller
*  Purpose:  To retrieve the number of nodes in the list
Cite: Function by Wei
*****************************************************************************/
int ObjectList::size()
{
	return mCount;
}


/*      Pre:  The list is instantiated and the index is valid
*     Post:  The data in the specified index is returned to the caller
*  Purpose:  To retrieve the specified nodes in the list
Cite: Function By Wei
*****************************************************************************/
PartitionStruct ObjectList::getData(int index)
{
	int     i;
	Node *tmp;

	if (index < 0 || index >= mCount)
		return PartitionStruct();

	tmp = mHead;
	for (i = 0; i < index; i++)
		tmp = tmp->mNext;

	return tmp->mData;
}


/*      Pre:  The list is instantiated, the index is valid and the data is
*            available
*     Post:  The data in the specified index is updated with the specified
*            data
*  Purpose:  To update the specified nodes in the list
Cite: Function by Wei
*****************************************************************************/
void ObjectList::setData(int index, PartitionStruct data)
{
	int     i;
	Node *tmp;

	if (index < 0 || index >= mCount)
		return;

	tmp = mHead;
	for (i = 0; i < index; i++)
		tmp = tmp->mNext;

	tmp->mData = data;
}


/*      Pre:  The list is initiated
*     Post:  All the nodes in the list is deleted
*  Purpose:  To remove all the nodes in the list
Cite: Function by Wei
*****************************************************************************/
void ObjectList::clear()
{
	while (mCount > 0)
	{
		removeAt(0);
	}
	mHead = NULL;
	mTail = NULL;
}


/*      Pre:  The list is instantiated
*     Post:  The entire list is displayed on the screen
*  Purpose:  To show the content of the list
Cite: function by Wei
*****************************************************************************/
void ObjectList::display(int offset)
{
	Node *tmp;

	if (mHead == NULL)
	{
		cout << "The list is empty\n";
		return;
	}

	tmp = mHead;
	while (tmp != NULL)
	{
		cout << space(offset) << tmp->mData;
		tmp = tmp->mNext;
	}
}

/*      Pre:  The list is instantiated
*     Post:  The function returns true is the list is empty; false otherwise
*  Purpose:  To determine if the list is empty
Cite: Function by Wei
*****************************************************************************/
bool ObjectList::isEmpty()
{
	return mHead == NULL;
}

/*      Pre:  The list is instantiated and the searchKey is available
*     Post:  The function returns true if the search key exists in the list;
*            otherwise false
*  Purpose:  To determine if a specific value exists in the list or not
Cite: Function mostly by Wei with tweeks from Tyler Chermely
*****************************************************************************/
bool ObjectList::isExistUnsorted(PartitionStruct searchKey)
{
	Node *tmp;
	if (mHead == NULL)
		return false;

	bool    found = false;

	tmp = mHead;
	while (tmp != NULL && !found)
	{
		if (tmp->mData == searchKey)
			found = true;

		tmp = tmp->mNext;
	}

	return found;
}

#pragma endregion

#pragma region Insert Functions
/*      Pre:  The list is instantiated and the data is available
*     Post:  The data is inserted in ascending order
*  Purpose:  To insert data into the list at the head
*****************************************************************************/
void ObjectList::insertUnsorted(const PartitionStruct &data)
{
	Node *newNode;
	newNode = new Node(data);
	if (newNode == NULL)
		return;
	if (mHead == NULL)
	{
		mHead = newNode;
		mTail = newNode;
		mCount++;
		return;
	}
	else
	{
		mTail->mNext = newNode;
		mTail = newNode;
		mCount++;
		return;
	}
}

#pragma endregion

/*      Pre:  The list is instantiated and the searchKey is available
*     Post:  If the searchKey exists, removes it from the list and the
*            function returns true; otherwise the function does nothing
*            and returns false
*  Purpose:  To remove a specific value from the unsorted list
Cite: Function mostly by Wei with tweeks from Tyler Chermely
*****************************************************************************/
bool ObjectList::removeUnsorted(PartitionStruct searchKey)
{
	Node *tmp, *prev;

	if (mHead == NULL)
		return false;

	tmp = mHead;
	prev = NULL;
	for (int i = 0; i < mCount; i++)
	{
		if (searchKey == tmp->mData)
			break;

		prev = tmp;
		tmp = tmp->mNext;
	}

	if (tmp != NULL)
	{
		if (tmp == mHead)
		{
			tmp = mHead;

			mHead = mHead->mNext;
			if (mHead == NULL)
				mTail = NULL;

			tmp->mNext = NULL;
		}
		else if (tmp == mTail)
		{
			prev->mNext = NULL;
			mTail = prev;
		}
		else
		{
			prev->mNext = tmp->mNext;
			tmp->mNext = NULL;
		}

		delete tmp;
		mCount--;

		return true;
	}

	return false;
}


/*      Pre:  The list is instantiated and the index is valid
*     Post:  Remove the element in the specified index location and returns
*            its content to the caller.  If the index location is invalid, the
*            function returns the default value
*  Purpose:  To remove an item in the specified index location
Cite: Function by Wei
*****************************************************************************/
PartitionStruct ObjectList::removeAt(int index)
{
	PartitionStruct data = PartitionStruct();
	Node *tmp = mHead;
	Node *previous = NULL;

	if (index >= 0 && index < mCount)
	{
		tmp = mHead;
		for (int i = 0; i < index; i++)
		{
			previous = tmp;
			tmp = tmp->mNext;
		}

		if (tmp == mHead)
		{
			tmp = mHead;
			mHead = mHead->mNext;

			if (mCount == 1)
				mTail = NULL;
		}
		else if (tmp == mTail)
		{
			previous->mNext = NULL;
			mTail = previous;
		}
		else
			previous->mNext = tmp->mNext;

		data = tmp->mData;
		tmp->mNext = NULL;
		delete tmp;
		mCount--;
	}

	return data;
}

#pragma endregion

#pragma region Operator Overloads

/*      Pre:  The list is instantiated and the index is valid
*     Post:  The data in the specified index is returned to the caller
*  Purpose:  To retrieve the specified nodes in the list using [] operator
Cite: Function by Wei
*****************************************************************************/
PartitionStruct& ObjectList::operator[](int index)
{
	int     i;
	Node *tmp;

	if (index < 0 || index >= mCount)
		return PartitionStruct();

	tmp = mHead;
	for (i = 0; i < index; i++)
		tmp = tmp->mNext;

	return tmp->mData;
}
#pragma endregion