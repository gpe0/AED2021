#include "funSearchProblem.h"

FunSearchProblem::FunSearchProblem() {}

//-----------------------------------------------------------------

// TODO
int FunSearchProblem::facingSun(const vector<int> & values) {
    int num = 0;
    int max = -1;
    for (int i = 0; i < values.size(); i++) {
        if (values[i] > max) {
            max = values[i];
            num++;
        }
    }
    return num;
}

// TODO
int FunSearchProblem::squareR(int num) {
    vector<int> v;
    for (int i = 0; i <= num; i++) {
        v.push_back(i);
    }

    int left = 0, right = v.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (v[mid] * v[mid] < num) {
            left = mid + 1;
        } else if (num < v[mid] * v[mid]) {
            right = mid - 1;
        } else {
            return v[mid];
        }

    }
    return v[right];

}

// TODO
int FunSearchProblem::smallestMissingValue(const vector<int> & values) {
    int min = INT_MAX;
    int max = 0;
    for (int i = 0; i < values.size(); i++) {
        if (values[i] > 0) {
            if (values[i] > max) {
                max = values[i];
            }

            if (values[i] < min) {
                min = values[i];
            }

        }
    }

    for (int i = 0; i < max + 1; i++) {
        for (int j = 0; j < values.size(); j++) {

        }
    }
    return min;
}

// TODO
int FunSearchProblem::minPages(const vector<int> & values, int numSt) {
    return 0;
}

