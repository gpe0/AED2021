#include "funSortProblem.h"
#include <algorithm>
#include <ctime>

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
    vector<float> arr = arrival;
    vector<float> dep = departure;


    int max = 1;
    int imax = 1;
    for (int i = 0; i < arr.size() - 1; i++) {

        if (arr[i + 1] < dep[i]) {
            imax++;
        } else {
            if (max < imax) {
                max = imax;
                imax = 0;
            }
        }
    }
    return max;



}

void quickSort(vector<Piece> &v, int left, int right) {

    if (right - left < 2) {
        sort(v.begin(), v.end(), [](const Piece & p1, const Piece & p2) -> bool {
            return p1.getDiameter() < p2.getDiameter();
        });
    } else {
        Piece x = v[v.size()/2];
        int i = left, j = right - 1;

        for (;;) {
            while (v[++i].getDiameter() < x.getDiameter());
            while (x.getDiameter() < v[--j].getDiameter()) ;
            if (i <j) {
                swap(v[i], v[j]);
            }
            else {
                break;
            }
        }
        swap(v[i], v[right - 1]);
        quickSort(v, left, i - 1);
        quickSort(v, i + 1, right);
    }

}

// TODO

void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {

    quickSort(nuts, 0, nuts.size());
    quickSort(bolts, 0, bolts.size());


}
