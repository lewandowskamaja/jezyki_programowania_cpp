//
//autor: Maja Lewandowska
//Podczas tworzenia funkcji podzbiory wykorzystano model Gemini 4 Hydrogen.
//

#include <iostream>
#include <vector>
#include <cassert>
#include <set>
#include <stdexcept>
using namespace std;

vector<set<char>> podzbiory(set<char> x) {
    // funkcja wyznaczajca pozbiory

    vector<set<char>> result;

    // zamieniamy na wektor, zeby odwolywac sie przez indeksy
    vector<char> elements(x.begin(), x.end());
    int n = elements.size();

    // petla dla liczby podzbiorow (bitowo obliczamy 2^n)
    // 1 << przesuniecie bitowe o n
    for (int i = 0; i < (1 << n); i++) {
        set<char> subset;

        // petla dla liczby elementow
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                //operacja bitowa AND - dodajemy ten element gdzie wychodzi 1
                // np. dla i=0 i j=0 bedzie 000 & 001
                subset.insert(elements[j]);
            }
        }
        result.push_back(subset);
    }
    return result;

}

// TESTY

void test_1() {
    // prawidlowe dane

    set<char> x = {'a', 'c', 'e', 'g'};

    vector<set<char>> result = podzbiory(x);

    assert(result.size() == 16);
}

void test_2() {
    // prawidlowe dane

    set<char> x = {'a', 'c'};

    vector<set<char>> result = podzbiory(x);
    vector<set<char>> expected_result = {{}, {'a'}, {'c'},{'a', 'c'}};

    assert(result == expected_result);
}

void test_3() {
    // pusty zbior

    set<char> x;

    vector<set<char>> result = podzbiory(x);

    assert(result.size() == 1 && result[0].empty());
}

// MAIN

int main() {

    test_1();
    test_2();
    test_3();

    set<char> x = {'k', 'l', 'm', 'n'};

    try {
        vector<set<char>> result = podzbiory(x);

        cout << "Podzbiory: " << endl;
        for (set<char> subset : result) {
            cout << "{";

            bool first = true;

            for (char element : subset) {

                if (!first) {
                    cout << ", ";
                }
                cout << element << "";
                first = false;
            }

            cout << "}" << endl;
        }
    }
    catch(const invalid_argument& e) {
        cout << e.what();
    }
    return 0;
}
