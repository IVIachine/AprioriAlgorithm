#ifndef _HELPER_H_
#define _HELPER_H_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef void(*FUNC_PTR)(void);

void	clear();
int		getInt(string message);
string	getString(string message);
bool	isNumber(string str);
void	pause();

#endif // !_HELPER_H_
