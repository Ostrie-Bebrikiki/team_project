#include "PolynomialCalc.h"
#include "bebra.h"

void PolynomialMenu()
{
	char choose;
	printf_s("\tКАЛЬКУЛЯТОР МНОГОЧЛЕНОВ\n");
	do {
		printf_s("Выберите действие:\n");
		printf_s("1: Сложение\n");
		printf_s("2: Вычитание\n");
		printf_s("3: Умножение\n");
		printf_s("4: Умножение на число\n");
		printf_s("5: Производная\"\n");
		printf_s("6: Деление\n");
		printf_s("0: Выйти\n");
		do {
			printf_s("Выбрано: "); choose = _getche();
		} while (choose < '0' || choose > '6');

		switch (choose) {
		case '1': PolynomialSum(); break;
		case '2': PolynomialSubstraction(); break;
		case '3': PolynomialMulti(); break;
		case '4': PolynomialMultiNumber(); break;
		case '5': PolynomialDerivative(); break;
		case '6': PolynomialDivision(); break;
		case '0': return;
		default: break;
		}
	} while (choose != '0');
}

void PolynomialSum()
{
	printf_s("Введите первый многочлен: ");
	printf_s("Введите второй многочлен: ");
}

void PolynomialSubstraction()
{
	printf_s("Введите первый многочлен: ");
	printf_s("Введите второй многочлен: ");
}

void PolynomialMulti()
{
	printf_s("Введите первый многочлен: ");
	printf_s("Введите второй многочлен: ");
}

void PolynomialMultiNumber()
{
	printf_s("Введите многочлен: ");
	printf_s("Введите число: ");
}

void PolynomialDerivative()
{
	printf_s("Введите многочлен: ");
}

void PolynomialDivision()
{
	printf_s("Введите первый многочлен: ");
	printf_s("Введите второй многочлен: ");
}
