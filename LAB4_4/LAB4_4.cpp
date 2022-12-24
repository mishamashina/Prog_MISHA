// LAB4_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "gun.h"
#include <cassert>
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

string gun::get_name() { 
    return name; }
double gun::get_damage() { 
    return damage; }
double gun::get_weight() { 
    return weight; }
void gun::set_damage(double damage) { 
    this->damage = damage; }

Characteristic::Characteristic(double power) : power(power) {
}
double Characteristic::get_damage(gun* weapon) { 
    return weapon->damage + power; }

int MyMath::count = 0;

double MyMath::adding(double a, double b) { 
    MyMath::count++; return a + b; }
double MyMath::subtraction(double a, double b) { 
    MyMath::count++; return a - b; }
double MyMath::multiply(double a, double b) { 
    MyMath::count++; return a * b; }
double MyMath::division(double a, double b) { 
    MyMath::count++; return a / b; }


int main() {

    setlocale(LC_ALL, "Russian");

    gun* a = new gun("АК-103", 14, 15);
    assert(a->get_name() == "АК-103");
    assert(a->get_damage() == 14);
    assert(a->get_weight() == 15);
    a->set_damage(20);
    assert(a->get_damage() == 20);

    Characteristic b(10);
    assert(b.get_damage(a) == 30);

    assert(MyMath::adding(1, 2) == 3);
    assert(MyMath::subtraction(3, 4) == -1.0);
    assert(MyMath::multiply(4, 5) == 20);
    assert(MyMath::division(8, 2) == 4);
    assert(MyMath::count == 4);
    std::cout << "Результат MyMath::adding(1, 2): " << MyMath::adding(1, 2) << std::endl;
    std::cout << "Результат MyMath::subtraction(3, 4): " << MyMath::subtraction(3, 4) << std::endl;
    std::cout << "Результат MyMath::multiply(4, 5): " << MyMath::multiply(4, 5) << std::endl;
    std::cout << "Результат MyMath::division(8, 2): " << MyMath::division(8, 2) << std::endl;
    std::cout << "Значение вызовов функций MyMath: " << MyMath::count << std::endl;
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
