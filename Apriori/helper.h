#ifndef _HELPER_H_
#define _HELPER_H_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef void(*FUNC_PTR)(void);

void	clear();
void	errorMessage(string message);
void	errorMessage(string message, FUNC_PTR fallBack);
int		getInt();
bool	isNumber(string str);
void	pause();
void	print(string text);
void	printl(string text);

#endif // !_HELPER_H_
