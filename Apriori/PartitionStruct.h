#ifndef PARTITIONSTRUCT
#define PARTITIONSTRUCT



#include <iostream>

using namespace std;

struct PartitionStruct
{
	int 
		frequency,
		size;

	int* data;
	
	PartitionStruct()
	{
		frequency = 0;
		size = 0;
		data = NULL;
	}
	
	~PartitionStruct()
	{
		if (size != 0)
		{
			data = NULL;
			delete[] data;
		}


      size = 0;
      frequency = 0;

	}
};

inline bool operator ==(PartitionStruct lhs, PartitionStruct rhs)
{
	return lhs.data == rhs.data;
}

inline ostream& operator<<(ostream& out, PartitionStruct p)
{
	for (int i = 0; i < p.size; i++)
	{
		out << p.data[i] << " ";
	}
	out << endl;
	return out;
}
#endif // !PARTITIONSTRUCT