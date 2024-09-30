#include<iostream>
using namespace std;

#include "Calculator.h"

void Add::set(int x, int y) {
	a = x;
	b = y;
}
int Add::calculate() {
	return a + b;
}

void Sub::set(int x, int y) {
	a = x;
	b = y;
}
int Sub::calculate() {
	return a - b;
}

void Mul::set(int x, int y) {
	a = x;
	b = y;
}
int Mul::calculate() {
	return a * b;
}

void Div::set(int x, int y) {
	a = x;
	b = y;
}
int Div::calculate() {
	return a - b;
}


