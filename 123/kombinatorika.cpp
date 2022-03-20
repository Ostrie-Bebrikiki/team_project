// ������������� - ������� ���������
#include "kombinatorika.h"
#include "bebra.h"

int menu_kombinatorika()
{
	system("cls");
	char cmd;
	while (true)
	{
		while (true)
		{
			printf_s("1 - ���������� � ������������\n2 - ����������� ��� ����������\n3 - ��������� � �����������\n4 - ��������� ��� ����������\n5 - ������������ ��� ����������\n6 - ���������� � ������������\n0 - ���������\n");
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
		case '5': transposition_without(); break;
		case '6': transposition_with(); break;
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
		printf_s("������� ���������� ��������� n: ");
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
	unsigned int n, k;
	unsigned long long int x, fact;
	char cmd;
	while (true)
	{
		x = 1;
		fact = 1;
		printf_s("������� ���������� ��������� n: ");
		do
		{
			scanf_s("%u", &n);
			if (n <= 1)
			{
				printf_s("�������� ����.\n\n? : ");
			}
		} while (n <= 1);

		printf_s("������� ���������� ������� k (k < n): ");
		do
		{
			scanf_s("%u", &k);
			if (k >= n || k < 1)
			{
				printf_s("�������� ����.\n\n? : ");
			}
		} while (k >= n || k < 1);

		for (int i = 1; i <= n; i++)
		{
			x *= i;
		}

		for (int j = 1; j <= (n - k); j++)
		{
			fact *= j;
		}

		x /= fact;

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
	while (true)
	{
		system("cls");
		unsigned int n, k;
		unsigned long long int x = 1, fact = 1;
		char cmd;
		printf_s("������� ���������� n ��������� ���������: ");
		do
		{
			scanf_s("%u", &n);
			if (n < 1)
			{
				printf_s("������������ ����.\n\n? : ");
			}
		} while (n < 1);

		printf_s("������� ���������� k ��������� ������: ");
		do
		{
			scanf_s("%u", &k);
			if (k < 1)
			{
				printf_s("������������ ����.\n\n? : ");
			}
		} while (k < 1);

		for (int i = 1; i <= (n + k - 1); i++)
		{
			x *= i;
			if (i == n + k - 1)
			{
				for (int j = 1; j <= k; j++)
				{
					fact *= j;
					if (j == k)
					{
						x /= (n - 1) * fact;
					}
				}
			}
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

void combination_without()
{
	while (true)
	{
		system("cls");
		unsigned int n, k, x;
		unsigned long long int a = 1, b = 1, c = 1;
		char cmd;
		printf_s("������� ���������� n ��������� ���������: ");
		do
		{
			scanf_s("%u", &n);
			if (n < 1)
			{
				printf_s("������������ ����.\n\n? : ");
			}
		} while (n < 1);

		printf_s("������� ���������� k ��������� ������ (k <= n): ");
		do
		{
			scanf_s("%u", &k);
			if (k > n)
			{
				printf_s("������������ ����.\n\n? : ");
			}
		} while (k > n);

		for (int i = 1; i <= n; i++)
		{
			a *= i;
			if (i == n)
			{
				for (int j = 1; j <= k; j++)
				{
					b *= j;
					if (j == k)
					{
						for (int l = 1; l <= (n - k); l++)
						{
							c *= l;
						}
					}
				}
			}
		}

		x = a / (b * c);

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

void transposition_without()
{
	system("cls");
	unsigned int n;
	char cmd;
	while (true)
	{
		unsigned long long int x = 1;
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

void transposition_with()
{

}