//
//autor: Maja Lewandowska
//Podczas tworzenia funkcji wspolne wykorzystano model Gemini 4 Hydrogen.
//

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <set>
#include <stdexcept>
using namespace std;

multiset<int> wspolne(multiset<int> x, multiset<int> y) {
    // funkcja zwracajaca czesc wspolna

    multiset<int> result;

    set_intersection(
        // funcja z biblioteki algorithm
        x.begin(), x.end(),
        y.begin(), y.end(),
        inserter(result, result.begin()) //wskazuje gdzie i od jakiego miejsca wstawiac
    );

    return result;
}

// TESTY

void test_1() {
    // prawidlowe dane

    multiset<int> x = {1, 2, 3, 4, 4};
    multiset<int> y = {2, 3, 4, 5};

    assert(wspolne(x, y) == multiset<int>({2, 3, 4}));
}

void test_2() {
    // brak elementow wspolnych

    multiset<int> x = {1, 2, 3};
    multiset<int> y = {8, 9 , 10};

    assert(wspolne(x, y).empty());
}

void test_3() {
    // puste multizbiory

    multiset<int> x;
    multiset<int> y;

    assert(wspolne(x, y).empty());
}

// MAIN

int main() {

    test_1();
    test_2();
    test_3();

    multiset<int> x = {1, 2, 3, 4, 4, 4, 5, 28, 11, 11, 33};
    multiset<int> y = {2, 3, 5, 5, 6, 6, 6, 28, 13, 13, 34};

    try {
        multiset<int> result = wspolne(x, y);

        cout << "Czesc wspolna: ";

        for (int element : result) {
            cout << element << " ";
        }

    }
    catch(const invalid_argument& e) {
        cout << e.what();
    }
    return 0;
}