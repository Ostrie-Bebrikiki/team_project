#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "");
	char s, sd;
	int n = 0, m = 0;

	while (true) {
		while (true) {
			cout << "Выберите вариант заполнения массива" << endl << "1 - 1 способ(выделение памяти под весь массив сразу)" << endl << "2 - 2 способ(массив указателей)" << endl << '>';
			s = _getche();
			if (s == '1' || s == '2') break;
			system("cls");
		}
		cout << endl;
		while (true) {
			cout << "Выберите номер задания" << endl << "1 - Задание №1" << endl << "2 - Задание №2" << endl << '>';
			sd = _getche();
			if (sd == '1' || sd == '2') break;
			system("cls");
		}



		cout << endl << "Продолжить?";
		s = tolower(_getche());
		if (s == 'n' || s == 'т') break;
		system("cls");
	}
	return 0;
}