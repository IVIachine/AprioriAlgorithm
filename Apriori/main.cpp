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

#include "header.h"

int main()
{
	bool
		isStub = false,
		showDebugInfo = true;	
	
	while (true)
	{
		clear();

		mainMenu(isStub, showDebugInfo);
	}

	return 0;
}