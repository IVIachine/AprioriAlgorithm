#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>

using namespace std;

template <typename T>
class LinkedList
{
	template <typename R>
	struct Node
	{
		R       mData;
		Node<T> *mNext;

		/*      Pre:  None
		*     Post:  This object is initialized using default values
		*  Purpose:  To initialize date object
		*************************************************************************/
		Node()
		{
			mData = R();
			mNext = NULL;
		}


		/*      Pre:  None
		*     Post:  This object is initialized using specified data
		*  Purpose:  To intialize date object
		*************************************************************************/
		Node(R data)
		{
			mData = data;
			mNext = NULL;
		}
	};


private:
	Node<T> *mHead, *mTail;
	int     mCount;

public:
	LinkedList();
	~LinkedList();

	int  size();
	T    getData(int index);
	void setData(int index, T data);

	void clear();
	void display();
	void insertSorted(T data);
	void insertUnsorted(T data);

	bool isEmpty();
	bool isExistSorted(T searchKey);
	bool isExistUnsorted(T searchKey);
	bool removeSorted(T searchKey);
	bool removeUnsorted(T data);
	T    removeAt(int index);

	T operator[](int index);
};

#pragma region Constructor/Destructor

/*      Pre:  None
*     Post:  This object is initialized using the default
*  Purpose:  To initialize date object
*****************************************************************************/
template <typename T>
LinkedList<T>::LinkedList()
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
template <typename T>
LinkedList<T>::~LinkedList()
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
template <typename T>
int LinkedList<T>::size()
{
	return mCount;
}


/*      Pre:  The list is instantiated and the index is valid
*     Post:  The data in the specified index is returned to the caller
*  Purpose:  To retrieve the specified nodes in the list
Cite: Function By Wei
*****************************************************************************/
template <typename T>
T LinkedList<T>::getData(int index)
{
	int     i;
	Node<T> *tmp;

	if (index < 0 || index >= mCount)
		return T();

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
template <typename T>
void LinkedList<T>::setData(int index, T data)
{
	int     i;
	Node<T> *tmp;

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
template <typename T>
void LinkedList<T>::clear()
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
template <typename T>
void LinkedList<T>::display()
{
	Node<T> *tmp;

	if (mHead == NULL)
	{
		cout << "The list is empty\n";
		return;
	}

	tmp = mHead;
	cout << "\n";
	while (tmp != NULL)
	{
		cout << tmp->mData << " ";
		tmp = tmp->mNext;
	}
	cout << "\n\n";
}

/*      Pre:  The list is instantiated
*     Post:  The function returns true is the list is empty; false otherwise
*  Purpose:  To determine if the list is empty
Cite: Function by Wei
*****************************************************************************/
template <typename T>
bool LinkedList<T>::isEmpty()
{
	return mHead == NULL;
}


/*      Pre:  The list is instantiated and the searchKey is available
*     Post:  The function returns true if the search key exists in the list;
*            otherwise false
*  Purpose:  To determine if a specific value exists in the list or not
Cite: Function mostly by Wei with tweeks from Tyler Chermely
*****************************************************************************/
template <typename T>
bool LinkedList<T>::isExistSorted(T searchKey)
{
	Node<T> *tmp;
	if (mHead == NULL)
		return false;
	else if (searchKey < mHead->mData || searchKey > mTail->mData) //If the object is greater than the head and smaller than the tail it isn't in the list
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


/*      Pre:  The list is instantiated and the searchKey is available
*     Post:  The function returns true if the search key exists in the list;
*            otherwise false
*  Purpose:  To determine if a specific value exists in the list or not
Cite: Function mostly by Wei with tweeks from Tyler Chermely
*****************************************************************************/
template <typename T>
bool LinkedList<T>::isExistUnsorted(T searchKey)
{
	Node<T> *tmp;
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
*  Purpose:  To insert a data into the list in ascending order.
Cite: Function mostly by Wei with tweeks from Tyler Chermely
*****************************************************************************/
template <typename T>
void LinkedList<T>::insertSorted(T data)
{
	Node<T> *tmp, *oneBefore, *newNode;

	newNode = new Node<T>(data);
	if (newNode == NULL)
		return;

	if (mHead == NULL)
	{
		mHead = newNode;
		mTail = newNode;
	}
	else
	{
		if (data < mHead->mData)
		{
			newNode->mNext = mHead;
			mHead = newNode;
		}
		else if (data > mTail->mData)
		{
			mTail->mNext = newNode;
			mTail = newNode;
		}
		else if (data == mHead->mData || data == mTail->mData)
		{
			delete newNode;
			return;
		}
		else
		{
			tmp = mHead;
			oneBefore = mHead;
			while (tmp->mData < data)
			{
				oneBefore = tmp;
				tmp = tmp->mNext;
			}

			if (tmp->mData != data)
			{
				newNode->mNext = tmp;
				oneBefore->mNext = newNode;
			}
			else
			{
				delete newNode;
				return;
			}
		}
	}

	mCount++;
}


/*      Pre:  The list is instantiated and the data is available
*     Post:  The data is inserted in ascending order
*  Purpose:  To insert data into the list at the head
*****************************************************************************/
template <typename T>
void LinkedList<T>::insertUnsorted(T data)
{
	Node<T> *newNode;
	newNode = new Node<T>(data);
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

#pragma region Remove Functions

/*      Pre:  The list is instantiated and the searchKey is available
*     Post:  If the searchKey exists, removes it from the list and the
*            function returns true; otherwise the function does nothing
*            and returns false
*  Purpose:  To remove a specific value from the sorted list
Cite: Function mostly by Wei with tweeks from Tyler Chermely
*****************************************************************************/
template <typename T>
bool LinkedList<T>::removeSorted(T searchKey)
{
	Node<T> *tmp, *prev;

	if (mHead == NULL)
		return false;
	else if (searchKey < mHead->mData || searchKey > mTail->mData) //If the object is greater than the head and smaller than the tail it isn't in the list
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

/*      Pre:  The list is instantiated and the searchKey is available
*     Post:  If the searchKey exists, removes it from the list and the
*            function returns true; otherwise the function does nothing
*            and returns false
*  Purpose:  To remove a specific value from the unsorted list
Cite: Function mostly by Wei with tweeks from Tyler Chermely
*****************************************************************************/
template <typename T>
bool LinkedList<T>::removeUnsorted(T searchKey)
{
	Node<T> *tmp, *prev;

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
template <typename T>
T LinkedList<T>::removeAt(int index)
{
	T data = T();
	Node<T> *tmp = mHead;
	Node<T> *previous = NULL;

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
template <typename T>
T LinkedList<T>::operator[](int index)
{
	return getData(index);
}
#pragma endregion

#endif