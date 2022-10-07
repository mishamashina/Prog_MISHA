// LAB_3_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int sumMas(int* begin, int* end);

int sum(int a, int b);
int raz(int a, int b);
int f(char j);

int* test()
{
    return new int(15);
}

int main()
{
    int mas[] = { 1, 2, 3, 4, 5, 6 };

    cout << sumMas(begin(mas), end(mas)) << endl;

    cout << sum(6, 1) << " " << raz(6, 1) << endl;

    int(*operation)(int, int);
    operation = raz;

    cout << f('+') << endl;

    int* r = test();
    cout << r << " " <<  * r << endl;
    delete r;
    
}

int sumMas(int* begin, int* end)
{
    int sum = 0;
    for (int* i = begin; i < end; i++)
    {
        sum += *i;
    }
    return (sum);
}

int sum(int a, int b)
{
    return(a + b);
}

int raz(int a, int b)
{
    return(a - b);
}

int f(char j)
{
    int(*operation)(int, int);
    if (j == '-')
    {
        operation = raz;
        return(operation(12, 10));
    }
    else
    {
        operation = sum;
        return(operation(12, 10));
    }
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
