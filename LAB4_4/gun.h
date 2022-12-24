#pragma once
using namespace std;
class gun
{
private:
    string name;
    double damage;
    double weight;

    friend class Characteristic;

public:
    gun(string name, double damage, double weight);
    gun();
    ~gun();

    string get_name();
    double get_damage();
    double get_weight();

    void set_damage(double damage);

    bool max_weight(double max_weight);
    double sum_weight(gun* weapon);
    double sum_weight(double weight);
};


class Characteristic {
private:
    double power;

public:
    Characteristic(double power);

    double get_damage(gun* weapon);
};

class MyMath {
public:
    static int count;

    static double adding(double a, double b);
    static double subtraction(double a, double b);
    static double multiply(double a, double b);
    static double division(double a, double b);
};