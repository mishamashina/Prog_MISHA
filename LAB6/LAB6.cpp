// LAB6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

enum class UserError {
    NOT_CORRECT,
    OLD,
    BIG,
    NEGATIVE
};

class UserException : public std::exception {
private:
    UserError code;
public:
    UserException(UserError code) : code(code) {}

    const char* what() const throw () override{
        if (code == UserError::NOT_CORRECT) return "Некорректное значение";
        if (code == UserError::OLD) return "Что-то не верится...";
        if (code == UserError::BIG) return "Вы ещё не родились";
        if (code == UserError::NEGATIVE) return "Вы ввели отрицательное число!";
    }
};
int main() {

    int x;

    setlocale(LC_ALL, "Russian");
    try
    {
        cout << "Введите число 1, 2 или 3" << endl;
        cin >> x;
        if (x == 1 || x == 2 || x == 3)
        {
            if (x == 1)
            {
                cout << "Один" << endl;
            }
            if (x == 2)
            {
                cout << "Два" << endl;
            }
            if (x == 3)
            {
                cout << "Три" << endl;
            }

        }
        else
        {
            throw UserException(UserError::NOT_CORRECT);
        }
    }

    catch (const char* msg) {
        cout << msg << endl;
    }
    cout << endl;

    cout << "Введите год своего рождения" << endl;
    int y;
    try {
        cin >> y;
        if (y < 0 ) throw UserException(UserError::NEGATIVE);
        if (y < 1850 & y > 0) throw UserException(UserError::OLD);
        if (y > 2022) throw UserException(UserError::BIG);
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
    cout << "Спасибо";

}


/*
int main()
{
    setlocale(LC_ALL, "Russian");

    int x;
    try 
    {
        cout << "Введите число 1, 2 или 3" << endl;
        cin >> x;
        if (x == 1 || x == 2 || x == 3)
        {
            if (x == 1)
            {
                cout << "Один" << endl;
            }
            if (x == 2)
            {
                cout << "Два" << endl;
            }
            if (x == 3)
            {
                cout << "Три" << endl;
            }

        }
        else
        {
            throw "Неверно введенное число";
        }
    }
    catch (const char* msg) {

        cout << msg << "\n";
    }
    cout << endl;
    try
    {
        cout << "Введите свой год рождения" << endl;
        cin >> x;
        if (x < 1850 & x > 0) throw "Что-то не верится...";
        if (x > 2022) throw "Вы ещё не родились";
        if (x < 0) throw "Вы ввели отрицательное число!";
    }
    catch (const char* msg) {

        cout << msg << "\n";
    }
}
*/

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
