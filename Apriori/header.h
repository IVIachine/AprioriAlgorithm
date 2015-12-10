#include <iostream>
#include <string>
#include <time.h>

#include "helper.h"
#include "apriori.h"
#include "LinkedList.h"
#include "ObjectList.h"
#include "timerSystem.h"

using namespace std;

void mainMenu();

LinkedList<int>* loadData(string fName, bool showMessages, bool showResults);

int getTransNum(string fileName);

bool isDigit(char c);

void writeToFile(ObjectList theResult);


