#include <conio.h>
#include <iostream>
#include "header_ver.h"
using namespace std;

void menu_ver() {
	char s;
	while (true) {
		while (true) {
			cout << "�������� ������" << endl << "1 - ����������� m/n" << endl << "2 - ��������� ��� ����������� ������������� �������"
				<< endl << "3 - ���. �������� ��� ����������� ������������� �������" << endl << '>';
			s = _getche();
			if (s == '1' || s == '2' || s == '3') break;
			system("cls");
		}
		cout << endl;

		switch (s) {
		case '1':ver();
		case '2':;
		case '3':;
		}
		cout << endl << "����������?";
		s = tolower(_getche());
		if (s == 'n' || s == '�') break;
		system("cls");
	}
}