#pragma once
#include <string>
#include "TStack.h"
using namespace std;
class TCalculator{
	string expr, postfix;
	TStack<char> st_c;
	int Prior(char c);
public:
	TCalculator():st_c(50) {}
	~TCalculator() {}
	void SetExpr(string);
	string GetExpr();
	bool CheckBrackets();
	void ToPostfix();
};

