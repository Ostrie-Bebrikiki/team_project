#pragma once
#ifndef Functions
#define Functions
#include <conio.h>
#include <iostream>
#include <string>
#include "SDL.h"
#include <math.h>
#include <windows.h>
using namespace std;

void input_d(double& a, std::string str) {
	while (true) {
		std::cout << str << ": ";
		std::cin >> a;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Ошибка ввода" << std::endl;
		}
		else {
			break;
		}
	}
}
void input(int& a, std::string str) {
	while (true) {
		std::cout << str << ": ";
		std::cin >> a;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Ошибка ввода" << std::endl;
		}
		else {
			break;
		}
	}
}
double f(char ch, double x, double a, double b, double c, double d) {
	switch (ch) {
	case '2': return (x < 0 && double((int)b) != b ? -a : a) * pow((x < 0 && double((int)b) != b ? -x : x), b) + c;
	case '3': return a * pow(b, c * x) + d;
	case '4': return a * log(b * x) + c;
	case '5': return a * sin(b * x + c) + d;
	case '6': return a * cos(b * x + c) + d;
	default: return 0;
	}
}
double f1(char ch, double x, double a, double b, double c, double d) {
	switch (ch) {
	case '2': return b == -1 ? (a * log(x < 0 ? -x : x) + c * x) : (a * pow(x, b + 1) / (b + 1) + c * x);
	case '3': return c == 0 || b <=0? (b==0?(d):(d+(b < 0?-1:1)*a)):(d * x + (a * pow(b, c * x)) / (log(b) * c));
	case '4': return x==0?x:(x * (a * (log(b * x)-1) + c));
	case '5': return d * x - (a * cos(b * x + c) / b);
	case '6': return d * x + (a * sin(b * x + c) / b);
	default: return 0;
	}
}
void choose(char& s) {
	while (true) {
		std::cout << "Выберите функцию" << endl << "1 - Полином степени N: a0+a1**x+a2*x^2+...+aN*x^N" << endl
			<< "2 - Степенная: a*x^b+c" << endl << "3 - Показательная: a*b^(c*x)+d" << endl << "4 - Логарифмическая: a*ln(b*x)+c" << endl
			<< "5 - Синусоида: a*sin(b*x+c)+d" << endl << "6 - Косинусоида: a*cos(b*x+c)+d" << endl << "0 - Назад" << endl << '>';
		s = _getche();
		if (s == '0' || s == '1' || s == '2' || s == '3' || s == '4' || s == '5' || s == '6') break;
	}
}

void integral(char ch, double a, double b, double c, double d);
void graph(char ch, double a, double b, double c, double d);
void root_f(char ch, double a, double b, double c, double d);
void extremum(char ch, double a, double b, double c, double d);
#endif