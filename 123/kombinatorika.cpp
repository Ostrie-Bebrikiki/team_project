#include "kombinatorika.h"
#include "bebra.h"

void menu_kombinatorika()
{
	system("cls");
	char cmd;

	printf_s("1 - Размещение с повторениями\n2 - Размещенеие без повторений\n3 - Сочетание с повторением\n4 - Сочетание без повторений\n5 - Перестановки\n0 - Вернуться\n");
	scanf_s("%c", &cmd);
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
	printf_s("")
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