#ifndef _APRIORI_H_
#define _APRIORI_H_

#include <string>
#include <iostream>
#include <algorithm>
#include "header.h"

using namespace std;


ObjectList aprioriGen(LinkedList<int> data, int k);

LinkedList<int> reverseFunction(ObjectList& list);

LinkedList<int> getF1(LinkedList<int>* list, int size);

ObjectList aprioriAlgorithm(LinkedList<int>* data, int size, int min, bool showDebugInfo = false);

#endif