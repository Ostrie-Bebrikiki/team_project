//��������� ����������� (������������ ���������)
#include "MatrixCaulculatorHeader.h"
#include "bebra.h"

void MenuMatrix()
{
    setlocale(LC_ALL, "Russian");
    double** A;
    int m;
    double d;
    int n;
    char choose;

    while (true) 
    {
        while (true) 
        {
            system("cls");
            cout << "�������� ��������\n1 - ����� ������������ \n2 - ��������������� ������� \n3 - �������� �������\n4 - ��������� ������\n5 - ������� �������\
6 - �������� ������� �� �����\n7 - ������� ������� � �����\n8 - ����� �������� �������\n0 - ����� � ������� ����\n";
            choose = _getche();
            if (choose == '1' || choose == '2' || choose == '3' || choose == '4' || choose == '5' || choose == '6' || choose == '7' || choose == '8' || choose == '0')
            {
                system("cls");
                break;
            }
            system("cls");
        } 
        if (choose == '1') { // ������������
            Enter(n, m);
            A = new double* [n];
            for (int i = 0; i < n; i++)
            {
                A[i] = new double[m];
            }

            SetMatrix(n, m, A);
            OutputMatrix(n, m, A);
            if (m == n) {
                d = Determinant(A, m);
                cout << "\n������������ ����� = " << d << endl;

            }
            else cout << "������� �� ����������, ��������� ������������ ����������" << endl;
            FreeMem(n, m, A);

        }
        if (choose == '2') {// ����������������
            Enter(n, m);
            A = new double* [n];
            for (int i = 0; i < n; i++)
            {
                A[i] = new double[m];
            }

            SetMatrix(n, m, A);
            OutputMatrix(n, m, A);
            double** tA;
            tA = new double* [m];
            for (int i = 0; i < m; i++)
            {
                tA[i] = new double[n];
            }
            TransponMtx(A, tA, n, m);
            OutputMatrix(m, n, tA);
            FreeMem(m, n, tA);
            FreeMem(n, m, A);
        }
        if (choose == '3') { // ���������
            Enter(n, m);
            A = new double* [n];
            for (int i = 0; i < n; i++)
            {
                A[i] = new double[m];
            }

            SetMatrix(n, m, A);
            OutputMatrix(n, m, A);
            MultiplMatrix(n, m, A);
            FreeMem(n, m, A);
        }
        if (choose == '4') { // ��������� ������
            Enter(n, m);
            A = new double* [n];
            for (int i = 0; i < n; i++)
            {
                A[i] = new double[m];
            }

            SetMatrix(n, m, A);
            OutputMatrix(n, m, A);
            DiffMatrix(n, m, A);
            FreeMem(n, m, A);
        }
        if (choose == '5') {// �������� ������
            Enter(n, m);
            A = new double* [n];
            for (int i = 0; i < n; i++)
            {
                A[i] = new double[m];
            }

            SetMatrix(n, m, A);
            OutputMatrix(n, m, A);
            SummMartrix(n, m, A);
            FreeMem(n, m, A);

        }
        if (choose == '6') {
            Enter(n, m);
            A = new double* [n];
            for (int i = 0; i < n; i++)
            {
                A[i] = new double[m];
            }

            SetMatrix(n, m, A);
            OutputMatrix(n, m, A);
            MultiplNumber(n, m, A);
            FreeMem(n, m, A);
        }
        if (choose == '7') {
            Enter(n, m);
            A = new double* [n];
            for (int i = 0; i < n; i++)
            {
                A[i] = new double[m];
            }

            SetMatrix(n, m, A);
            OutputMatrix(n, m, A);
            SummNumber(n, m, A);
            FreeMem(n, m, A);
        }
        if (choose == '8') {
            Enter(n, m);
            A = new double* [n];
            for (int i = 0; i < n; i++)
            {
                A[i] = new double[m];
            }

            SetMatrix(n, m, A);
            OutputMatrix(n, m, A);
            if (m == n) {
                if (Determinant(A, m) != 0) {
                    inversionMatrix(A, n);
                    FreeMem(n, m, A);
                }
                else cout << "������������ ������� ����� 0, �������� ������� ����� ������" << endl;
            }
            else cout << "������� �� ���������� , ����� �������� ����������" << endl;
        }

        if (choose == '0')
        {
            return;
        }

        system("pause");
    }
}

void Enter(int& n, int& m) {
    cout << "\n���� ����� � ��������\n";
    do {
        cout << "������� ���������� �����: "; //������� ���������� �����
        cin >> n;
        cin.clear();
        while (cin.get() != '\n');

    } while (n < 1);
    do {
        cout << "������� ���������� ��������: "; //������� ���������� ��������
        cin >> m;
        cin.clear();
        while (cin.get() != '\n');

    } while (m < 1);
}
void SetMatrix(int n, int m, double** A) // ���� ������� 1
{
    cout << "���� ��������� �������: " << endl; //������� ������� �������
    for (int i = 0; i < n; i++) //���� �� ����
    {
        for (int j = 0; j < m; j++)
        {
            cout << "[" << i << "][" << j << "]="; //����� "i" � "j"
            cin >> A[i][j]; //���� ��� � ������ "A"
            cin.clear();
            while (cin.get() != '\n');
        }
    }
}
void OutputMatrix(int n, int m, double** A) //����� ������� 1
{
    cout << "\n�����  " << " \n \n";


    for (int i = 0; i < n; i++) //���� ��� ����������� ������
    {
        for (int j = 0; j < m; j++)
        {
            cout << fixed << showpoint << setprecision(3);
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\n";
}
void GetMatr(double** A, double** p, int i, int j, int m) { // ��� ������������
    int ki, kj, di, dj;
    di = 0;
    for (ki = 0; ki < m - 1; ki++) { // �������� ������� ������
        if (ki == i) di = 1;
        dj = 0;
        for (kj = 0; kj < m - 1; kj++) { // �������� ������� �������
            if (kj == j) dj = 1;
            p[ki][kj] = A[ki + di][kj + dj];
        }
    }
}
double Determinant(double** A, int m) { // ��� ������������
    int i, j, k, n1;
    double d;
    double** p;
    p = new double* [m];
    for (i = 0; i < m; i++)
        p[i] = new double[m];
    j = 0; d = 0;
    k = 1; //(-1) � ������� i
    n1 = m - 1;
    if (m < 1) cout << "������������ ��������� ����������!";
    if (m == 1) {
        d = A[0][0];
        return(d);
    }
    if (m == 2) {
        d = A[0][0] * A[1][1] - (A[1][0] * A[0][1]);
        return(d);
    }
    if (m > 2) {
        for (i = 0; i < m; i++) {
            GetMatr(A, p, i, 0, m);
            d = d + k * A[i][0] * Determinant(p, n1);
            k = -k;
        }
    }
    FreeMem(m, m, p);
    return(d);
}
void TransponMtx(double** A, double** tA, int n, int m) {//
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            tA[j][i] = A[i][j];
}
void DiffMatrix(int n, int m, double** A) {
    int nb, mb;
    double** B;
    Enter(nb, mb);
    B = new double* [nb];
    for (int i = 0; i < nb; i++)
    {
        B[i] = new double[mb];
    }

    if (nb != n || mb != m) {
        cout << "��������� ��������� ���������� , ������� ������ �� �����";
    }
    else
    {
        SetMatrix(nb, mb, B);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                A[i][j] = A[i][j] - B[i][j];
            }
        }
        OutputMatrix(n, m, A);
    }
    FreeMem(nb, mb, B);
}
void SummMartrix(int n, int m, double** A) {
    int nb, mb;
    double** B;
    Enter(nb, mb);
    B = new double* [nb];
    for (int i = 0; i < nb; i++)
    {
        B[i] = new double[mb];
    }

    if (nb != n || mb != m) {
        cout << "��������� �������� ���������� , ������� ������ �� �����";

    }
    else
    {
        SetMatrix(nb, mb, B);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                A[i][j] = A[i][j] + B[i][j];
            }
        }
        OutputMatrix(n, m, A);
    }
    FreeMem(nb, mb, B);
}
void MultiplMatrix(int n, int m, double** A) {
    int nb, mb; // ��� ��������� ������
    double** B;
    Enter(nb, mb);
    B = new double* [nb];
    for (int i = 0; i < nb; i++)
    {
        B[i] = new double[mb];
    }
    int nc, mc; // ��� ��������� ������
    double** C;
    C = new double* [mb];
    for (int i = 0; i < mb; i++)
    {
        C[i] = new double[n];
    }
    if (m == nb) {
        SetMatrix(nb, mb, B);




        cout << "������� (C = AB):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < mb; j++) {
                C[i][j] = 0;

                for (int k = 0; k < m; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }


            }
        }
        OutputMatrix(n, mb, C);
    }
    else cout << "������� ���������� ��������";
    FreeMem(nb, mb, B);
    FreeMem(mb, n, C);
}
void MultiplNumber(int n, int m, double** A) {
    int nb, mb; // ��� ��������� ������
    double number;
    cout << "������� ����� , �� ������� ����������� ��������: ";
    cin >> number;
    cin.clear();
    while (cin.get() != '\n');


    cout << "������� (A * �����):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = A[i][j] * number;
        }
    }
    OutputMatrix(n, m, A);

}
void SummNumber(int n, int m, double** A) {
    int nb, mb; // ��� ��������� ������
    double number;
    cout << "������� ����� , � ������� ����������� ����������: ";
    cin >> number;
    cin.clear();
    while (cin.get() != '\n');


    cout << "������� (A + �����):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = A[i][j] + number;
        }
    }
    OutputMatrix(n, m, A);

}

void inversionMatrix(double** A, int n)
{
    double temp;
    double** B;
    B = new double* [n];
    for (int i = 0; i < n; i++)
    {
        B[i] = new double[n];
    }
    double** C;
    C = new double* [n];
    for (int i = 0; i < n; i++)
    {
        C[i] = new double[n];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            B[i][j] = 0;

            if (i == j)
                B[i][j] = 1.0;
        }

    for (int k = 0; k < n; k++)
    {
        temp = C[k][k];

        for (int j = 0; j < n; j++)
        {
            C[k][j] /= temp;
            B[k][j] /= temp;
        }

        for (int i = k + 1; i < n; i++)
        {
            temp = C[i][k];

            for (int j = 0; j < n; j++)
            {
                C[i][j] -= C[k][j] * temp;
                B[i][j] -= B[k][j] * temp;
            }
        }
    }

    for (int k = n - 1; k > 0; k--)
    {
        for (int i = k - 1; i >= 0; i--)
        {
            temp = C[i][k];

            for (int j = 0; j < n; j++)
            {
                C[i][j] -= C[k][j] * temp;
                B[i][j] -= B[k][j] * temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = B[i][j];

    for (int i = 0; i < n; i++) //���� ��� ����������� ������
    {
        for (int j = 0; j < n; j++)
        {
            cout << fixed << showpoint << setprecision(4);
            cout << B[i][j] << "\t";
        }
        cout << endl;
    }
    FreeMem(n, n, B);
    FreeMem(n, n, C);
}

void FreeMem(int n, int m, double** A) {
    for (int i = 0; i < n; ++i)
        delete[] A[i];
    delete[] A;
}