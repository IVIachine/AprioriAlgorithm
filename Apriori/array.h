#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

using namespace std;

template <class T>
class Array
{
private:
	T * mData;
	int mCount;

public:
	Array();
	~Array();

	int size();
	T getData(int index);
	int indexOf(T searchKey);
	bool insert(T value);
	bool insertAt(T value, int index);
	bool empty();
	bool contains(T searchKey);
	bool isSorted();
	bool remove(T value);
	bool removeAt(int index);

	void add(T value);
	void clear();
	void display();
	void setData(int index, T value);

	T & operator[](const int index);
};

#pragma region Constructor/Destructor

template <class T>
Array<T>::Array()
{
	mCount = 0;
	mData = new T[mCount];
	for (int i = 0; i < mCount; i++)
		mData[i] = 0;
}

template <class T>
Array<T>::~Array()
{
	delete[] mData;
}

#pragma endregion

#pragma region Debug Functions

template <class T>
void Array<T>::display()
{
	if (empty())
	{
		cout
			<< "The list is empty."
			<< "\n\n";
		return;
	}

	cout << "{";
	for (int i = 0; i < mCount; i++)
	{
		cout << mData[i];
		cout << (i < mCount - 1 ? ", " : "}");
	}
	cout << "\n\n";
}

#pragma endregion

#pragma region Public Functions

template <class T>
void Array<T>::add(T value)
{
	mCount++;

	T * tmp = new T[mCount];

	for (int i = 0; i < mCount; i++)
	{
		tmp[i] = mData[i];
	}

	delete[] mData;
	mData = tmp;

	mData[mCount - 1] = value;
}


template <class T>
void Array<T>::clear()
{
	delete[] mData;
	mCount = 0;
}


template <class T>
bool Array<T>::empty()
{
	return mCount == 0;
}


template <class T>
T Array<T>::getData(int index)
{
	return mData[index];
}


template <class T>
int Array<T>::indexOf(T searchKey)
{
	for (int i = 0; i < mCount; i++)
	{
		if (mData[i] == searchKey)
			return i;
	}

	return -1;
}


template <class T>
bool Array<T>::insert(T value)
{
	if (contains(value)) return false;

	if (empty())
	{
		add(value);
		return true;
	}
	else
	{
		if (value < mData[0])
		{
			insertAt(value, 0);
			return true;
		}
		else if (value > mData[mCount - 1])
		{
			add(value);
			return true;
		}
		else
		{
			for (int i = 0; i < mCount; i++)
			{
				if (mData[i] > value)
				{
					insertAt(value, i);
					return true;
				}
			}
		}
	}

	return true;
}


template <class T>
bool Array<T>::insertAt(T value, int index)
{
	if (empty()) return false;

	mCount++;

	T * tmp = new T[mCount];

	for (int i = 0; i < mCount; i++)
	{
		if (i < index)
			tmp[i] = mData[i];
		else
			tmp[i + 1] = mData[i];
	}

	delete[] mData;
	mData = tmp;

	mData[index] = value;

	return true;
}


template <class T>
bool Array<T>::contains(T searchKey)
{
	for (int i = 0; i < mCount; i++)
	{
		if (mData[i] == searchKey)
			return true;
	}

	return false;
}


template <class T>
bool Array<T>::isSorted()
{
	// Only proceed if 'mData' has more than one element
	if (mCount > 1)
	{
		for (int i = 1; i < mCount; i++)
		{
			if (mData[i - 1] > mData[i])
			{
				// Return false if ([i -1] > [i])
				return false;
			}
		}
	}

	return true;
}


template <class T>
bool Array<T>::remove(T value)
{
	if (!contains(value)) return false;

	while (contains(value))
	{
		int i = indexOf(value);

		removeAt(i);
	}

	return true;
}


template <class T>
bool Array<T>::removeAt(int index)
{
	if (index >= 0 && index < mCount)
	{
		mCount--;

		T * tmp = new T[mCount];

		for (int i = 0; i < mCount; i++)
		{
			if (i < index)
				tmp[i] = mData[i];
			else
				tmp[i] = mData[i + 1];
		}

		delete[] mData;
		mData = tmp;

		return true;
	}

	return false;
}

template <class T>
void Array<T>::setData(int index, T value)
{
	mData[index] = value;
}

template <class T>
int Array<T>::size()
{
	return mCount;
}

#pragma endregion

#pragma region Operator Overloads

template <class T>
T& Array<T>::operator[](const int index)
{
	return mData[index];
}

#pragma endregion

#endif