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

#ifndef _APRIORI_H_
#define _APRIORI_H_

#include <string>
#include <iostream>
#include <algorithm>
#include "header.h"

using namespace std;

//function headers

ObjectList aprioriGen(LinkedList<int> data, int k);

LinkedList<int> reverseFunction(ObjectList& list);

LinkedList<int> getF1(LinkedList<int>* list, int size);

ObjectList aprioriAlgorithm(LinkedList<int>* data, int size, int min, bool showDebugInfo = false);

#endif