#ifndef _APRIORI_H_
#define _APRIORI_H_

#include <string>
#include <iostream>
#include <algorithm>
#include "header.h"

using namespace std;


ObjectList aprioriGen(LinkedList<int> data, int k, bool showDebugInfo = false);

LinkedList<int> reverseFunction(ObjectList& list, bool showDebugInfo = false);

LinkedList<int> getF1(LinkedList<int>* list, int size, bool showDebugInfo = false);

ObjectList aprioriAlgorithm(LinkedList<int>* data, int size, int min, bool showDebugInfo = false);

#endif