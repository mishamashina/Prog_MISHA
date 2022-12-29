#pragma once
#include "node.h"

struct Tree {
    virtual void add(int k) = 0;
    virtual void del(int k) = 0;
};