#include "product.h"

using namespace std;

Product::Product(int id, const string& name, double cost)
    : id(id), name(name), cost(cost) {}

int Product::getId() const {
    return id;
}

string Product::getName() const {
    return name;
}

double Product::getCost() const {
    return cost;
}
