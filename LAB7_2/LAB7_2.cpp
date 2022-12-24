// LAB7_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <regex>
using namespace std;

bool valid_name(string name) {
    regex reg("^[A-Z]{1}[a-zA-Z]{1,31}$");
    return regex_search(name, reg);
}



int main() {

    setlocale(LC_ALL, "Russian");

    cout << "Введите имя" << endl;

    string x; 
    cin >> x;
    if (valid_name(x)) {
        cout << "Ваше имя верно" << endl;
    }
    else {
        cout << "Ваше имя не верно" << endl;
    }
    string email_1 = x + "@mail.ru";
    string email_2 = x + "@mail.com";
    smatch matches;
    regex reg("\\w*@\\w*[.]\\w{2,5}");

    while (regex_search(email_1, matches, reg)) {
        cout << matches[0] << endl;
        email_1 = matches.suffix().str();
    };
    while (regex_search(email_2, matches, reg)) {
        cout << matches[0] << endl;
        email_2 = matches.suffix().str();
    };
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
