﻿// LAB4_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "gun.h"
#include <cassert>
#include <iostream>
using namespace std;

gun::gun(string name, double damage, double weight) : name(name), damage(damage), weight(weight) {}
gun::gun() : name("name"), damage(0), weight(0) {}
gun::~gun() { 
    cout << "Удаление объекта" << endl; 
}

bool gun::max_weight(double max_weight) {
    return max_weight < weight; 
    }
double gun::sum_weight(gun* gun) {
    return sum_weight(gun->weight);
    }
    double gun::sum_weight(double weight) {
    return weight + weight;
    }

int main() {

    setlocale(LC_ALL, "Russian");

    gun* a = new gun("АН-98", 13, 18);
    cout << "Данные объекта a: \n";
    cout << a->name << endl;
    cout << a->damage << endl;
    cout << a->weight << endl;
    delete(a);

    gun b("АК-103", 10, 30), c("СВУ", 10, 30);
    assert(b.sum_weight(&c) == 60);
    assert(b.sum_weight(c.weight) == 60);
    assert(b.max_weight(4) == true);
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

