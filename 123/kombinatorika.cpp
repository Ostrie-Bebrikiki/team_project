#include "kombinatorika.h"
#include "bebra.h"

void menu_kombinatorika()
{
	system("cls");
	char cmd;

	printf_s("1 - ���������� � ������������\n2 - ����������� ��� ����������\n3 - ��������� � �����������\n4 - ��������� ��� ����������\n5 - ������������\n0 - ���������\n");
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