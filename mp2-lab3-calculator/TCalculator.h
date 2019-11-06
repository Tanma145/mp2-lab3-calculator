#pragma once
#include <string>
#include "TStack.h"
using namespace std;
class TCalculator{
	string expr, postfix;
	TStack<char> st_c;
	TStack<double> st_d;
	int Prior(char c);
public:
	TCalculator():st_c(50), st_d(50) {}
	~TCalculator() {}
	void SetExpr(string);
	string GetExpr();
	string GetPostfix();
	bool CheckBrackets();
	void ToPostfix();
	double Calc();
};

