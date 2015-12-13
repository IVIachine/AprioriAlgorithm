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

//operators
inline ostream& operator<<(ostream& out, PartitionStruct p)
{
	cout << "{";
	for (int i = 0; i < p.size; i++)
	{
		out << p.data[i] << (i < p.size - 1 ? ", " : "}\n");
	}

	return out;
}

//compares an array to an array
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