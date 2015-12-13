#ifndef _HELPER_H_
#define _HELPER_H_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef void(*FUNC_PTR)(void);

void	clear();
int		getInt(string message = "Requesting integer: ");
string	getString(string message = "Requesting string: ");
bool	isNumber(string str);
string	line(char c, int length, bool newLine = true);
void	pause();
void	showProgress(float progress, int maxWidth = 50, int hSpacing = 0);
string	space(int numTabs = 1);

#endif // !_HELPER_H_
