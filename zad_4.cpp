//
//autor: Maja Lewandowska
//Podczas tworzenia funkcji fib_iteration i fib_recursion wykorzystano model Gemini 4 Hydrogen.
//

#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>
using namespace std;

vector<unsigned long long> fib_iteration(int n) {
    // funkcja zwracajaca ciag Fibonacciego

    if (n < 0) {
        throw invalid_argument("Liczba nie moze być ujemna!");
    }

    vector<unsigned long long> result;

    // pierwsze dwa stale elementy
    unsigned long long a = 0;
    unsigned long long b = 1;

    for (int i = 0; i < n; i++) {
        result.push_back(a);

        unsigned long long c = a + b;

        //przesuwanie wartosci
        a = b;
        b = c;
    }

    return result;
}

vector<unsigned long long> fib_recursion(int n) {
    // funkcja zwracajaca ciag Fibonacciego

    if (n < 0) {
        throw invalid_argument("Liczba nie moze byc ujemna!");
    }

    // stale elementy
    if (n == 0) return {};
    if (n == 1) return {0};
    if (n == 2) return {0, 1};

    vector<unsigned long long> result = fib_recursion(n - 1); // n zmniejsza się dopoki nie bedzie 2

    // wyznaczanie indeksu dla ostatniego i przedostatniego elementu
    // np. dla {0, 1} a = 1 i b = 0
    unsigned long long a = result[result.size() - 1];
    unsigned long long b = result[result.size() - 2];

    result.push_back(a + b);

    return result;
}

// TESTY

void test_1() {
    // poprawne dane - iteracja

    vector<unsigned long long> result = fib_iteration(7);

    assert(result.size() == 7);
    assert(result[0] == 0);
    assert(result[1] == 1);
    assert(result[2] == 1);
    assert(result[3] == 2);
    assert(result[4] == 3);
    assert(result[5] == 5);
    assert(result[6] == 8);
}

void test_2() {
    // poprawne dane - rekurencja

    vector<unsigned long long> result = fib_recursion(7);

    assert(result.size() == 7);
    assert(result[0] == 0);
    assert(result[1] == 1);
    assert(result[2] == 1);
    assert(result[3] == 2);
    assert(result[4] == 3);
    assert(result[5] == 5);
    assert(result[6] == 8);
}

void test_3() {
    // brak danych

    assert(fib_iteration(0).empty());
    assert(fib_recursion(0).empty());
}

// MAIN

int main() {

    test_1();
    test_2();
    test_3();

    int n = 7;

    try {
        vector<unsigned long long> result_1 = fib_iteration(n);
        vector<unsigned long long> result_2 = fib_recursion(n);

        cout << "Wynik iteracyjny: ";

        for (unsigned long long x : result_1) {
            cout << x << " ";
        }

        cout << endl;

        cout << "Wynik rekurencyjny: ";

        for (unsigned long long x : result_2) {
            cout << x << " ";
        }

        cout << endl;
    }
    catch(const invalid_argument& e) {
        cout << e.what();
    }
    return 0;
}
