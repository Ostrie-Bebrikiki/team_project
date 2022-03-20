//Матричный калькулятор (Кривоносиков Александр)
#include "MatrixCaulculator-Header.h"

void MenuMatrix()
{
    int ex;
    do {
        system("cls");
        setlocale(LC_ALL, "Russian");
        double** A;
        int m;
        double d;
        int n;
        int choose;
        Enter(n, m);
        A = new double* [n];
        for (int i = 0; i < n; i++)
        {
            A[i] = new double[m];
        }

        SetMatrix(n, m, A);
        OutputMatrix(n, m, A);
        do {
            cout << "\nСделайте выбор:\n1.Найти определитель \n2.Транспонировать матрицу \n3.Умножить матрицы\n4.Вычитание матриц\n5.Сложить матрицы\n6.Умножить матрицу на число\n7.Сложить матрицу и число\n8.Найти обратную матрицу\n0.Выход из матричного калькулятора\n";
            cin >> choose;
            cin.clear();
            while (cin.get() != '\n');

        } while (choose < 0 || choose> 8);
        if (choose == 1) { // Определитель
            if (m == n) {
                d = Determinant(A, m);
                cout << "\n Определитель равен = " << d;
            }
            else cout << "Матрица не квадратная , вычислить определитель невозможно";

        }
        if (choose == 2) {// Транспонирование
            double** tA;
            tA = new double* [n];
            for (int i = 0; i < n; i++)
            {
                tA[i] = new double[m];
            }
            TransponMtx(A, tA, n, m);
            OutputMatrix(n, m, tA);
        }
        if (choose == 3) { // Умножение
            MultiplMatrix(n, m, A);
        }
        if (choose == 4) { // Вычитание матриц
            DiffMatrix(n, m, A);
        }
        if (choose == 5) {// Сложение матриц
            SummMartrix(n, m, A);

        }
        if (choose == 6) {
            MultiplNumber(n, m, A);
        }
        if (choose == 7) {
            SummNumber(n, m, A);
        }
        if (choose == 8) {
            if (m == n) {
                if (Determinant(A, m) != 0) {
                    inversionMatrix(A, n);
                }
                else cout << "Определитель матрицы равен 0, обратную матрицу найти нельзя\n";
            }
            else cout << "Матрица не квадратная , найти обратную невозможно";
        }
        do {
            cout << "\nЖелаете выйти из матричного калькулятора?\n1.Да\t2.Нет";
            cin >> ex;
            cin.clear();
            while (cin.get() != '\n');
        } while (ex > 2 || ex < 1);
    } while (ex == 2);
}

void Enter(int& n, int& m) {
    do {
        cout << "Введите количество строк: "; //введите количество строк
        cin >> n;
        cin.clear();
        while (cin.get() != '\n');

    } while (n < 1);
    do {
        cout << "Введите количетсво столбцов: "; //введите количество столбцов
        cin >> m;
        cin.clear();
        while (cin.get() != '\n');

    } while (m < 1);
}
void SetMatrix(int n, int m, double** A) // ввод матрицы 1
{
    cout << "Enter matrix item: " << endl; //введите элемент матрицы
    for (int i = 0; i < n; i++) //цикл на ввод
    {
        for (int j = 0; j < m; j++)
        {
            cout << "[" << i << "][" << j << "]="; //вывод "i" и "j"
            cin >> A[i][j]; //ввод это в массив "A"
            cin.clear();
            while (cin.get() != '\n');
        }
    }
}
void OutputMatrix(int n, int m, double** A) //вывод матрицы 1
{
    cout << "\nВывод  " << " \n \n";


    for (int i = 0; i < n; i++) //цикл для корректного вывода
    {
        for (int j = 0; j < m; j++)
        {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
}
void GetMatr(double** A, double** p, int i, int j, int m) { // для Определителя
    int ki, kj, di, dj;
    di = 0;
    for (ki = 0; ki < m - 1; ki++) { // проверка индекса строки
        if (ki == i) di = 1;
        dj = 0;
        for (kj = 0; kj < m - 1; kj++) { // проверка индекса столбца
            if (kj == j) dj = 1;
            p[ki][kj] = A[ki + di][kj + dj];
        }
    }
}
double Determinant(double** A, int m) { // для Определителя
    int i, j, k, n1;
    double d;
    double** p;
    p = new double* [m];
    for (i = 0; i < m; i++)
        p[i] = new double[m];
    j = 0; d = 0;
    k = 1; //(-1) в степени i
    n1 = m - 1;
    if (m < 1) cout << "Определитель вычислить невозможно!";
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
    SetMatrix(nb, mb, B);
    if (nb != n || mb != m) {
        cout << "Совершить вычитание невозможно , размеры матриц не равны";
    }
    else
    {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                A[i][j] = A[i][j] - B[i][j];
            }
        }
        OutputMatrix(n, m, A);
    }
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
    SetMatrix(nb, mb, B);
    if (nb != n || mb != m) {
        cout << "Совершить сложение невозможно , размеры матриц не равны";

    }
    else
    {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                A[i][j] = A[i][j] + B[i][j];
            }
        }
        OutputMatrix(n, m, A);
    }
}
void MultiplMatrix(int n, int m, double** A) {
    int nb, mb; // Для умножения матриц
    double** B;
    Enter(nb, mb);
    B = new double* [nb];
    for (int i = 0; i < nb; i++)
    {
        B[i] = new double[mb];
    }
    SetMatrix(nb, mb, B);
    int nc, mc; // Для умножения матриц
    double** C;
    C = new double* [n];
    for (int i = 0; i < n; i++)
    {
        C[i] = new double[mb];
    }

    if (m == nb) {
        cout << "Matrix C=AB:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < mb; j++) {
                C[i][j] = 0;

                for (int k = 0; k < n; k++)
                    C[i][j] += A[i][k] * B[k][j];

            }
        }
        OutputMatrix(n, mb, C);
    }
    else cout << "Матрицы невозможно умножить";
}
void MultiplNumber(int n, int m, double** A) {
    int nb, mb; // Для умножения матриц
    double number;
    cout << "Введите число , на которое собираетесь умножить: ";
    cin >> number;
    cin.clear();
    while (cin.get() != '\n');


    cout << "Matrix C=AB:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = A[i][j] * number;
        }
    }
    OutputMatrix(n, m, A);

}
void SummNumber(int n, int m, double** A) {
    int nb, mb; // Для умножения матриц
    double number;
    cout << "Введите число , с которым собираетесь складывать: ";
    cin >> number;
    cin.clear();
    while (cin.get() != '\n');


    cout << "Matrix C=AB:\n";
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

    for (int i = 0; i < n; i++) //цикл для корректного вывода
    {
        for (int j = 0; j < n; j++)
        {
            cout << B[i][j] << "\t";
        }
        cout << endl;
    }
}