#include "Functions.h"

void menu_Func() {
	char s;
	while (true) {
		while (true) {
			system("cls");
			cout << "Выберите действие" << endl << "1 - Вычисление определенного интеграла" << endl << "2 - Построение графика функции"
				<< endl << "3 - Поиск корня при Y = 0 на отрезке" << endl << "4 - Поиск экстремумов на отрезке" 
				<< endl << "0 - Выход в главное меню" << endl << '>';
			s = _getche();
			if (s == '0' || s == '1' || s == '2' || s == '3' || s == '4') break;
			system("cls");
		}
		cout << endl;

		switch (s) {
		case '1': break;
		case '2': break;
		case '3': break;
		case '4': break;
		case '0': return;
		default: break;
		}
		cout << endl << "Продолжить?";
		s = tolower(_getche());
		if (s == 'n' || s == 'т') break;
		system("cls");
	}
	
}