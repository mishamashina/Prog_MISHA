// LAB_5_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
bool gun::operator>(gun gun) { return this->get_damage() > gun.get_damage(); }
bool gun::operator<(gun gun) { return this->get_damage() < gun.get_damage(); }

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
double MagicWeapon::get_damage() {
    return damage + magic_damage;
}
void MagicWeapon::Attack() { cout << "Атакуем магическим оружием" << endl; }

DisposableGun::DisposableGun(string name, double damage, double weight, gunType gunType) : gun(name, damage, weight, gunType) {}
DisposableGun::DisposableGun() : gun() {}
bool DisposableGun::is_used() { return used; }
void DisposableGun::Attack() { cout << (used ? "Оружие уже было использовано" : "Атакуем одноразовым оружием") << endl; used = true; }

template <typename A, typename B>
inline GunArms<A, B>::GunArms(A* gun1, B* gun2) : gun1(gun1), gun2(gun2) {}

template <typename A, typename B>
A* GunArms<A, B>::get_gun1() { return gun1; }

template <typename A, typename B>
B* GunArms<A, B>::get_gun2() { return gun2; }

template <typename A, typename B>
void GunArms<A, B>::set_gun1(A* gun1) { this->gun1 = gun1; }

template <typename A, typename B>
void GunArms<A, B>::set_gun2(B* gun2) { this->gun2 = gun2; }


int main() {

    setlocale(LC_ALL, "Russian");

    DisposableGun dg;

    dg.Attack();
    dg.Attack();

    gun gun_1("gun_1", 14, 521, gunType::ONEHANDED);
    gun gun_2("gun_2", 152, 1, gunType::ONEHANDED);

    GunArms<gun, gun> wa(&gun_1, &gun_2);

    cout << "Урон первого оружия: " << wa.get_gun1()->get_damage() << endl;
    cout << "Урон второго оружия: " << wa.get_gun2()->get_damage() << endl;

    int a = 10, b = 15;
    GunArms<int, int> wa2(&a, &b);

    cout << "Значение первого оружия Int: " << *wa2.get_gun1() << endl;
    cout << "Значение второго оружия Int: " << *wa2.get_gun2() << endl;
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
