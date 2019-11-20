#include "TCalculator.h"
#include <conio.h>
#include <iostream>
using namespace std;
int main() {
	try {
		TCalculator calc;
		string s;

		getline(cin, s);
		calc.SetExpr(s);
		cout << calc.GetExpr() << endl;
		if (!calc.CheckBrackets()) throw 0;
		calc.ToPostfix();
		cout << calc.GetPostfix() << endl;
		cout << calc.Calc();
		_getch();
		return 0;
	}
	catch(int a){
		cout << a << " oof";
		_getch();
		return 0;
	}
}