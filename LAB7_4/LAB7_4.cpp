// LAB7_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

class Settings {
public:

    static map<int, int> x;
    static void Print();
    static int Get(int key);
    static void Add(int key, int val);
};

map<int, int> Settings::x;

void Settings::Add(int key, int val) { 
    Settings::x[key] = val; 
}

int Settings::Get(int key) { 
    return Settings::x[key]; 
}

void Settings::Print() { 
    for (auto& u : Settings::x) 
        cout << u.first << " : " << u.second << " "; cout << endl; 
}

void print_vector(vector<float>& v) {
    for (auto& u : v) {
        cout << u << " ";
    }
    cout << endl;
}

int main() {
    vector<float> v;
    for (int i = 0; i < 5; i++) {
        v.push_back(i * 1.2);
    }

    print_vector(v);
    v.resize(6);

    for (int i = 5; i >= 4; i--) {
        v[i] = v[i - 1];
    }

    v[3] = 7;

    print_vector(v);
    v.resize(5);

    print_vector(v);

    Settings::Add(1, 2);
    Settings::Add(3, 1);
    assert(Settings::Get(1) == 2);
    assert(Settings::Get(3) == 1);
    Settings::Add(1, 5);
    assert(Settings::Get(1) == 5);

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
