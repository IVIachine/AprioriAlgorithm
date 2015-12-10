#ifndef _HELPER_H_
#define _HELPER_H_

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

typedef void(*FUNC_PTR)(void);

void	clear();
void	errorMessage(string message);
void	errorMessage(string message, FUNC_PTR fallBack);
int		getInt();
bool	isNumber(string str);
void	pause();
void	print(char* text);
void	printl(char* text);

#endif // !_HELPER_H_
