#include <iostream>
using namespace std;

// Функция для вывода матрицы
void printMatrix(int matrix[][100], int m, int n) {
    cout << "Поле после удаления видимых непрозрачных кубиков" << endl;
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
    int field[100][100];     // Исходное поле (1 - непрозрачный, 0 - прозрачный)
    bool toDelete[100][100]; // Флаги для удаления (видимые кубики)

    cout << "Введите размеры поля m x n: ";
    cin >> m >> n;

    if (m <= 0 || n <= 0) {
        cout << "Ошибка: размеры должны быть положительными" << endl;
        return 1;
    }

    // Ввод поля
    cout << "\nВведите поле " << m << " x " << n << " (1 - непрозрачный, 0 - прозрачный):\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> field[i][j];
        }
    }

    // Инициализация флагов удаления (пока ничего не удаляем)
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            toDelete[i][j] = false;
        }
    }

    // Анализ видимости с четырех сторон

    // 1. Видимость сверху (смотрим сверху вниз по каждому столбцу)
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            if (field[i][j] == 1) {
                toDelete[i][j] = true; // Первый непрозрачный в столбце видим
                break;                 // Дальше не смотрим
            }
        }
    }

    // 2. Видимость снизу (смотрим снизу вверх по каждому столбцу)
    for (int j = 0; j < n; ++j) {
        for (int i = m - 1; i >= 0; --i) {
            if (field[i][j] == 1) {
                toDelete[i][j] = true;
                break;
            }
        }
    }

    // 3. Видимость слева (смотрим слева направо по каждой строке)
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (field[i][j] == 1) {
                toDelete[i][j] = true;
                break;
            }
        }
    }

    // 4. Видимость справа (смотрим справа налево по каждой строке)
    for (int i = 0; i < m; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            if (field[i][j] == 1) {
                toDelete[i][j] = true;
                break;
            }
        }
    }

    // Вывод информации о видимых кубиках
    cout << "\nНепрозрачные кубики, видимые хотя бы с одной стороны:\n";
    bool found = false;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (toDelete[i][j] && field[i][j] == 1) {
                cout << "(" << i + 1 << "," << j + 1 << ") ";
                found = true;
            }
        }
    }
    if (!found) {
        cout << "нет таких кубиков";
    }
    cout << endl;

    // Удаление видимых кубиков (делаем их прозрачными)
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (toDelete[i][j]) {
                field[i][j] = 0; // Делаем прозрачным
            }
        }
    }

    // Вывод результата
    printMatrix(field, m, n);

    return 0;
}