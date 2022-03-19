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
			system("cls");
			cout << "КАЛЬКУЛЯТОР ТЕОРИИ ВЕРОЯТНОСТИ И МАТ. СТАТИСТИКИ" << endl<<endl;
			cout << "Выберите действие" << endl << "1 - Вычислить вероятность m/n" << endl << "2 - Вычислить дисперсию для дискретного распределения величин"
				<< endl << "3 - Вычислить мат. ожидание для дискретного распределения величин" << endl <<"4 - Выход в главное меню" << endl << '>';
			s = _getche();
			if (s == '1' || s == '2' || s == '3' || s == '4') break;
			system("cls");
		}
		cout << endl;

		switch (s) {
		case '1':ver(); break;
		case '2':disp(); break;
		case '3':MathAwait(); break;
		case '4': return;
		default: break;
		}
		cout << endl << "Продолжить?";
		s = tolower(_getche());
		if (s == 'n' || s == 'т') break;
		system("cls");
	}
}

void ver() {
	double m, n;
	while (true) {
		input_d(m, "Введите m");
		while (true) {
			input_d(n, "Введите n");
			if (n > 0) break;
			else cout << "n должна быть больше 0\n";
		}
		if (m > n) cout << "m должна быть меньше n\n";
		else break;
	}
	cout << "Ответ: " << m / n;
}

void disp() {

}

void MathAwait() {

}