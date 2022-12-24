// LAB5_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "gun.h"
#include <cassert>
#include <iostream>
using namespace std;

gun::gun(std::string name, double damage, double weight, gunType weapon_type) : name(name), damage(damage), weight(weight), gun_type(gun_type) {}
gun::gun() : name("default"), damage(0), weight(0), gun_type(gunType::ONEHANDED) {}
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
    return name;
}
double gun::get_damage() {
    return damage;
}
double gun::get_weight() {
    return weight;
}
void gun::set_damage(double damage) {
    this->damage = damage;
}

gunType gun::get_gun_type() { return gun_type; }

Player::Player(int id, string login, string password) : id(id), login(login), password(password) {}
void Player::print_info() {
    cout << "id: " << id << endl;
    cout << "login: " << login << endl;
    cout << "password: " << password << endl;
}

MagicWeapon::MagicWeapon(string name, double damage, double weight, gunType gunType, double magic_damage) : gun(name, damage, weight, gunType), magic_damage(magic_damage) {}
MagicWeapon::MagicWeapon() : gun(), magic_damage(0) {}
double MagicWeapon::get_magic_damage() { 
    return magic_damage; 
}

int main() {

    setlocale(LC_ALL, "Russian");

    gun w("name", 10, 5, gunType::ONEHANDED);

    if (w.get_gun_type() == gunType::ONEHANDED) {
        cout << "Одноручное оружие" << endl;
    }
    if (w.get_gun_type() == gunType::TWOHANDED) {
        cout << "Двуручное оружие" << endl;
    }
    if (w.get_gun_type() == gunType::BOW) {
        cout << "Лук" << endl;
    }
    if (w.get_gun_type() == gunType::CROSSBOW) {
        cout << "Арбалет" << endl;
    }

    Player p(1, "login", "password");
    p.print_info();
    assert(p.id == 1);
    assert(p.login == "login");
    assert(p.password == "password");

    MagicWeapon primer_1("name", 10, 5, gunType::ONEHANDED, 10), primer_2;

    assert(primer_1.get_magic_damage() == 10);
    assert(primer_1.get_damage() == 10);
    assert(primer_1.get_weight() == 5);
    assert(primer_1.get_name() == "name");

    assert(primer_2.get_magic_damage() == 0);
    assert(primer_2.get_damage() == 0);
    assert(primer_2.get_weight() == 0);
    assert(primer_2.get_name() == "default");
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
