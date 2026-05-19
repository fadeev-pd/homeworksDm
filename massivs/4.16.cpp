#include <iostream>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    int m;
    int K[100];      // исходный массив
    int L[100], M[100];
    int x = 0, y = 0; // индексирование при заполнении двух массивов
    cout << "Введите 1 для ручного заполнения массива и 0 для автоматического: " << endl;
    cin >> m;
    if (m == 1) {
        cout << "Введите элементы массива: " << endl;
        for (int i = 0; i < n; i++) {
            cin >> K[i]; //Ручной ввод
        }
    }
    else if (m == 0) {
        for (int i = 0; i < n; i++) {
            K[i] = rand() % 201 - 100; //Автоматический ввод
        }
    }
    else {
        cout << "Некорректные данные." << endl;
        return 0;
    }

    cout << "Полученный массив: " << endl;
    for (int i = 0; i < n; i++) {
        cout << K[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        if (K[i] % 2 == 0) {
            L[x] = K[i];
            x++;
        }
        else {
            M[y] = K[i];
            y++;
        }
    }
    cout << "Массив L с четными элементами: " << endl;
    for (int i = 0; i < x; i++) {
        cout << L[i] << " ";
    }
    cout << endl;

    cout << "Массив M с нечетными элементами: " << endl;
    for (int i = 0; i < y; i++) {
        cout << M[i] << " ";
    }
    cout << endl;
}