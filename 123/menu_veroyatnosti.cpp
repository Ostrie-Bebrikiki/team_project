#include <conio.h>
#include <iostream>
#include "header_ver.h"
using namespace std;

void menu_ver() {
	char s;
	while (true) {
		while (true) {
			cout << "Выберите задачу" << endl << "1 - Вероятность m/n" << endl << "2 - Дисперсия для дискретного распределения величин"
				<< endl << "3 - Мат. ожидание для дискретного распределения величин" << endl << '>';
			s = _getche();
			if (s == '1' || s == '2' || s == '3') break;
			system("cls");
		}
		cout << endl;

		switch (s) {
		case '1':ver();
		case '2':;
		case '3':;
		}
		cout << endl << "Продолжить?";
		s = tolower(_getche());
		if (s == 'n' || s == 'т') break;
		system("cls");
	}
}