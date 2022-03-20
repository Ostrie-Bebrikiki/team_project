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
void DrawCircle(SDL_Renderer* renderer, int32_t centreX, int32_t centreY, int32_t radius)
{
	const int32_t diameter = (radius * 2);

	int32_t x = (radius - 1);
	int32_t y = 0;
	int32_t tx = 1;
	int32_t ty = 1;
	int32_t error = (tx - diameter);

	while (x >= y)
	{
		SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
		SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
		SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
		SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
		SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
		SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
		SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
		SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

		if (error <= 0)
		{
			++y;
			error += ty;
			ty += 2;
		}

		if (error > 0)
		{
			--x;
			tx += 2;
			error += (tx - diameter);
		}
	}
}
double f(char ch, double x, double a, double b, double c, double d) {
	switch (ch) {
	case '2': return a * pow(x, b) + c;
	case '3': return a * pow(b, c * x) + d;
	case '4': return a * log(b * x) + c;
	case '5': return a * sin(b * x + c) + d;
	case '6': return a * cos(b * x + c) + d;
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