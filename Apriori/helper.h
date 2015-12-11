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
string	line(char c, int length, bool newLine = true);
bool	isNumber(string str);
void	pause();
string	space(int numTabs = 1);
string	space(int numTabs, char c);
void	showProgress(float progress, int maxWidth);

#endif // !_HELPER_H_
