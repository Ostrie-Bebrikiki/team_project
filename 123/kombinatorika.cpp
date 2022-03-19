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
			printf_s("1 - Размещение с повторениями\n2 - Размещенеие без повторений\n3 - Сочетание с повторением\n4 - Сочетание без повторений\n5 - Перестановки\n0 - Вернуться\n");
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
	unsigned int n, k, x;
	char cmd;
	while (true)
	{
		printf_s("Введите количество символов n: ");
		do
		{
			scanf_s("%d", &n);
			if (n < 1)
			{
				printf_s("Неверный ввод.\n\n? : ");
			}
		} while (n < 1);
		x = n;
		printf_s("Введите количество позиций k: ");
		do
		{
			scanf_s("%d", &k);
			if (k < 1)
			{
				printf_s("Неверный ввод.\n\n? : ");
			}
		} while (k < 1);

		for (int i = 1; i < k; i++)
		{
			x *= n;
		}

		printf_s("\nОтвет : %d\n", x);

		printf_s("\n1 - Вернуться в меню.\nЧтобы продолжить нажмите любую кнопку.\n\n? : ");
		cmd = _getche();
		if (cmd == '1')
		{
			system("cls");
			printf_s("\n");
			return;
		}

		system("cls");
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