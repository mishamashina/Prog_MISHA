﻿// Лабораторная работа 2.1 23.09.2022.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int fun(int a = 1);

int fun4(int a, int b, float& n1, float& n2);

int main()
{
    setlocale(LC_ALL, "");

    int mas[2][3] = { {1,2,3}, {4,5,6} };
    int sum = 0;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            sum += mas[i][j];
        }
    }
    cout << "sum = " << sum << endl;

    int arr[] = { 1, 2, 3 };

    arr[0] = mas[0][0] + mas[1][0];
    arr[1] = mas[0][1] + mas[1][1];
    arr[2] = mas[0][2] + mas[1][2];

    for (int i = 0; i < 3; i++)
    {
        int ind = 0;
        arr[i] = mas[ind][i] + mas[ind + 1][i];
        cout << arr[i] << endl;
    }

    float a = 20.84;
    float b = 100;
    float& n1 = a;
    float& n2 = b;

    n1 = 50;
    cout << a << " " << n1 << " " << n2  << endl;

    cout << fun(5) << endl;
    cout << fun() << endl;

    cout << a << " " << b << endl;
    cout << fun4(5, 6, n1, n2) << endl;
    cout << n1 << " " << n2 << " " << a << " " << b << endl;

    int d = 12;
    cout << d << endl;
    cout << "--------------------------" << endl;
        
    for (int i = 1; i <= 3; i++)
    {
        int g = 19;
        cout << d << endl;
        cout << g << endl;
    }

    cout << g << endl;
}
int fun(int a)
{
    if (a == 0 || a < 0)
    {
        return (0);
    }
    else
    {
        int sum = 0;
        for (int i = 1; i <= a; i++)
        {
            sum += i;
        }
        return (sum);
    }
}

int fun4(int a, int b, float& n1, float& n2)
{
    n1 = a + b;
    n2 = a * b;
    return n1, n2;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
