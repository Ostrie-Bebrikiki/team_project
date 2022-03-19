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

	printf_s("1 - Размещение с повторениями\n2 - Размещенеие без повторений\n3 - Сочетание с повторением\n4 - Сочетание без повторений\n5 - Перестановки\n0 - Вернуться\n");
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

		printf_s("1 - Ещё раз.\n2 - В меню.\n\n? : ");

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