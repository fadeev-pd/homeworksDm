#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите порядок латинского квадрата n: ";
    cin >> n;

    if (n <= 0 or n > 100) {
        cout << "Неверный порядок!" << endl;
        return 1;
    }

    int square[100][100];

    // Заполняем первую строку
    for (int j = 0; j < n; ++j) {
        square[0][j] = j + 1;
    }

    // Заполняем остальные строки циклическим сдвигом
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            square[i][j] = square[i - 1][(j + 1) % n];
        }
    }

    // Выводим результат
    cout << "Латинский квадрат порядка " << n << ":" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(3) <<square[i][j];
        }
        cout << endl;
    }

    return 0;
}