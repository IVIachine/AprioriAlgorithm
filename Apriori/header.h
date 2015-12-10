#include <iostream>
#include <string>
#include <time.h>

#include "helper.h"
#include "apriori.h"
#include "LinkedList.h"
#include "ObjectList.h"

using namespace std;

void mainMenu();
LinkedList<int>* loadData(string fName, bool showDebugInfo = false);

int getTransNum(string fileName);
bool isDigit(char c);

