#include "PolynomialCalc.h"
#include "bebra.h"

//Функции калькулятора многочленов
//Ответственный - Коростелев

void PolynomialMenu()
{
	char choose;
	bool flag = false;
	do {
		do {
			printf_s("\tКАЛЬКУЛЯТОР МНОГОЧЛЕНОВ\n");
			printf_s("Выберите действие:\n");
			printf_s("1: Сложение\n");
			printf_s("2: Вычитание\n");
			printf_s("3: Умножение\n");
			printf_s("4: Умножение на число\n");
			printf_s("5: Производная\"\n");
			printf_s("6: Деление\n");
			printf_s("0: Выйти\n");
			printf_s("Выбрано: "); choose = _getche();
			if (choose < '0' || choose > '6') {
				system("cls");
			}
			else flag = true;
		} while (flag == false);

		system("cls");

		switch (choose) {
		case '1': PolynomialSum(); break;
		case '2': PolynomialSubstraction(); break;
		case '3': PolynomialMulti(); break;
		case '4': PolynomialMultiNumber(); break;
		case '5': PolynomialDerivative(); break;
		case '6': PolynomialDivision(); break;
		case '0': {
			do {
				printf_s("Вы точно хотите выйти?\ny -Да\nn - Нет\nВыбрано: "); choose = _getche();
				if (choose == 'y') return;
				else if (choose == 'n') break;
				else system("cls");
			} while (choose != 'y' || choose != 'n');
		}; break;
		default: break;
		}
	} while (choose != '0');
	system("cls");
}

void PolynomialSum()
{
	Polynomial slag1, slag2;
	do {
		printf_s("\tСЛОЖЕНИЕ МНОГОЧЛЕНОВ\n");
		printf_s("Введите степень первого многочлена: "); scanf_s("%d", &slag1.n); // Запрос степеней многочленов
		printf_s("Введите степень второго многочлена: "); scanf_s("%d", &slag2.n);
		if (slag1.n <= 0 || slag2.n <= 0) system("cls");
	} while (slag1.n <= 0 || slag2.n <= 0);

	printf_s("Введите константы первого многочлена: \n"); //Ввод констант многочленов
	for (int i = slag1.n; i >= 0; i--) {
		printf_s("c%d = ", i); scanf_s("%lf", &slag1.c[i]);
	}
	printf_s("Введите константы второго многочлена: \n");
	for (int i = slag2.n; i >= 0; i--) {
		printf_s("c%d = ", i); scanf_s("%lf", &slag2.c[i]);
	}

	printf_s("Первый многочлен: "); // Вывод первого многочлена
	printf_s("%.3lfx^%d", slag1.c[slag1.n], slag1.n);
	for (int i = slag1.n - 1; i >= 2; i--) {
		if (slag1.c[i] >= 0) printf_s("+%.3lfx^%d", slag1.c[i], i);
		else printf_s("%.3lfx^%d", slag1.c[i], i);
	}
	if (slag2.c[1] >= 0) printf_s("+%.3lfx", slag2.c[1]); //Для x^1
	else printf_s("%.3lfx^%d", slag2.c[1]);
	if (slag1.c[0] >= 0) printf_s("+%lf\n", slag1.c[0]); //Для x^0
	else printf_s("%.3lf\n", slag1.c[0]);

	printf_s("Второй многочлен: "); // Вывод первого многочлена
	printf_s("%.3lfx^%d", slag2.c[slag2.n], slag2.n);
	for (int i = slag2.n - 1; i >= 2; i--) {
		if (slag2.c[i] >= 0) printf_s("+%.3lfx^%d", slag2.c[i], i);
		else printf_s("%.3lfx^%d", slag2.c[i], i);
	}
	if (slag2.c[1] >= 0) printf_s("+%.3lfx", slag2.c[1]); //Для x^1
	else printf_s("%.3lfx", slag2.c[1]);
	if (slag2.c[0] >= 0) printf_s("+%.3lf\n", slag2.c[0]); //Для x^0
	else printf_s("%.3lf\n", slag2.c[0]);
}

void PolynomialSubstraction()
{
	printf_s("\tВЫЧИТАНИЕ МНОГОЧЛЕНОВ\n");
	printf_s("Введите первый многочлен: ");
	printf_s("Введите второй многочлен: ");
	system("cls");
}

void PolynomialMulti()
{
	printf_s("\tУМНОЖЕНИЕ МНОГОЧЛЕНОВ\n");
	printf_s("Введите первый многочлен: ");
	printf_s("Введите второй многочлен: ");
	system("cls");
}

void PolynomialMultiNumber()
{
	printf_s("\tУМНОЖЕНИЕ МНОГОЧЛЕНА НА ЧИСЛО\n");
	printf_s("Введите многочлен: ");
	printf_s("Введите число: ");
	system("cls");
}

void PolynomialDerivative()
{
	printf_s("\tПРОИЗВОДНАЯ ОТ МНОГОЧЛЕНА\n");
	printf_s("Введите многочлен: ");
	system("cls");
}

void PolynomialDivision()
{
	printf_s("\tДЕЛЕНИЕ МНОГОЧЛЕНОВ\n");
	printf_s("Введите первый многочлен: ");
	printf_s("Введите второй многочлен: ");
	system("cls");
}
