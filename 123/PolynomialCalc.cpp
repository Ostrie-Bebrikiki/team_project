#include "PolynomialCalc.h"
#include "bebra.h"

void PolynomialMenu()
{
	char choose;
	do {
		printf_s("\t����������� �����������\n�������� ��������:\n");
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

		switch (choose)
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

double PolynomalDivision()
{
	return 0.0;
}
