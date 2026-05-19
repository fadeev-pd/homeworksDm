#include <iostream>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    int m;
    int X[100];      // исходный массив
    double result[100]; // массив для результата
    double sum = 0;     // накопленная сумма

    cout << "Введите 1 для ручного заполнения массива и 0 для автоматического: " << endl;
    cin >> m;
    if (m == 1) {
        cout << "Введите элементы массива: " << endl;
        for (int i = 0; i < n; i++) {
            cin >> X[i]; //Ручной ввод
        }
    }
    else if (m == 0) {
        for (int i = 0; i < n; i++) {
            X[i] = rand() % 201 - 100; //Автоматический ввод
        }
    }
    else {
        cout << "Некорректные данные." << endl;
        return 0;
    }

    // Вычисляем сглаженные значения
    for (int i = 0; i < n; i++) {
        sum += X[i];                // добавляем текущий элемент к сумме
        result[i] = sum / (i + 1); // среднее арифметическое первых (i+1) элементов
    }

    cout << "Исходный массив X: ";
    for (int i = 0; i < n; i++) {
        cout << X[i] << " ";
    }
    cout << endl;

    cout << "Сглаженный массив: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}