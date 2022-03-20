// Ответственный - Крупеня Александр
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
			printf_s("1 - Размещение с повторениями\n2 - Размещенеие без повторений\n3 - Сочетание с повторением\n4 - Сочетание без повторений\n5 - Перестановки без повторений\n6 - Постановки с повторениями\n0 - Вернуться\n");
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
		printf_s("Введите количество элементов n: ");
		do
		{
			scanf_s("%u", &n);
			if (n < 1)
			{
				printf_s("Неверный ввод.\n\n? : ");
			}
		} while (n < 1);
		x = n;
		printf_s("Введите количество позиций k: ");
		do
		{
			scanf_s("%u", &k);
			if (k < 1)
			{
				printf_s("Неверный ввод.\n\n? : ");
			}
		} while (k < 1);

		for (int i = 1; i < k; i++)
		{
			x *= n;
		}

		printf_s("\nОтвет : %lu\n", x);

		printf_s("\n1 - Вернуться в меню.\nЧтобы использовать калькулятор ещё раз, нажмите любую кнопку.\n\n? : ");
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
		printf_s("Введите количество элементов n: ");
		do
		{
			scanf_s("%u", &n);
			if (n <= 1)
			{
				printf_s("Неверный ввод.\n\n? : ");
			}
		} while (n <= 1);

		printf_s("Введите количество позиций k (k < n): ");
		do
		{
			scanf_s("%u", &k);
			if (k >= n || k < 1)
			{
				printf_s("Неверный ввод.\n\n? : ");
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

		printf_s("\nОтвет : %lu\n", x);

		printf_s("\n1 - Вернуться в меню.\nЧтобы использовать калькулятор ещё раз, нажмите любую кнопку.\n\n? : ");
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
		printf_s("Введите количество n элементов множества: ");
		do
		{
			scanf_s("%u", &n);
			if (n < 1)
			{
				printf_s("Некорректный ввод.\n\n? : ");
			}
		} while (n < 1);

		printf_s("Введите количество k элементов выбора: ");
		do
		{
			scanf_s("%u", &k);
			if (k < 1)
			{
				printf_s("Некорректный ввод.\n\n? : ");
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

		printf_s("\nОтвет : %lu\n", x);

		printf_s("\n1 - Вернуться в меню.\nЧтобы использовать калькулятор ещё раз, нажмите любую кнопку.\n\n? : ");
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
		printf_s("Введите количество n элементов множества: ");
		do
		{
			scanf_s("%u", &n);
			if (n < 1)
			{
				printf_s("Некорректный ввод.\n\n? : ");
			}
		} while (n < 1);

		printf_s("Введите количество k элементов выбора (k <= n): ");
		do
		{
			scanf_s("%u", &k);
			if (k > n)
			{
				printf_s("Некорректный ввод.\n\n? : ");
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

		printf_s("\nОтвет : %lu\n", x);

		printf_s("\n1 - Вернуться в меню.\nЧтобы использовать калькулятор ещё раз, нажмите любую кнопку.\n\n? : ");
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
		printf_s("Введите количество элементов, входящих в перестановку: ");
		do
		{
			scanf_s("%u", &n);
			if (n < 1)
			{
				printf_s("Некорректный ввод.\n\n? : ");
			}
		} while (n < 1);

		for (int i = 1; i <= n; i++)
		{
			x *= i;
		}

		printf_s("\nОтвет : %lu\n", x);

		printf_s("\n1 - Вернуться в меню.\nЧтобы использовать калькулятор ещё раз, нажмите любую кнопку.\n\n? : ");
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