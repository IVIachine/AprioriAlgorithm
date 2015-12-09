#ifndef PARTITIONSTRUCT
#define PARTITIONSTRUCT



#include <iostream>

using namespace std;

struct PartitionStruct
{
	int theFrequency;
	int *myArray;
	int arraySize;
	
	PartitionStruct()
	{
		theFrequency = 0;
		arraySize = 0;
		myArray = NULL;
	}
	
	~PartitionStruct()
	{
		if (arraySize != 0)
			delete [] myArray;

      arraySize = 0;
      theFrequency = 0;
      myArray = NULL;
	}
};

inline bool operator ==(PartitionStruct lhs, PartitionStruct rhs)
{
	return lhs.myArray == rhs.myArray;
}

inline ostream& operator<<(ostream& out, PartitionStruct p)
{
	for (int i = 0; i < p.arraySize; i++)
	{
		out << p.myArray[i] << " ";
	}
	out << endl;
	return out;
}
#endif // !PARTITIONSTRUCT