#include <iostream>
using namespace std;

// Функция для сравнения двух строк (начиная с характеристик, т.е. со 2-го элемента)
bool compareCharacteristics(int row1[], int row2[], int n) {
    // Сравниваем характеристики (элементы с индекса 1 до n-1)
    for (int j = 1; j < n; ++j) {
        if (row1[j] != row2[j]) {
            return false; // Характеристики не совпадают
        }
    }
    return true; // Характеристики совпадают
}

// Функция для удаления строки из матрицы
void deleteRow(int matrix[][100], int& m, int n, int rowIndex) {
    // Сдвигаем все строки после удаляемой вверх
    for (int i = rowIndex; i < m - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = matrix[i + 1][j];
        }
    }
    m--; // Уменьшаем количество строк
}

// Функция для вывода матрицы
void printMatrix(int matrix[][100], int m, int n) {
    cout << "Оставшаяся после резекции матрица:" << endl;;
    if (m == 0) {
        cout << "Матрица пуста" << endl;
        return;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int m, n;
    int matrix[100][100];
    bool toDelete[100] = { false }; // Массив флагов для удаления

    cout << "Введите количество строк m: ";
    cin >> m;
    cout << "Введите количество столбцов n (первый - шифр, остальные - характеристики): ";
    cin >> n;

    if (m <= 0 || n < 2) {
        cout << "Ошибка: m должно быть > 0, n должно быть >= 2" << endl;
        return 1;
    }

    // Ввод матрицы
    cout << "\nВведите матрицу " << m << " x " << n << ":\n";
    cout << "(первый элемент каждой строки - шифр детали, остальные - характеристики)\n";
    for (int i = 0; i < m; ++i) {
        cout << "Строка " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Выявление строк для удаления
    // Строка удаляется, если есть другая строка с таким же шифром,
    // но с отличающимися характеристиками
    for (int i = 0; i < m; ++i) {
        for (int k = i + 1; k < m; ++k) {
            // Если шифры совпадают
            if (matrix[i][0] == matrix[k][0]) {
                // Проверяем характеристики
                if (!compareCharacteristics(matrix[i], matrix[k], n)) {
                    // Характеристики не совпадают - обе строки подлежат удалению
                    toDelete[i] = true;
                    toDelete[k] = true;
                }
            }
        }
    }

    // Вывод номеров строк, подлежащих удалению
    cout << "\nНомера строк с совпадающими шифрами и несовпадающими характеристиками: ";
    bool found = false;
    for (int i = 0; i < m; ++i) {
        if (toDelete[i]) {
            cout << i + 1 << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "нет таких строк";
    }
    cout << endl;

    // Удаление помеченных строк
    // Удаляем с конца, чтобы не сбивать индексы
    for (int i = m - 1; i >= 0; --i) {
        if (toDelete[i]) {
            deleteRow(matrix, m, n, i);
        }
    }

    // Вывод оставшейся матрицы
    printMatrix(matrix, m, n);

    return 0;
}