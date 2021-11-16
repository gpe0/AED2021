#include "funSortProblem.h"
#include <algorithm>

FunSortProblem::FunSortProblem() {}


//-----------------------------------------------------------------

// TODO
void FunSortProblem::expressLane(vector<Product> &products, unsigned k) {

    /*
    for (unsigned p = 1; p < products.size(); p++) {
        Product tmp = products[p];
        unsigned j;
        for (j = p; j > 0 && tmp < products[j-1]; j--)
            products[j] = products[j-1];
        products[j] = tmp;
    }
    */


    sort(products.begin(), products.end());

    while (products.size() > k) {
        products.pop_back();
    }

}

// TODO
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    if (values.size() < nc) {
        return -1;
    }
    vector<unsigned> valuesM = values;
    sort(valuesM.begin(), valuesM.end());

    int min = INT_MAX;

    for (int i = 0; i <= valuesM.size() - nc; i++) {
        vector<unsigned> temp(valuesM.begin() + i, valuesM.begin() + i + nc);
        int diff = temp[nc - 1] - temp[0];
        if (diff < min) {
            min = diff;
        }
    }


    return min;

}


// TODO
unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {
    vector<float> v(arrival.size() + departure.size());

    merge(arrival.begin(), arrival.end(), departure.begin(), departure.end(), v.begin());
    sort(v.begin(), v.end());
    int max = 0;
    int count = 0;

}


// TODO

void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {

}

