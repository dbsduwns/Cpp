#include<iostream>
using namespace std;

#include "Calculator.h"

int main() {
	Add a; Sub s; Mul m; Div d;
	int x, y;
	char Cal;

	while (true) {
		cout << "계산기 프로그램" << endl;
		cout << "두 정수와 연산자를 입력해주세요 : ";
		cin >> x >> y >> Cal;

		switch (Cal) {
		case '+':
			a.set(x, y);
			cout << "계산결과 : " << a.calculate() << endl;
			break;
		case '-':
			s.set(x, y);
			cout << "계산결과 : " << s.calculate() << endl;
			break;
		case '*':
			m.set(x, y);
			cout << "계산결과 : " << m.calculate() << endl;
			break;
		case '/':
			d.set(x, y);
			cout << "계산결과 : " << d.calculate() << endl;
			break;
		}
	}
}
