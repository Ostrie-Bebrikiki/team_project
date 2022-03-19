#include "header_ver.h"

void input_d(double& a, string str) {
	while (true) {
		std::cout << str<<": ";
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
		case '2':disp();
		case '3':MathAwait();
		}
		cout << endl << "Продолжить?";
		s = tolower(_getche());
		if (s == 'n' || s == 'т') break;
		system("cls");
	}
}

void ver() {
	double m, n;
	input_d(m, "Введите m");
	while (true) {
		input_d(n, "Введите n");
		if (n > 0) break;
		else cout << "n должна быть больше 0";
	}
}

void disp() {

}

void MathAwait() {

}