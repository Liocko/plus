#include <iostream>

using namespace std;

int main() {
    // Создание динамических массивов для таблиц A, B и C
    int **A = new int*[3];
    for (int i = 0; i < 3; ++i) {
        A[i] = new int[4];
    }

    double **B = new double*[4];
    for (int i = 0; i < 4; ++i) {
        B[i] = new double[2];
    }

    double **C = new double*[3];
    for (int i = 0; i < 3; ++i) {
        C[i] = new double[2];
        for (int j = 0; j < 2; ++j) {
            C[i][j] = 0; // нулевая матрица С
        }
    }

    // таблица A
    A[0][0] = 5; A[0][1] = 2; A[0][2] = 0; A[0][3] = 10;
    A[1][0] = 3; A[1][1] = 5; A[1][2] = 2; A[1][3] = 5;
    A[2][0] = 20; A[2][1] = 0; A[2][2] = 0; A[2][3] = 0;

    // таблица B
    B[0][0] = 1.20; B[0][1] = 0.50;
    B[1][0] = 2.80; B[1][1] = 0.40;
    B[2][0] = 5.00; B[2][1] = 1.00;
    B[3][0] = 2.00; B[3][1] = 1.50;

    // Вычисление матрицы C = A * B
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 4; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
// Выводим матрицу C
    cout << "Матрица C (A * B):" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    // 1) Находим продавца с максимальной и минимальной выручкой
    double maxRev = C[0][0];
    double minRev = C[0][0];
    int maxSeller, minSeller;

    for (int i = 1; i < 3; ++i) {
        if (C[i][0] > maxRev) {
            maxRev = C[i][0];
            maxSeller = i + 1; // добавляем 1, т.к индексы начинаются с 0
        }

        if (C[i][0] < minRev) {
            minRev = C[i][0];
            minSeller = i + 1;
        }
    }

    cout << "\n1) Продавец " << maxSeller << " выручил больше всего денег: " << maxRev << endl;
    cout << "   Продавец " << minSeller << " выручил меньше всего денег: " << minRev << endl;

    // 2) Находим продавца с максимальными и минимальными комиссионными
    double maxCommission = C[0][1];
    double minCommission = C[0][1];
    int maxCommissionSeller, minCommissionSeller;

    for (int i = 1; i < 3; ++i) {
        if (C[i][1] > maxCommission) {
            maxCommission = C[i][1];
            maxCommissionSeller = i + 1;
        }

        if (C[i][1] < minCommission) {
            minCommission = C[i][1];
            minCommissionSeller = i + 1;
        }
    }

    cout << "\n2) Продавец " << maxCommissionSeller << " получил наибольшие комиссионные: " << maxCommission << endl;
    cout << "   Продавец " << minCommissionSeller << " получил наименьшие комиссионные: " << minCommission << endl;

    // 3) Находим общую сумму денег, вырученных за проданные товары
    double totalRevenue = 0;
    for (int i = 0; i < 3; ++i) {
        totalRevenue += C[i][0];
    }
    cout << "\n3) Общая сумма денег: " << totalRevenue << endl;

    // 4) Находим общее количество комиссионных, полученных продавцами
    double totalCommission = 0;
    for (int i = 0; i < 3; ++i) {
        totalCommission += C[i][1];
    }
    cout << "4) Общее количество комиссионных: " << totalCommission << endl;

    // 5) Находим общую сумму денег, прошедших через руки продавцов
    double totalMoney = totalRevenue + totalCommission;
    cout << "5) Общая сумма денег, прошедших через руки продавцов: " << totalMoney << endl;


    delete[] A;
    delete[] B;
    delete[] C;


    return 0;
}
