#pragma once
#include <string>
#include "TStack.h"
class TCalculator{
	std::string expr, postfix;
	TStack<char> st_c;
	TStack<double> st_d;
	int Prior(char c);
public:
	TCalculator():st_c(50), st_d(50) {}
	~TCalculator() {}
	void SetExpr(std::string);
	std::string GetExpr();
	std::string GetPostfix();
	bool CheckBrackets();
	void ToPostfix();
	double Calc();
};

