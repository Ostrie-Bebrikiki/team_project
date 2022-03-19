#include "PolynomialCalc.h"
#include "bebra.h"

void PolynomialMenu()
{
	char choose;
	do {
		printf_s("\tКАЛЬКУЛЯТОР МНОГОЧЛЕНОВ\nВыберите действие:\n");
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
		case '0': break;
		}
	} while (choose != '0');
}

double PolynomialSum()
{
	return 0.0;
}

double PolynomialSubstraction()
{
	return 0.0;
}

double PolynomialMulti()
{
	return 0.0;
}

double PolynomialMultiNumber()
{
	return 0.0;
}

double PolynomialDerivative()
{
	return 0.0;
}

double PolynomialDivision()
{
	return 0.0;
}
