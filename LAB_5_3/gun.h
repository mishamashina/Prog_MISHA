#pragma once
#include <iostream>
#include <string>
using namespace std;

enum gunType {
    ONEHANDED,
    TWOHANDED,
    BOW,
    CROSSBOW
};

class gun {
public:
    string name;
    double damage;
    double weight;
    gunType gun_type;

    friend class Characteristic;

public:
    gun(string name, double damage, double weight, gunType weaponType);
    gun();
    ~gun();

    string get_name();
    double get_damage();
    double get_weight();
    gunType get_gun_type();

    void set_damage(double damage);

    bool max_weight(double max_weight);
    double sum_weight(gun* weapon);
    double sum_weight(double weight);
    bool operator>(gun gun);
    bool operator<(gun gun);
};


class Characteristic {
private:
    double power;

public:
    Characteristic(double power);

    double get_damage(gun* gun);
};

class MyMath {
public:
    static int count;

    static double adding(double a, double b);
    static double subtraction(double a, double b);
    static double multiply(double a, double b);
    static double division(double a, double b);
};

class MagicWeapon : public gun {
private:
    double magic_damage;
public:
    MagicWeapon(string name, double damage, double weight, gunType gunType, double magic_damage);
    MagicWeapon();

    double get_magic_damage();
    double get_damage();

    void Attack();
};

class DisposableGun : public gun {
protected:
    bool used = false;
public:
    DisposableGun(string name, double damage, double weight, gunType gunType);
    DisposableGun();

    bool is_used();
    void Attack();
};

template<typename A, typename B>
class GunArms {
protected:
    A* gun1;
    B* gun2;
public:
    GunArms(A* gun1, B* gun2);

    A* get_gun1();
    B* get_gun2();

    void set_gun1(A* gun1);
    void set_gun2(B* gun2);
};

struct Player {
    int id;
    string login;
    string password;

    Player(int id, string login, string password);
    void print_info();
};