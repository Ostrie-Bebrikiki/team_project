#include "PolynomialCalc.h"
#include "bebra.h"

void PolynomialMenu()
{
	char choose;
	bool flag = false;
	do {
		printf_s("\t����������� �����������\n");
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
			if (choose < '0' || choose > '6') {
				system("cls");
			}
		} while (flag == false);

		system("cls");

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
	printf_s("\t�������� �����������\n");
	printf_s("������� ������ ���������: ");
	printf_s("������� ������ ���������: ");
	system("cls");
}

void PolynomialSubstraction()
{
	printf_s("\t��������� �����������\n");
	printf_s("������� ������ ���������: ");
	printf_s("������� ������ ���������: ");
	system("cls");
}

void PolynomialMulti()
{
	printf_s("\t��������� �����������\n");
	printf_s("������� ������ ���������: ");
	printf_s("������� ������ ���������: ");
	system("cls");
}

void PolynomialMultiNumber()
{
	printf_s("\t��������� ���������� �� �����\n");
	printf_s("������� ���������: ");
	printf_s("������� �����: ");
	system("cls");
}

void PolynomialDerivative()
{
	printf_s("\t����������� �� ����������\n");
	printf_s("������� ���������: ");
	system("cls");
}

void PolynomialDivision()
{
	printf_s("\t������� �����������\n");
	printf_s("������� ������ ���������: ");
	printf_s("������� ������ ���������: ");
	system("cls");
	return;
}
