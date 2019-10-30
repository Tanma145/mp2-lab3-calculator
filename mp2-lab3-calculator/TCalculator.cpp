#include "TCalculator.h"

int TCalculator::Prior(char c){
	switch (c) {
	case '(': return 0;
	case '+': return 1;
	case '-': return 1;
	case '*': return 2;
	case '/': return 2;
	case '^': return 3;
	default: throw c;
	}
}

void TCalculator::SetExpr(string s){
	expr = s;
}

string TCalculator::GetExpr(){
	return expr;
}

bool TCalculator::CheckBrackets(){
	st_c.Clear();
	for (int i = 0; i < expr.size(); i++) {
		if (expr[i] == '(') st_c.Push('(');
		if (expr[i] == ')')
			if (st_c.IsEmpty()) return false;
			else st_c.Pop();
	}
	return st_c.IsEmpty();
}

void TCalculator::ToPostfix(){
	string tmp = "(";
	tmp += expr += ")";
	postfix = "";
	st_c.Clear();
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == '(') st_c.Push('(');
		if (tmp[i] >= '0' && tmp[i] <= '9' || tmp[i] == '.') postfix[i] = tmp[i];
		if (tmp[i] == ')') {
			char t = st_c.Pop();
			while (t != '(') {
				postfix += t;
				t = st_c.Pop();
			}
		}
	}
}
