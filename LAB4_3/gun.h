#pragma once
#include <string>
class gun
{
public:
    std::string name;
    double damage;
    double weight;

    gun(std::string name, double damage, double weight);
    gun();
    ~gun();

    bool max_weight(double max_weight);
    double sum_weight(gun* gun);
    double sum_weight(double weight);
};

