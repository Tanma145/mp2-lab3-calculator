#include "TCalculator.h"
#include <iostream>
#include <conio.h>
using namespace std;
int main() {
	try {
		TCalculator calc;
		string s;

		getline(cin, s);

//		cin >> s;
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