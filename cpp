
#include <iostream>
#include <ctime>
#include <windows.h> 

#define n 5
#define m 5

using namespace std;

void CreateArrayMemory(int**& a, const int N, const int M) {

    a = new int* [N];
    for (int i = 0; i < N; i++)
        a[i] = new int[M];
}

void UserInputElements(int**& a, const int N, const int M) {
    cout << "Введите данные массива:\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> a[i][j];
}

void RandInputElements(int**& a, const int N, const int M) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            a[i][j] = rand() % 20;;
}

void ArrayPrototypeSort(int**& array, const int i, const int o) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int o = 0; o < m; o++)
            {
                if (array[i][o] < array[i][o + 1])
                {
                    int tmp = array[i][o];
                    array[i][o] = array[i][o + 1];
                    array[i][o + 1] = tmp;
                }

            }
        }
    }
}

void TerminalOutput(int**& a, const int N, const int M) {
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << a[i][j] << "\t";
        cout << "\n";
    }
}

void DeleteMemoryArray(int**& a, const int N) {
    for (int i = 0; i < N; i++)
        delete[] a[i];
    delete[] a;
}
void Menu() {
        cout << "\nМеню операций:\n\n1.Динамическое выделение памяти для двумерного массива\n2.Ввод элементов массива с клавиатуры\n3.Заполнение массива случайными числами\n4.Сортировка элементов массива (по вариантам)\n5.Вывод элементов массива на экран\n6.Освобождение памяти, выделенной для массива\n\n0.Выход из программы\n" << endl;
    }

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    
    bool point = false; int choice = 0; int** a = 0;

    Menu();

        do {
        cout << "\nВведите желаемый пункт от 1 до 6 либо 0 для выхода:" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            CreateArrayMemory(a, n, m);
            break;
        case 2:
            UserInputElements(a, n, m);
            break;
        case 3:
            RandInputElements(a, n, m);
            break;
        case 4:
            ArrayPrototypeSort(a, n, m);
            break;
        case 5:
            TerminalOutput(a, n, m);
            break;
        case 6:
            DeleteMemoryArray(a, n);
            break;
        case 0:
            point = true;
            break;
        default:
            cout << "Ошибка! Пожалуйста, введите действительные значения от 1 до 6 либо 0 для выхода!" << endl;
            break;
        }
    }
        while (!point);
    return 0;
}
