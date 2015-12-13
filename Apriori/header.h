#include <iostream>
#include <string>
#include <time.h>

#include "helper.h"
#include "apriori.h"
#include "LinkedList.h"
#include "ObjectList.h"
#include "timerSystem.h"

using namespace std;

void mainMenu(bool isStub,  bool showDebugInfo);

LinkedList<int>* loadData(string fName, int size, bool isStub, bool showDebugInfo);

string fileFormat(string fName);

int getTransNum(string fileName);

bool isDigit(char c);

void writeToFile(string fName, ObjectList theResult);


