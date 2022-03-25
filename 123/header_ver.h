#pragma once
#ifndef header_ver
#define header_ver
#include <conio.h>
#include <iostream>
#include <string>
using namespace std;

void input_d1(double& a, std::string str) {
	while (true) {
		std::cout << str << ": ";
		std::string str1;
		std::getline(std::cin, str1);
		int err = 0;
		for (int i = 0; i < str1.length(); i++) {
			if (str1[i] == '.') str1[i] = ',';
			if (str1[i] == ',' || str1[i] == '-') {
				err++;
			}
		}
		if (str1[0] == '-') err--;
		if (err == 1 && str1[0] == '-') err--;
		if (str1.length() > 0) {
			if (std::isdigit(str1[0])) {
				for (int i = 0; i < str1.length(); i++) {
					if (!isdigit(str1[i]) && str1[i] != ',') err++;
				}
				if (!err) {
					a = std::stod(str1);
					break;
				}
			}
			else if (str1.length() > 1) if (str1[0] == '-' && std::isdigit(str1[1])) {
				for (int i = 1; i < str1.length(); i++) {
					if (!isdigit(str1[i]) && str1[i] != ',') err++;
				}
				if (!err) {
					a = std::stod(str1);
					break;
				}
			}
		}
		std::cout << "Ошибка ввода" << std::endl;
	}
}

void input1(int& a, std::string str) {
	while (true) {
		std::cout << str << ": ";
		std::string str1;
		std::getline(std::cin, str1);
		int err = 0;
		if (str1.length() > 0) {
			if (std::isdigit(str1[0])) {
				for (int i = 0; i < str1.length(); i++) {
					if (!isdigit(str1[i])) err++;
				}
				if (!err) {
					a = std::stoi(str1);
					break;
				}
			}
			else if (str1.length() > 1) if (str1[0] == '-' && std::isdigit(str1[1])) {
				for (int i = 1; i < str1.length(); i++) {
					if (!isdigit(str1[i])) err++;
				}
				if (!err) {
					a = std::stoi(str1);
					break;
				}
			}
		}
		std::cout << "Ошибка ввода" << std::endl;
	}
}

void ver();
void disp();
void MathAwait();
#endif