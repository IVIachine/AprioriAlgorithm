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
void	pause();
string	tab(int num = 0);
void	showProgress(float progress, int maxWidth);

#endif // !_HELPER_H_
