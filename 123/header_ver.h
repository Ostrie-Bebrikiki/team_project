#pragma once
#ifndef header_ver
#define header_ver
#include <conio.h>
#include <iostream>
#include <string>
using namespace std;


void input_d(double& a, string str) {
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
void input(int& a, string str) {
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

void ver();
void disp();
void MathAwait();
#endif