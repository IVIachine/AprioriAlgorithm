#ifndef _HEADER_H_
#define _HEADER_H_

#include "apriori.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <class T>
void display(LinkedList<LinkedList<T>> list)
{
	cout
		<< "double list"
		<< "\n\n";
	
	for (int i = 0; i < list.size(); i++)
	{
		list[i].display();
	}
}

void mainMenu();

#endif