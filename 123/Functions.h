#pragma once
#ifndef Functions
#define Functions
#include <conio.h>
#include <iostream>
#include <string>
#include "SDL.h"
#include <math.h>
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

void integral(char ch, double x, double a, double b, double c, double d);
void graph(char ch, double x, double a, double b, double c, double d);
void root_f(char ch, double x, double a, double b, double c, double d);
void extremum(char ch, double x, double a, double b, double c, double d);
#endif