// LAB_2_1_Zadanie_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int x;
	while (true)
	{
		cout << "Введите целое положительное число" << endl;
		cin >> x;
		if (x > 0)
		{
			break;
		}
	}
	for (int first = 1; first <= x; first++)
	{
		if (first == 1)
		{
			cout << first;
		}
		else
		{
			cout << "+" << first;
		}
	}
	cout << endl;
	int arr[10] = { 1, 3, 5, 10, 42, 2, 4, 19, 18, 100 };
	int length = sizeof(arr) / sizeof(arr[0]);
	cout << "Все элементы массива";
	cout << endl;
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Четные элементы массива";
	cout << endl;
	for (int i = 0; i < length; i++)
	{
		int numb = 2;
		if (i % numb == 0)
		{
			cout << arr[i] << " ";
		}
	}
	cout << endl;
	cout << "Нечетные элементы массива";
	cout << endl;
	for (int i = 0; i < length; i++)
	{
		int numb = 2;
		if (i % numb != 0)
		{
			cout << arr[i] << " ";
		}
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
