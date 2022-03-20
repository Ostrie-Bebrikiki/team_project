#include "PolynomialCalc.h"
#include "bebra.h"

//������� ������������ �����������
//������������� - ����������

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
		printf_s("������� ������� ������� ����������: "); scanf_s("%d", &slag1.n); // ������ �������� �����������
		printf_s("������� ������� ������� ����������: "); scanf_s("%d", &slag2.n);
		if (slag1.n <= 0 || slag2.n <= 0) system("cls");
	} while (slag1.n <= 0 || slag2.n <= 0);

	printf_s("������� ��������� ������� ����������: \n"); //���� �������� �����������
	for (int i = slag1.n; i >= 0; i--) {
		printf_s("c%d = ", i); scanf_s("%lf", &slag1.c[i]);
	}
	printf_s("������� ��������� ������� ����������: \n");
	for (int i = slag2.n; i >= 0; i--) {
		printf_s("c%d = ", i); scanf_s("%lf", &slag2.c[i]);
	}

	printf_s("������ ���������: "); // ����� ������� ����������
	printf_s("%.3lfx^%d", slag1.c[slag1.n], slag1.n);
	for (int i = slag1.n - 1; i >= 2; i--) {
		if (slag1.c[i] >= 0) printf_s("+%.3lfx^%d", slag1.c[i], i);
		else printf_s("%.3lfx^%d", slag1.c[i], i);
	}
	if (slag2.c[1] >= 0) printf_s("+%.3lfx", slag2.c[1]); //��� x^1
	else printf_s("%.3lfx^%d", slag2.c[1]);
	if (slag1.c[0] >= 0) printf_s("+%lf\n", slag1.c[0]); //��� x^0
	else printf_s("%.3lf\n", slag1.c[0]);

	printf_s("������ ���������: "); // ����� ������� ����������
	printf_s("%.3lfx^%d", slag2.c[slag2.n], slag2.n);
	for (int i = slag2.n - 1; i >= 2; i--) {
		if (slag2.c[i] >= 0) printf_s("+%.3lfx^%d", slag2.c[i], i);
		else printf_s("%.3lfx^%d", slag2.c[i], i);
	}
	if (slag2.c[1] >= 0) printf_s("+%.3lfx", slag2.c[1]); //��� x^1
	else printf_s("%.3lfx", slag2.c[1]);
	if (slag2.c[0] >= 0) printf_s("+%.3lf\n", slag2.c[0]); //��� x^0
	else printf_s("%.3lf\n", slag2.c[0]);
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
