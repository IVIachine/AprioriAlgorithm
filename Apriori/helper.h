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

#ifndef _HELPER_H_
#define _HELPER_H_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef void(*FUNC_PTR)(void);

//Function headers

void	clear();
int		getInt(string message = "Requesting integer: ");
string	getString(string message = "Requesting string: ");
bool	isNumber(string str);
string	line(char c, int length, bool newLine = true);
void	pause();
void	showProgress(float progress, int maxWidth = 50, int hSpacing = 0);
string	space(int numTabs = 1);

#endif // !_HELPER_H_
