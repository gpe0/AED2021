#include "product.h"

Product::Product(string i, float p, float w): id(i), price(p), weight(w) {}

string Product::getId() const {
    return id;
}

float Product::getPrice() const {
    return price;
}

float Product::getWeight() const {
    return weight;
}

bool Product::operator<(const Product &right) const {
    if (price<right.price) {
        return true;
    }
    else if (price == right.price) {
        return weight < right.weight;
    }
    else {
        return false;
    }
}