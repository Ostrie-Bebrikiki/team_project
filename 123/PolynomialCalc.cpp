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
				printf_s("�� ����� ������ �����?\ny - ��\nn - ���\n�������: "); choose = _getche();
				if (choose == 'y') return;
				else if (choose == 'n') {
					system("cls");
					break;
				}
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
	} while (slag1.n <= 0 || slag2.n <= 0 || slag1.n >= 100 || slag2.n >= 100);

	printf_s("������� ��������� ������� ����������: \n"); //���� �������� �����������
	PolynomInput(slag1);
	printf_s("������� ��������� ������� ����������: \n");
	PolynomInput(slag2);

	printf_s("������ ���������: "); // ����� ������� ����������
	PolynomOutput(slag1);

	printf_s("������ ���������: "); // ����� ������� ����������
	PolynomOutput(slag2);

	int max;

	if (slag1.n > slag2.n) max = slag1.n;
	else max = slag2.n;

	Polynomial sumPolynom;

	for (int i = max; i >= 0; i--) {
		sumPolynom.c[i] = slag1.c[i] + slag2.c[i];
	}

	printf_s("����� �����������: ");
	PolynomOutput(sumPolynom);
}

void PolynomialSubstraction(){
	Polynomial sub1, sub2;
	do {
		printf_s("\t��������� �����������\n");
		printf_s("������� ������� ������� ����������: "); scanf_s("%d", &sub1.n); // ������ �������� �����������
		printf_s("������� ������� ������� ����������: "); scanf_s("%d", &sub2.n);
		if (sub1.n <= 0 || sub2.n <= 0) system("cls");
	} while (sub1.n <= 0 || sub2.n <= 0 || sub1.n >= 100 || sub2.n >= 100);

	printf_s("������� ��������� ������� ����������: \n"); //���� �������� �����������
	PolynomInput(sub1);
	printf_s("������� ��������� ������� ����������: \n");
	PolynomInput(sub2);

	printf_s("������ ���������: "); // ����� ������� ����������
	PolynomOutput(sub1);

	printf_s("������ ���������: "); // ����� ������� ����������
	PolynomOutput(sub2);

	int max;

	if (sub1.n > sub2.n) max = sub1.n;
	else max = sub2.n;

	Polynomial subPolynom;

	for (int i = max; i >= 0; i--) {
		subPolynom.c[i] = sub1.c[i] - sub2.c[i];
	}

	printf_s("�������� �����������: "); 
	PolynomOutput(subPolynom); //�����

	system("cls");
}

void PolynomialMulti()
{
	Polynomial sub1, sub2;
	do {
		printf_s("\t��������� �����������\n");
		printf_s("������� ������� ������� ����������: "); scanf_s("%d", &sub1.n); // ������ �������� �����������
		printf_s("������� ������� ������� ����������: "); scanf_s("%d", &sub2.n);
		if (sub1.n <= 0 || sub2.n <= 0) system("cls");
	} while (sub1.n <= 0 || sub2.n <= 0 || sub1.n >= 100 || sub2.n >= 100);

	printf_s("������� ��������� ������� ����������: \n"); //���� �������� �����������
	PolynomInput(sub1);
	printf_s("������� ��������� ������� ����������: \n");
	PolynomInput(sub2);

	printf_s("������ ���������: "); // ����� ������� ����������
	PolynomOutput(sub1);

	printf_s("������ ���������: "); // ����� ������� ����������
	PolynomOutput(sub2);

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

void PolynomInput(Polynomial &slag)
{
	for (int i = slag.n; i >= 0; i--) {
		printf_s("c%d = ", i); scanf_s("%lf", &slag.c[i]);
	}
}

void PolynomOutput(Polynomial& slag)
{
	printf_s("%.3lfx^%d", slag.c[slag.n], slag.n);
	for (int i = slag.n - 1; i >= 2; i--) {
		if (slag.c[i] >= 0) printf_s("+%.3lfx^%d", slag.c[i], i);
		else printf_s("%.3lfx^%d", slag.c[i], i);
	}
	if (slag.c[1] >= 0) printf_s("+%.3lfx", slag.c[1]); //��� x^1
	else printf_s("%.3lfx", slag.c[1]);
	if (slag.c[0] >= 0) printf_s("+%lf\n", slag.c[0]); //��� x^0
	else printf_s("%.3lf\n", slag.c[0]);
}
