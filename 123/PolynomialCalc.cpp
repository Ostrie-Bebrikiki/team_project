#include "PolynomialCalc.h"
#include "bebra.h"

void PolynomialMenu()
{
	char choose;
	printf_s("\t����������� �����������\n");
	do {
		printf_s("�������� ��������:\n");
		printf_s("1: ��������\n");
		printf_s("2: ���������\n");
		printf_s("3: ���������\n");
		printf_s("4: ��������� �� �����\n");
		printf_s("5: �����������\"\n");
		printf_s("6: �������\n");
		printf_s("0: �����\n");
		do {
			printf_s("�������: "); choose = _getche();
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
	printf_s("������� ������ ���������: ");
	printf_s("������� ������ ���������: ");
}

void PolynomialSubstraction()
{
	printf_s("������� ������ ���������: ");
	printf_s("������� ������ ���������: ");
}

void PolynomialMulti()
{
	printf_s("������� ������ ���������: ");
	printf_s("������� ������ ���������: ");
}

void PolynomialMultiNumber()
{
	printf_s("������� ���������: ");
	printf_s("������� �����: ");
}

void PolynomialDerivative()
{
	printf_s("������� ���������: ");
}

void PolynomialDivision()
{
	printf_s("������� ������ ���������: ");
	printf_s("������� ������ ���������: ");
}
