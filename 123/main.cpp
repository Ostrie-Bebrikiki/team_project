#include "bebra.h"

int main(int argc, char** argv) {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "");
	char s;

	while (true) {
		while (true) {
			cout << "�������� ��� ������������" << endl << "1 - ���������"<< endl << "2 - ������������ ������" 
				<< endl << "3 - ������ �������������" << endl << "4 - ������ ������������ � ���. ����������" << endl
				<<"5 - �����������"<< endl << "6 - ������ � ��������" << endl << '>';
			s = _getche();
			if (s == '1' || s == '2' || s == '3' || s == '4' || s == '5' || s == '6') break;
			system("cls");
		}
		cout << endl;
		
		switch (s) {
			case '1': MenuMatrix(); break;
			case '2': break;
			case '3': menu_kombinatorika(); break;
			case '4': menu_ver(); break;
			case '5': PolynomialMenu(); break;
			case '6': menu_Func(); break;
			default: break;
		}
		system("cls");
	}
	return 0;
}