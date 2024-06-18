#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

class Product {
public:
    Product(int id, const string& name, double cost);
    int getId() const;
    string getName() const;
    double getCost() const;

private:
    int id;
    string name;
    double cost;
};

#endif 
