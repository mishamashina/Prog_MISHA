// LAB7_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    
    cout << "Введите радуис окружности" << endl;
    int r; 
    cin >> r;
    double res = 2 * 3.14 * r;

    cout << fixed << setprecision(3) << res << endl;


    ifstream myfile; myfile.open("a.txt");
    string mystring;

    if (myfile.is_open()) {
        char mychar;

        while (myfile) {
            mychar = myfile.get();
            cout << mychar;
        }
    }

    while (true) {

        cout << "Введите слова или команду read, erase или exit" << endl;
        string s; cin >> s;

        if (s == "read") {
            ifstream myfile; myfile.open("a.txt");
            string mystring;

            if (myfile.is_open()) {
                char mychar;

                while (myfile) {
                    mychar = myfile.get();
                    cout << mychar;
                }
            }
        }
        else if (s == "erase") {
            ofstream ofs("a.txt", ios::out | ios::trunc);
            ofs.close();
        }
        else if (s == "exit") {
            break;
        }
        else {
            ofstream ofs("a.txt", ios::out | ios::app);
            ofs << s << endl;
            ofs.close();
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
