#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

int main() {
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
			case '1': ;
			case '2': ;
			case '3': ;
			case '4': ;
			case '5': ;
			case '6': ;
		}
		cout << endl << "����������?";
		s = tolower(_getche());
		if (s == 'n' || s == '�') break;
		system("cls");
	}
	return 0;
}