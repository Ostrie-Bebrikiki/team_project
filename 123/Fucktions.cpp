#include "Functions.h"

void menu_Func() {
	char s;
	while (true) {
		while (true) {
			system("cls");
			cout << "�������� ��������" << endl << "1 - ���������� ������������� ���������" << endl << "2 - ���������� ������� �������"
				<< endl << "3 - ����� ����� ��� Y = 0 �� �������" << endl << "4 - ����� ����������� �� �������" 
				<< endl << "0 - ����� � ������� ����" << endl << '>';
			s = _getche();
			if (s == '0' || s == '1' || s == '2' || s == '3' || s == '4') break;
			system("cls");
		}
		cout << endl;

		switch (s) {
		case '1': break;
		case '2': break;
		case '3': break;
		case '4': break;
		case '0': return;
		default: break;
		}
		cout << endl << "����������?";
		s = tolower(_getche());
		if (s == 'n' || s == '�') break;
		system("cls");
	}
	
}