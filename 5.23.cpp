#include <iostream>
#include <ctime>
#include <cmath> // для abs()
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите n (размер массивов B и C): ";
    cin >> n;

    int sizeA = 2 * n;
    int x;
    int A[100];     // исходный массив (максимум 100 элементов)
    bool used[100]; // массив для отметки использованных элементов
    int B[100];     // массив для меньших элементов
    int C[100];     // массив для больших элементов

    // Ввод элементов массива A
    cout << "Введите 1 для ручного заполнения массива A и 0 для автоматического: " << endl;
    cin >> x;
    if (x == 1) {
        cout << "Введите элементы массива A: " << endl;
        for (int i = 0; i < sizeA; i++) {
            cin >> A[i]; //Ручной ввод
            used[i] = false; // изначально все элементы не использованы
        }
    }
    else if (x == 0) {
        for (int i = 0; i < sizeA; i++) {
            A[i] = rand() % 201 - 100; //Автоматический ввод
            used[i] = false; // изначально все элементы не использованы
        }
    }
    else {
        cout << "Некорректные данные." << endl;
        return 0;
    }

    cout << "Полученный массив A: " << endl;
    for (int i = 0; i < sizeA; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    int countB = 0; // счетчик для массива B
    int countC = 0; // счетчик для массива C

    // Основной цикл: выполняем n шагов (по 2 элемента за шаг)
    for (int step = 0; step < n; step++) {
        int bestI = -1, bestJ = -1;
        int minDiff = 2147483647; // максимальное значение int

        // Поиск двух наиболее близких неиспользованных элементов
        for (int i = 0; i < sizeA; i++) {
            if (used[i]) continue; // пропускаем уже использованные
            for (int j = i + 1; j < sizeA; j++) {
                if (used[j]) continue;
                int diff = abs(A[i] - A[j]);
                if (diff < minDiff) {
                    minDiff = diff;
                    bestI = i;
                    bestJ = j;
                }
            }
        }

        // Меньший элемент помещаем в B, больший - в C
        if (A[bestI] < A[bestJ]) {
            B[countB] = A[bestI];
            C[countC] = A[bestJ];
        }
        else {
            B[countB] = A[bestJ];
            C[countC] = A[bestI];
        }
        countB++;
        countC++;

        // Отмечаем элементы как использованные
        used[bestI] = true;
        used[bestJ] = true;
    }

    // Вывод массива B
    cout << "Массив B: ";
    for (int i = 0; i < countB; i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    // Вывод массива C
    cout << "Массив C: ";
    for (int i = 0; i < countC; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    return 0;
}