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

inline ostream& operator<<(ostream& out, PartitionStruct p)
{
	for (int i = 0; i < p.size; i++)
	{
		out << p.data[i] << " ";
	}
	out << endl;
	return out;
}

inline bool operator==(const PartitionStruct& lhs, const PartitionStruct& rhs)
{
	if (lhs.size == rhs.size)
	{
		for (int i = 0; i < lhs.size; i++)
		{
			if (lhs.data[i] != rhs.data[i])
				return false;
		}

		return true;
	}

	return false;
}

#endif // !PARTITIONSTRUCT