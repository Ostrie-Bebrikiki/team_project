// ������������� - ������� ���������
#include "kombinatorika.h"
#include "bebra.h"

void menu_kombinatorika()
{
	system("cls");
	char cmd;
	while (true)
	{
		while (true)
		{
			printf_s("1 - ���������� � ������������\n2 - ����������� ��� ����������\n3 - ��������� � �����������\n4 - ��������� ��� ����������\n5 - ������������ ��� ����������\n6 - ���������� � ������������\n0 - ���������\n");
			cmd = _getche();
			if (cmd == '1' || cmd == '2' || cmd == '3' || cmd == '4' || cmd == '5' || cmd == '6' || cmd == '0')
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
		case '0': return;
		}
	}
}

void placement_with()
{
	system("cls");
	int i, error;
	string tmp;
	unsigned int n, k;
	unsigned long long int x;
	char cmd;
	while (true)
	{
		printf_s("������� ���������� ��������� n: ");
		do
		{
			do
			{
				i = 0;
				error = 0;
				getline(cin, tmp);
				if (tmp.empty() || tmp.length() >= 1)
				{
					printf_s("�������� ����.\n\n? : ");
					error = 1;
				}
				while (i < tmp.length())
				{
					if (isdigit(tmp[i]) == 0)
					{
						printf_s("�������� ����.\n\n? : ");
						error = 1;
						break;
					}
					i++;
				}
			} while (error == 1);

			n = stoi(tmp, 0, 10);

			if (n < 1)
			{
				printf_s("�������� ����.\n\n? : ");
			}

		} while (n < 1);
		x = n;
		printf_s("������� ���������� ������� k: ");
		do
		{
			do
			{
				i = 0;
				error = 0;
				getline(cin, tmp);
				if (tmp.empty() || tmp.length() >= 10)
				{
					printf_s("�������� ����.\n\n? : ");
					error = 1;
				}
				while (i < tmp.length())
				{
					if (isdigit(tmp[i]) == 0)
					{
						printf_s("�������� ����.\n\n? : ");
						error = 1;
						break;
					}
					i++;
				}
			} while (error == 1);

			k = stoi(tmp, 0, 10);

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
	int i, error;
	string tmp;
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
			do
			{
				i = 0;
				error = 0;
				getline(cin, tmp);
				if (tmp.empty() || tmp.length() >= 10)
				{
					printf_s("�������� ����.\n\n? : ");
					error = 1;
				}
				while (i < tmp.length())
				{
					if (isdigit(tmp[i]) == 0)
					{
						printf_s("�������� ����.\n\n? : ");
						error = 1;
						break;
					}
					i++;
				}
			} while (error == 1);

			n = stoi(tmp, 0, 10);

			if (n <= 1)
			{
				printf_s("�������� ����.\n\n? : ");
			}
		} while (n <= 1);

		printf_s("������� ���������� ������� k (k <= n): ");
		do
		{
			do
			{
				i = 0;
				error = 0;
				getline(cin, tmp);
				if (tmp.empty() || tmp.length() >= 10)
				{
					printf_s("�������� ����.\n\n? : ");
					error = 1;
				}
				while (i < tmp.length())
				{
					if (isdigit(tmp[i]) == 0)
					{
						printf_s("�������� ����.\n\n? : ");
						error = 1;
						break;
					}
					i++;
				}
			} while (error == 1);

			k = stoi(tmp, 0, 10);

			if (k > n || k < 1)
			{
				printf_s("�������� ����.\n\n? : ");
			}
		} while (k > n || k < 1);

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
	system("cls");
	int i, error;
	string tmp;
	unsigned int n, k;
	char cmd;
	while (true)
	{
		unsigned long long int x = 1, fact = 1;
		printf_s("������� ���������� n ��������� ���������: ");
		do
		{
			do
			{
				i = 0;
				error = 0;
				getline(cin, tmp);
				if (tmp.empty() || tmp.length() >= 10)
				{
					printf_s("�������� ����.\n\n? : ");
					error = 1;
				}
				while (i < tmp.length())
				{
					if (isdigit(tmp[i]) == 0)
					{
						printf_s("�������� ����.\n\n? : ");
						error = 1;
						break;
					}
					i++;
				}
			} while (error == 1);

			n = stoi(tmp, 0, 10);

			if (n < 1)
			{
				printf_s("������������ ����.\n\n? : ");
			}
		} while (n < 1);

		printf_s("������� ���������� k ��������� ������: ");
		do
		{
			do
			{
				i = 0;
				error = 0;
				getline(cin, tmp);
				if (tmp.empty() || tmp.length() >= 10)
				{
					printf_s("�������� ����.\n\n? : ");
					error = 1;
				}
				while (i < tmp.length())
				{
					if (isdigit(tmp[i]) == 0)
					{
						printf_s("�������� ����.\n\n? : ");
						error = 1;
						break;
					}
					i++;
				}
			} while (error == 1);

			k = stoi(tmp, 0, 10);

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

		printf_s("\n����� : %ul\n", x);

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
	system("cls");
	int i, error;
	string tmp;
	unsigned int n, k, x;
	char cmd;
	while (true)
	{
		unsigned long long int a = 1, b = 1, c = 1;
		printf_s("������� ���������� n ��������� ���������: ");
		do
		{
			do
			{
				i = 0;
				error = 0;
				getline(cin, tmp);
				if (tmp.empty() || tmp.length() >= 10)
				{
					printf_s("�������� ����.\n\n? : ");
					error = 1;
				}
				while (i < tmp.length())
				{
					if (isdigit(tmp[i]) == 0)
					{
						printf_s("�������� ����.\n\n? : ");
						error = 1;
						break;
					}
					i++;
				}
			} while (error == 1);

			n = stoi(tmp, 0, 10);

			if (n < 1)
			{
				printf_s("������������ ����.\n\n? : ");
			}
		} while (n < 1);

		printf_s("������� ���������� k ��������� ������ (k <= n): ");
		do
		{
			do
			{
				i = 0;
				error = 0;
				getline(cin, tmp);
				if (tmp.empty() || tmp.length() >= 10)
				{
					printf_s("�������� ����.\n\n? : ");
					error = 1;
				}
				while (i < tmp.length())
				{
					if (isdigit(tmp[i]) == 0)
					{
						printf_s("�������� ����.\n\n? : ");
						error = 1;
						break;
					}
					i++;
				}
			} while (error == 1);

			k = stoi(tmp, 0, 10);

			if (k > n)
			{
				printf_s("������������ ����.\n\n? : ");
			}
		} while (k < 1 || k > n);

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
	int i, error;
	string tmp;
	unsigned int n;
	char cmd;
	while (true)
	{
		unsigned long long int x = 1;
		printf_s("������� ���������� ���������, �������� � ������������: ");
		do
		{
			do
			{
				i = 0;
				error = 0;
				getline(cin, tmp);
				if (tmp.empty())
				{
					printf_s("�������� ����.\n\n? : ");
					error = 1;
				}
				while (i < tmp.length() || tmp.length() >= 10)
				{
					if (isdigit(tmp[i]) == 0)
					{
						printf_s("�������� ����.\n\n? : ");
						error = 1;
						break;
					}
					i++;
				}
			} while (error == 1);

			n = stoi(tmp, 0, 10);

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
	system("cls");
	int i, error, sum = 0;
	string tmp;
	unsigned int n, a, fact, tmpF;
	char cmd;
	while (true)
	{
		unsigned long long int x = 1, fact = 1, tmpF = 1;
		printf_s("������� ���������� n ��������� ���������, �������� � ������������: ");
		do
		{
			do
			{
				i = 0;
				error = 0;
				getline(cin, tmp);
				if (tmp.empty() || tmp.length() >= 10)
				{
					printf_s("�������� ����.\n\n? : ");
					error = 1;
				}
				while (i < tmp.length())
				{
					if (isdigit(tmp[i]) == 0)
					{
						printf_s("�������� ����.\n\n? : ");
						error = 1;
						break;
					}
					i++;
				}
			} while (error == 1);

			n = stoi(tmp, 0, 10);

			if (n < 2)
			{
				printf_s("������������ ����.\n\n? : ");
			}
		} while (n < 2);

		for (int j = 1; j <= n; j++)
		{
			printf_s("������� ���������� ��������� � ��������� n%d: ", j);
			do
			{
				i = 0;
				error = 0;
				getline(cin, tmp);
				if (tmp.empty() || tmp.length() >= 10)
				{
					printf_s("�������� ����.\n\n? : ");
					error = 1;
				}
				while (i < tmp.length())
				{
					if (isdigit(tmp[i]) == 0)
					{
						printf_s("�������� ����.\n\n? : ");
						error = 1;
						break;
					}
					i++;
				}
			} while (error == 1);

			a = stoi(tmp, 0, 10);

			tmpF = 1;
			sum += a;
			for (int l = 1; l <= a; l++)
			{
				tmpF *= l;
			}
			
			fact *= tmpF;
		}

		tmpF = 1;
		for (int h = 1; h <= sum; h++)
		{
			tmpF *= h;
		}

		x = tmpF / fact;
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