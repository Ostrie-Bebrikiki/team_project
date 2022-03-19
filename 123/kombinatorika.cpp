#include "kombinatorika.h"
#include "bebra.h"

void placement_with();
void placement_without();
void combination_with();
void combination_without();
void transposition();

void menu_kombinatorika()
{
	system("cls");
	char cmd;

	printf_s("1 - ���������� � ������������\n2 - ����������� ��� ����������\n3 - ��������� � �����������\n4 - ��������� ��� ����������\n5 - ������������\n0 - ���������\n");
	cmd = _getche();

	switch(cmd)
	{
	case '1': placement_with(); break;
	case '2': placement_without(); break;
	case '3': combination_with(); break;
	case '4': combination_without(); break;
	case '5': transposition(); break;
	case '0': return;
	}
}

void placement_with()
{
	system("cls");
	int n, k, x;
	char cmd;
	while (true)
	{
		printf_s("������� ���������� �������� n: ");
		do
		{
			scanf_s("%d", &n);
			if (n < 1)
			{
				printf_s("�������� ����.\n\n? : ");
			}
		} while (n < 1);
		x = n;
		printf_s("������� ���������� ������� k: ");
		do
		{
			scanf_s("%d", &k);
			if (k < 1)
			{
				printf_s("�������� ����.\n\n? : ");
			}
		} while (k < 1);

		for (int i = 1; i < k; i++)
		{
			x *= n;
		}

		printf_s("\n����� : %d\n", x);

		printf_s("1 - ��� ���.\n2 - � ����.\n\n? : ");

		cmd = _getche();
		if (cmd == '2')
		{
			break;
			system("cls");
		}
	}
}

void placement_without()
{
}

void combination_with()
{
}

void combination_without()
{
}

void transposition()
{
}