#include <iostream>
#include <vector>

using namespace std;

template <class T>
class MyVector {
    vector<T> values;
public:
    MyVector();
    ~MyVector();
    void push_back(T v1);
    vector<T> getValues() const;
    T max() const;
    bool hasDuplicates() const;
    void removeDuplicates() ;
};


// exception EmptyVector
class EmptyVector
{ };

// methods
template <class T>
MyVector<T>::MyVector() {}

template <class T>
MyVector<T>::~MyVector() {}

template <class T>
void MyVector<T>::push_back(T v1) {
    values.push_back(v1);
}

template <class T>
vector<T> MyVector<T>::getValues() const {
    return values;
}

//---------------------------------

// TODO
template <class T>
T MyVector<T>::max() const { // complexidade temporal : O(n)
                             // complexidade espacial : S(1)
    T vmax;
    if (values.size() == 0) {
        throw EmptyVector();
    }
    for (int i = 0; i < values.size(); i++) {
        if (values[i] > vmax) {
            vmax = values[i];
        }
    }
	return vmax;
}

// TODO
template<class T>
bool MyVector<T>::hasDuplicates() const {   // complexidade temporal : O(n^2)
                                            // complexidade espacial : S(1)
	for (int i = 0; i < values.size(); i++) {
        for (int j = 0; j < values.size(); j++) {
            if (i != j) {
                if (values[i] == values[j]) {
                    return true;
                }
            }
        }
    }
    return false;
}

// TODO
template<class T>

void MyVector<T>::removeDuplicates() {    // complexidade temporal : O(n^2)
                                          // complexidade espacial : S(1)
    for (int i = 0; i < values.size(); i++) {
        for (int j = 0; j < values.size(); j++) {
            if (i != j) {
                if (values[i] == values[j]) {
                    values.erase(values.begin() + j);
                    j--;
                }
            }
        }
    }

}

