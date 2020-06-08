#include "Kalkulator.h"

double calc(char forward, double a, double b) {//prosty switch do obsluzenia operacji
	double result = 0;
	switch (forward) {
	case '+':
		result = add(a, b); break;
	case '-':
		result = substract(a, b); break;
	case '*':
		result = multiply(a, b); break;
	case '/':
		result = divide(a, b); break;
	case 'C':
		result = clear(); break;
	}
	return result;
}

double add(double a, double b) {
	return a + b;
}
double substract(double a, double b) {
	return a - b;
}
double multiply(double a, double b) {
	return a * b;
}
double divide(double a, double b) {
	if (b != 0)
		return a / b;
	else
		return 0;//unikniecie dzielenia przez 0
}
double clear() {
	return 0;
}
