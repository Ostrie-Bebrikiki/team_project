#include "PolynomialCalc.h"
#include "bebra.h"

void PolynomialMenu()
{
	char choose;
	bool flag = false;
	do {
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
			printf_s("�������: "); choose = _getche();
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
				printf_s("�� ����� ������ �����?\ny -��\nn - ���\n�������: "); choose = _getche();
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
		printf_s("\t�������� �����������\n");
		printf_s("������� ������� ������� ����������: "); scanf_s("%d", &slag1.n);
		printf_s("������� ������� ������� ����������: "); scanf_s("%d", &slag2.n);
		if (slag1.n <= 0 || slag2.n <= 0) system("cls");
	} while (slag1.n <= 0 || slag2.n <= 0);
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
}
