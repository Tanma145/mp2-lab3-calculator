#include "TCalculator.h"
#include <iostream>
using namespace std;

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

string TCalculator::GetPostfix(){
	return postfix;
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
	(tmp += expr) += ")";
	postfix = "";
	st_c.Clear();
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == '(') st_c.Push('(');
		if (tmp[i] >= '0' && tmp[i] <= '9' || tmp[i] == '.') postfix += tmp[i];
		if (tmp[i] == ')') {
			char t = st_c.Pop();
			while (t != '(') {
				postfix += t;
				t = st_c.Pop();
			}
		}
		if (tmp[i] == '+' || tmp[i] == '-' || tmp[i] == '*' || tmp[i] == '/' || tmp[i] == '^') {
			cout << st_c.Top() << endl;
			if (tmp[i] == '-' && st_c.Top() == '(') postfix += '0';
			char t = st_c.Pop();
			postfix += ' ';
			while (Prior(tmp[i]) <= Prior(t)) {
				postfix += t;
				t = st_c.Pop();
			}
			st_c.Push(t);
			st_c.Push(tmp[i]);
		}

	}
}

double TCalculator::Calc() {
	st_d.Clear();
	for (int i = 0; i < postfix.size(); i++) {
		if (postfix[i] >= '0' && postfix[i] <= '9' || postfix[i] == '.') {
			char *tmp;
			double d = strtod(&postfix[i], &tmp);
			st_d.Push(d);
			i += tmp - &postfix[i] - 1; //мб здесь нужно -1
		}
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
			double rez, op1, op2 = st_d.Pop();
			op1 = st_d.Pop();
			switch (postfix[i]) {
			case '+': 
				rez = op1 + op2;
				st_d.Push(rez);
				break;
			case '-':
				rez = op1 - op2;
				st_d.Push(rez);
				break;
			case '*':
				rez = op1 * op2;
				st_d.Push(rez);
				break;
			case '/':
				rez = op1 / op2;
				st_d.Push(rez);
				break;/*
			case '^':
				double rez = op1 + op2;
				st_d.Push(rez);
				break;*/
			default: throw postfix[i];
			}
		}
	}
	return st_d.Pop();
}