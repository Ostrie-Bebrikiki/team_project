#include "kombinatorika.h"
#include "bebra.h"

void placement_with();
void placement_without();
void combination_with();
void combination_without();
void transposition();

int menu_kombinatorika()
{
	system("cls");
	char cmd;
	while (true)
	{
		while (true)
		{
			printf_s("1 - ���������� � ������������\n2 - ����������� ��� ����������\n3 - ��������� � �����������\n4 - ��������� ��� ����������\n5 - ������������\n0 - ���������\n");
			cmd = _getche();
			if (cmd == '1' || cmd == '2' || cmd == '3' || cmd == '4' || cmd == '0')
			{
				break;
			}
			system("cls");
		}

		switch (cmd)
		{
		case '1': placement_with(); break;
		case '2': placement_without(); break;
		case '3': combination_with(); break;
		case '4': combination_without(); break;
		case '5': transposition(); break;
		case '0': return 0;
		}
	}
}

void placement_with()
{
	system("cls");
	unsigned int n, k;
	unsigned long long int x;
	char cmd;
	while (true)
	{
		printf_s("������� ���������� �������� n: ");
		do
		{
			scanf_s("%u", &n);
			if (n < 1)
			{
				printf_s("�������� ����.\n\n? : ");
			}
		} while (n < 1);
		x = n;
		printf_s("������� ���������� ������� k: ");
		do
		{
			scanf_s("%u", &k);
			if (k < 1)
			{
				printf_s("�������� ����.\n\n? : ");
			}
		} while (k < 1);

		for (int i = 1; i < k; i++)
		{
			x *= n;
		}

		printf_s("\n����� : %lu\n", x);

		printf_s("\n1 - ��������� � ����.\n����� ������������ ����������� ��� ���, ������� ����� ������.\n\n? : ");
		cmd = _getche();
		if (cmd == '1')
		{
			system("cls");
			return;
		}

		system("cls");
	}
}

void placement_without()
{
	system("cls");
	unsigned int n;
	unsigned long long int x = 1;
	char cmd;
	while (true)
	{
		printf_s("������� ���������� ���������, �������� � ������������: ");
		do
		{
			scanf_s("%u", &n);
			if (n < 1)
			{
				printf_s("������������ ����.\n\n? : ");
			}
		} while (n < 1);
		
		for (int i = 1; i <= n; i++)
		{
			x *= i;
		}

		printf_s("\n����� : %lu\n", x);

		printf_s("\n1 - ��������� � ����.\n����� ������������ ����������� ��� ���, ������� ����� ������.\n\n? : ");
		cmd = _getche();
		if (cmd == '1')
		{
			system("cls");
			return;
		}

		system("cls");
	}
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