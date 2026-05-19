#include <iostream>
#include <iomanip>
using namespace std;

// Функция для заполнения матрицы по спирали
void Spiral(int matrix[][100], int m, int n) {
    int top = 0, bottom = m - 1;      // Границы по строкам
    int left = 0, right = n - 1;      // Границы по столбцам
    int num = 1;                       // Текущее число для заполнения

    while (top <= bottom and left <= right) {
        //Заполняем верхнюю строку (слева направо)
        for (int j = left; j <= right; ++j) {
            matrix[top][j] = num++;
        }
        top++; //Верхняя граница опускается вниз

        //Заполняем правый столбец (сверху вниз)
        for (int i = top; i <= bottom; ++i) {
            matrix[i][right] = num++;
        }
        right--; // Правая граница сдвигается влево

        //Заполняем нижнюю строку (справа налево)
        if (top <= bottom) {
            for (int j = right; j >= left; --j) {
                matrix[bottom][j] = num++;
            }
            bottom--; //Нижняя граница поднимается вверх
        }

        //Заполняем левый столбец (снизу вверх)
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = num++;
            }
            left++; //Левая граница сдвигается вправо
        }
    }
}

//Функция для вывода матрицы
void printMatrix(int matrix[][100], int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int m, n;
    int matrix[100][100];

    cout << "Введите количество строк m (не более " << 100 << "): ";
    cin >> m;
    cout << "Введите количество столбцов n (не более " << 100 << "): ";
    cin >> n;

    if (m <= 0 or n <= 0 or m > 100 or n > 100) {
        cout << "Неверные размеры матрицы!" << endl;
        return 1;
    }

    //Заполняем матрицу по спирали
    Spiral(matrix, m, n);

    //Выводим результат
    cout << "Матрица заполненная по спирали:" << endl;
    printMatrix(matrix, m, n);

    return 0;
}