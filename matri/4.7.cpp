#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

void vvod(int n, int m, int mas[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mas[i][j];
        }
    }
}

void randvvod(int n, int m, int mas[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mas[i][j] = rand() % 201 - 100;
        }
    }
}

void vivod(int n, int m, int mas[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(5) << mas[i][j];
        }
        cout << endl;
    }
}

void vivodDouble(int n, int m, double mas[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(8) << fixed << setprecision(2) << mas[i][j];
        }
        cout << endl;
    }
}

//функция деления, проходит по столбам находит диоганальный элемент и делит весь столбец на него
void delenie(int m, int mas[][100], double result[][100]) {
    for (int j = 0; j < m; j++) { // по столбцам
        int diagonalny = mas[j][j]; // диагональный элемент в столбце j

        if (diagonalny == 0) {
            cout << "Ошибка: диагональный элемент в столбце " << j + 1 << " равен 0!" << endl;
            return;
        }

        for (int i = 0; i < m; i++) { // по строкам
            result[i][j] = (double)mas[i][j] / diagonalny;
        }
    }
}

int main() {
    srand(time(0));
    setlocale(LC_ALL, "rus");
    int mas[100][100];
    double result[100][100];
    int n, m, t;

    cout << "Введите размер квадратной матрицы (m x m)" << endl;
    cin >> m;
    n = m; // для квадратной матрицы

    cout << "Введите 1 для ручного ввода и 0 для рандомного заполнения" << endl;
    cin >> t;

    if (t == 1) {
        cout << "Введите элементы матрицы " << m << "x" << m << endl;
        vvod(n, m, mas);
    }
    else if (t == 0) {
        randvvod(n, m, mas);
    }

    cout << "Исходная матрица:" << endl;
    vivod(n, m, mas);

    // Выполняем деление
    delenie(m, mas, result);

    cout << "Результат деления каждого элемента на диагональный в том же столбце:" << endl;
    vivodDouble(m, m, result);

    return 0;
}